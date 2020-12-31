#include "logic.h"
#include <stdlib.h>
#include <limits.h>

int get_index_from_coordinates(int c, int r) {
    return (r * 4 - r / 2) + c / 2;
}

int get_index_from_pos(Pos pos) {
    return get_index_from_coordinates(pos.c, pos.r);
}

void initialize_board(Piece *board) {
    int r, c;
    Color firstColor;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLUMNS; c++) {
            if (is_pos_valid(initialize_pos(c, r))) {
                firstColor = r <= 2 ? WHITE : (r >= 4 ? BLACK : UNDEFINED);
                board[get_index_from_coordinates(c, r)] = initialize_piece(firstColor, UNDEFINED, UNDEFINED,
                                                                           false, firstColor == UNDEFINED ? 0 : 1);
            }
        }
    }
}

GameState compute_state(Piece *board, Color colorToMove) {
    cvector_vector_type(Move) moves = get_possible_moves_by_color(board, colorToMove);
    cvector_vector_type(Pos) whitePiecesPos;
    cvector_vector_type(Pos) blackPiecesPos;
    GameState state = PLAYING;
    /* Se il giocatore che deve muovere non ha nessuna mossa a disposizione ha perso */
    bool noValidMove = cvector_empty(moves);
    cvector_free(moves);
    if (noValidMove) {
        if (colorToMove == WHITE) state = BLACK_WIN;
        else state = WHITE_WIN;
        return state;
    }
    /* Se un giocatore finisce i pezzi ha perso */
    whitePiecesPos = get_pieces_pos_by_color(board, WHITE);
    if (cvector_empty(whitePiecesPos))
        state = BLACK_WIN;
    cvector_free(whitePiecesPos);
    blackPiecesPos = get_pieces_pos_by_color(board, BLACK);
    if (cvector_empty(blackPiecesPos))
        state = WHITE_WIN;
    cvector_free(blackPiecesPos);
    return state;
}

/* For internal use only */
int compute_score(Piece *board, Color colorToMove) {
    GameState state = compute_state(board, colorToMove);
    if (state == WHITE_WIN) return 100 * (colorToMove == WHITE ? 1 : -1);
    if (state == BLACK_WIN) return 100 * (colorToMove == BLACK ? 1 : -1);
    return (count_pieces(board, WHITE) - count_pieces(board, BLACK)) * (colorToMove == WHITE ? 1 : -1);
}

/* For internal use only */
int minimax(Piece *board, Color colorToMove, int depth, bool maximize) {
    int i, score;
    cvector_vector_type(Move) moves;

    if (depth == 0) return compute_score(board, colorToMove);

    moves = get_possible_moves_by_color(board, colorToMove);
    if(cvector_empty(moves))
        return compute_score(board, colorToMove);

    if (maximize) score = INT_MIN;
    else score = INT_MAX;

    for (i = 0; i < cvector_size(moves); i++) {
        Piece *tempBoard = clone_board(board);
        apply_move(tempBoard, colorToMove, moves[i]);
        if (maximize) {
            score = max(score, minimax(tempBoard, get_opposite_color(colorToMove), depth - 1, false));
        } else {
            score = min(score, minimax(tempBoard, get_opposite_color(colorToMove), depth - 1, true));
        }
        free(tempBoard);
    }
    cvector_free(moves);

    return score;
}

Move best_move_minimax(Piece *board, Color colorToMove, int depth) {
    int bestScore = INT_MIN;
    Move bestMove;
    cvector_vector_type(Move) moves = get_possible_moves_by_color(board, colorToMove);
    int i, score;
    if(cvector_size(moves) == 1) {
        bestMove = moves[0];
    } else {
        for (i = 0; i < cvector_size(moves); i++) {
            Piece *tempBoard = clone_board(board);
            apply_move(tempBoard, colorToMove, moves[i]);
            score = minimax(tempBoard, get_opposite_color(colorToMove), depth - 1, false);
            if (score > bestScore) {
                bestScore = score;
                bestMove = moves[i];
            }
            free(tempBoard);
        }
    }
    cvector_free(moves);

    return bestMove;
}

bool apply_move(Piece *board, Color colorToMove, Move move) {
    /* Controlla se la mossa è valida, se è in quelle possibili per quel colore
       Sposta i pezzi e li modifica nel caso qualcuno abbia mangiato */
    cvector_vector_type(Move) colorMoves = get_possible_moves_by_color(board, colorToMove);
    Piece piece, eatenPiece;
    int i, pieceIndex;
    bool validMove = false;

    for (i = 0; i < cvector_size(colorMoves); i++) {
        if (is_move_equal(move, colorMoves[i])) {
            validMove = true;
            break;
        }
    }
    cvector_free(colorMoves);
    if (!validMove) return false;

    pieceIndex = get_index_from_pos(move.from);
    piece = board[pieceIndex];

    /* Se mangia una pedina avversaria */
    if (does_move_eat(board, move)) {
        int eatenIndex = get_index_from_coordinates((move.from.c + move.to.c) / 2, (move.from.r + move.to.r) / 2);
        eatenPiece = board[eatenIndex];

        /* Aggiorno l'altezza */
        piece.height += 1;

        if (piece.height > MAX_HEIGHT) {
            piece.height = MAX_HEIGHT;
        }

        if (piece.color[MAX_HEIGHT - 1] == UNDEFINED) {
            /* Aggiorno i colori */
            piece.color[piece.height - 1] = eatenPiece.color[0];
        }

        /* Modifico il pezzo nella board */
        eatenPiece.height -= 1;
        if (eatenPiece.height == 0) {
            board[eatenIndex] = initialize_null_piece();
        } else {
            for (i = 0; i < eatenPiece.height; i++) {
                eatenPiece.color[i] = eatenPiece.color[i + 1];
            }
            eatenPiece.color[eatenPiece.height] = UNDEFINED;
            board[eatenIndex] = eatenPiece;
        }
        board[get_index_from_pos(move.to)] = piece;
    } else {
        board[get_index_from_pos(move.to)] = board[get_index_from_pos(move.from)];
    }

    board[get_index_from_pos(move.from)] = initialize_null_piece();

    /* Promuove il pezzo se opportuno */
    if (piece.color[0] == WHITE && move.to.r == ROWS - 1) {
        piece.promoted = true;
    } else if (piece.color[0] == BLACK && move.to.r == 0) {
        piece.promoted = true;
    }

    board[get_index_from_pos(move.to)] = piece;

    return true;
}

bool is_move_valid(Piece *board, Move move) {
    bool res = is_pos_valid(move.from) && is_pos_valid(move.to);
    int dx = abs(move.from.c - move.to.c);
    int dy = abs(move.from.r - move.to.r);
    int maxDiff = does_move_eat(board, move) ? 2 : 1;
    res = res && dx <= maxDiff && dy <= maxDiff;
    /* Controlla se la nuova cella è vuota */
    res = res && is_piece_null(board[get_index_from_pos(move.to)]);
    return res;
}

bool is_pos_valid(Pos pos) {
    return pos.c >= 0 && pos.c < 7 && pos.r >= 0 && pos.r < 7 && (pos.c % 2 == pos.r % 2 || (pos.c + pos.r) % 2 == 0);
}

bool does_move_eat(Piece *board, Move move) {
    Piece movedPiece =
            board[get_index_from_coordinates(move.from.c, move.from.r)];

    Piece middlePiece = board[get_index_from_coordinates(
            (move.from.c + move.to.c) / 2, (move.from.r + move.to.r) / 2)];

    int dx = abs(move.from.c - move.to.c);
    int dy = abs(move.from.r - move.to.r);

    int movedPieceOwnColors = 1;
    int middlePieceOwnColors = 1;

    int i;

    if (dx != 2 || dy != 2 || movedPiece.color[0] == UNDEFINED || middlePiece.color[0] == UNDEFINED ||
        !is_opposite_color(movedPiece.color[0], middlePiece.color[0])) {
        return false;
    }

    for (i = 1; i < 3; i++) {
        if (movedPiece.color[0] == movedPiece.color[i]) {
            movedPieceOwnColors++;
        }
    }

    for (i = 1; i < 3; i++) {
        if (middlePiece.color[0] == middlePiece.color[i]) {
            middlePieceOwnColors++;
        }
    }

    return movedPieceOwnColors >= middlePieceOwnColors;
}

cvector_vector_type(Move) get_possible_moves_by_color(Piece *board, Color color) {
    cvector_vector_type(Move) allMoves = NULL;
    cvector_vector_type(Move) eatMoves = NULL;
    cvector_vector_type(Pos) piecesPos = NULL;
    int i;
    piecesPos = get_pieces_pos_by_color(board, color);
    for (i = 0; i < cvector_size(piecesPos); i++) {
        cvector_vector_type(Move) pieceMoves = get_possible_moves_by_piece(board, piecesPos[i]);
        cvector_copy(pieceMoves, allMoves);
        cvector_free(pieceMoves);
    }
    cvector_free(piecesPos);
    /* Controlla se il colore che deve muovere è obbligato a mangiare */
    for (i = 0; i < cvector_size(allMoves); i++) {
        if (does_move_eat(board, allMoves[i])) {
            cvector_push_back(eatMoves, allMoves[i]);
        }
    }

    if (cvector_empty(eatMoves)) return allMoves;
    cvector_free(allMoves);

    return eatMoves;
}

cvector_vector_type(Move) get_possible_moves_by_piece(Piece *board, Pos piecePos) {
    int i;
    Move move;
    cvector_vector_type(Move) moves = NULL;
    Piece piece = board[get_index_from_pos(piecePos)];
    /* Controlla le celle in "alto" */
    if (piece.color[0] == WHITE || piece.promoted) {
        for (i = -1; i <= 1; i += 2) {
            Pos newPos = initialize_pos(piecePos.c + i, piecePos.r + 1);
            if (is_pos_valid(newPos)) {
                /* Se nella nuova cella c'è un avversario, controlla se lo può mangiare */
                if (is_opposite_color(board[get_index_from_pos(piecePos)].color[0],
                                      board[get_index_from_pos(newPos)].color[0])) {
                    newPos = initialize_pos(piecePos.c + (i * 2), piecePos.r + 2);
                }
                move = initialize_move(piecePos, newPos);
                if (is_move_valid(board, move)) {
                    cvector_push_back(moves, move);
                }
            }
        }
    }
    /* Controlla le celle in "basso" */
    if (piece.color[0] == BLACK || piece.promoted) {
        for (i = -1; i <= 1; i += 2) {
            Pos newPos = initialize_pos(piecePos.c + i, piecePos.r - 1);
            if (is_pos_valid(newPos)) {
                /* Se nella nuova cella c'è un avversario, controlla se lo può mangiare */
                if (is_opposite_color(board[get_index_from_pos(piecePos)].color[0],
                                      board[get_index_from_pos(newPos)].color[0])) {
                    newPos = initialize_pos(piecePos.c + (i * 2), piecePos.r - 2);
                }
                move = initialize_move(piecePos, newPos);
                if (is_move_valid(board, move)) {
                    cvector_push_back(moves, move);
                }
            }
        }
    }
    return moves;
}

#include "logic.h"
#include <stdlib.h>

int get_index_from_coordinates(int c, int r) {
    return r * COLUMNS + c;
}

int get_index_from_pos(Pos pos) {
    return get_index_from_coordinates(pos.c, pos.r);
}

void initialize_board(Piece *board) {
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLUMNS; c++) {
            if (is_pos_valid(initialize_pos(c, r)) && (r <= 2 || r >= 4)) {
                board[get_index_from_coordinates(c, r)] = initialize_piece(r <= 2 ? WHITE : BLACK, UNDEFINED, UNDEFINED,
                                                                           false, 1);
            } else {
                board[get_index_from_coordinates(c, r)] = initialize_null_piece();
            }
        }
    }
}

GameState compute_state(Piece *board, Color colorToMove) {
    /* Se il giocatore che deve muovere non ha nessuna mossa a disposizione ha perso */
    if (cvector_size(get_possible_moves_by_color(board, colorToMove)) == 0) {
        if (colorToMove == WHITE) return BLACK_WIN;
        else return WHITE_WIN;
    }
    /* Se un giocatore finisce i pezzi ha perso */
    if (cvector_size(get_pieces_pos_by_color(board, WHITE)) == 0)
        return BLACK_WIN;
    if (cvector_size(get_pieces_pos_by_color(board, BLACK)) == 0)
        return WHITE_WIN;
    /* Altrimenti il gioco continua */
    return PLAYING;
}

Move best_move_minimax(Piece *board, int depth, Color colorToMove, GameSettings settings) {
    Move move;
    /* TODO Davide */
    return move;
}

bool apply_move(Piece *board, Color colorToMove, Move move) {
    /* Controlla se la mossa è valida, se è in quelle possibili per quel colore
       Sposta i pezzi e li modifica nel caso qualcuno abbia mangiato */
    cvector_vector_type(Move) colorMoves = get_possible_moves_by_color(board, colorToMove);
    int i, flag = 0;

    print_moves(colorMoves);
    for (i = 0; i < cvector_size(colorMoves) && !flag; i++) {
        if (is_move_equal(move, colorMoves[i])) {
            if (does_move_eat(board, move)) {
                int eatenIndex = get_index_from_coordinates((move.from.c + move.to.c) / 2,
                                                            (move.from.r + move.to.r) / 2);
                Piece fromPiece = board[get_index_from_pos(move.from)];
                Piece eatenPiece = board[eatenIndex];

                /* Rimuovo il pezzo dalla board */
                board[eatenIndex] = initialize_null_piece();

                /* Aggiorno l'altezza */
                fromPiece.height += eatenPiece.height;

                if (fromPiece.height > MAX_HEIGHT) {
                    fromPiece.height = MAX_HEIGHT;
                }

                if (fromPiece.color[MAX_HEIGHT - 1] == UNDEFINED) {
                    /* Aggiorno i colori */
                    fromPiece.color[fromPiece.height - 1] = eatenPiece.color[0];
                }

                /* Muovo il pezzo che mangia */
                board[get_index_from_pos(move.to)] = fromPiece;
            } else {
                board[get_index_from_pos(move.to)] = board[get_index_from_pos(move.from)];
                board[get_index_from_pos(move.from)] = initialize_null_piece();
            }

            if(move.to.r == ROWS-1 || !move.to.r) {
                board[get_index_from_pos(move.from)].promoted = true;
            }

            flag = 1;
        }
    }

    cvector_free(colorMoves);

    return flag;
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

    int dx = abs(move.from.r - move.to.r);
    int dy = abs(move.from.c - move.to.c);

    if (dx == 1 && dy == 1) {
        return false;
    }

    if (middlePiece.color[0] != UNDEFINED) {
        /* Controllare condizioni */
        if (is_opposite_color(middlePiece.color[0], movedPiece.color[0]) &&
            middlePiece.height <= movedPiece.height) {
            return true;
        }
    }

    return false;
}

cvector_vector_type(Move) get_possible_moves_by_color(Piece *board, Color color) {
    cvector_vector_type(Move) allMoves = NULL;
    cvector_vector_type(Move) validMoves = NULL;
    int r, c, pos, i;
    bool mustEat = false;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLUMNS; c++) {
            pos = get_index_from_coordinates(c, r);
            if (!is_piece_null(board[pos]) && *board[pos].color == color) {
                Pos currentPos = initialize_pos(c, r);
                cvector_vector_type(Move) pieceMoves = get_possible_moves_by_piece(board, currentPos);
                cvector_copy(pieceMoves, allMoves);
            }
        }
    }
    /* Controlla se il colore che deve muovere è obbligato a mangiare */
    for (i = 0; i < cvector_size(allMoves); i++) {
        if (does_move_eat(board, allMoves[i])) {
            mustEat = true;
            break;
        }
    }
    if (!mustEat) return allMoves;

    for (i = 0; i < cvector_size(allMoves); i++) {
        if (does_move_eat(board, allMoves[i]))
            cvector_push_back(validMoves, allMoves[i]);
    }

    cvector_free(allMoves);
    /* TODO check this Davide */
    return validMoves;
}

cvector_vector_type(Move) get_possible_moves_by_piece(Piece *board, Pos piecePos) {
    int i;
    Move move;
    cvector_vector_type(Move) moves = NULL;
    Piece piece = board[get_index_from_pos(piecePos)];
    /* Controlla le celle in "alto" */
    if (piece.color[0] == WHITE || piece.promoted) {
        for (i = -1; i <= 1; i += 2) {
            int posColumn = piecePos.c + i;
            Pos newPos = initialize_pos(posColumn, piecePos.r + 1);
            if (is_pos_valid(newPos)) {
                /* Se nella nuova cella c'è un avversario, controlla se lo può mangiare */
                if (is_opposite_color(board[get_index_from_pos(piecePos)].color[0],
                                      board[get_index_from_pos(newPos)].color[0])) {
                    newPos = initialize_pos(piecePos.c + i * 2, piecePos.r + 1 * 2);
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
                if (board[get_index_from_pos(piecePos)].color[0] != board[get_index_from_pos(newPos)].color[0]) {
                    newPos = initialize_pos(piecePos.c + i * 2, piecePos.r - 1 * 2);
                }
                move = initialize_move(piecePos, newPos);
                if (is_move_valid(board, move)) {
                    cvector_push_back(moves, move);
                }
            }
        }
    }
    /* TODO add more tests Davide */
    return moves;
}

cvector_vector_type(Pos) get_pieces_pos_by_color(Piece *board, Color color) {
    cvector_vector_type(Pos) pieces = NULL;
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLUMNS; c++) {
            if (board[r].color[0] == color)
                cvector_push_back(pieces, initialize_pos(c, r));
        }
    }
    return pieces;
}
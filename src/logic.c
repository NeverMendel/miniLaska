#include "logic.h"
#include <stdlib.h>

inline int get_index_from_pos(Pos pos){
    return pos.r * COLUMNS + pos.c;
}

void initialize_board(Piece* board){
    int r, c;
    for(r = 0; r < ROWS; r++){
        for(c = 0; c < COLUMNS; c++){
            // TODO Giulia
        }
    }
}

GameState compute_state(Piece* board){
    if(cvector_size(get_possible_moves_by_color(board, WHITE)) == 0) return BLACK_WIN;
    if(cvector_size(get_possible_moves_by_color(board, BLACK)) == 0) return WHITE_WIN;
    GameState state = PLAYING;
    // TODO Christian
    return state;
}

Move best_move_minimax(Piece* board, int depth, Color colorToMove, GameSettings settings){
    Move move;
    // TODO Davide
    return move;
}

bool apply_move(Piece* board, Color colorToMove, Move move){
    // Controlla se la mossa è valida, se è in quelle possibili per quel colore
    // get_possible_moves_by_color

    // Sposta i pezzi e li modifica nel caso qualcuno abbia mangiato
    // TODO Christian
    return true;
}

bool is_move_valid(Piece* board, Move move){
    bool res = is_pos_valid(move.from) && is_pos_valid(move.to);
    int dx = abs(move.from.c - move.to.c);
    int dy = abs(move.from.r - move.to.r);
    int maxDiff = does_move_eat(board, move) ? 2 : 1;
    res = res && dx <= maxDiff && dy <= maxDiff;
    return res;
}

inline bool is_pos_valid(Pos pos){
    return pos.c >= 0 && pos.c < 7 && pos.r >= 0 && pos.r < 7 && (pos.c % 2 == pos.r % 2 || (pos.c + pos.r) % 2 == 0);
}

bool does_move_eat(Piece* board, Move move) {
    //TODO Christian
    return 0;
}

cvector_vector_type(Move) get_possible_moves_by_color(Piece* board, Color color){
    cvector_vector_type(Move) allMoves = NULL;
    int r, c, pos;
    for(r = 0; r < ROWS; r++){
        for(c = 0; c < COLUMNS; c++){
            pos = get_index_from_pos((Pos){c, r});
            if((board + pos) != NULL && *board[pos].color == color){
                Pos currentPos = {c, r};
                cvector_vector_type(Move) pieceMoves = get_possible_moves_by_piece(board, currentPos);
                cvector_copy(pieceMoves, allMoves);
            }
        }
    }
    // Controlla se il colore che deve muovere è obbligato a mangiare
    Move* movesIterator;
    bool mustEat = false;
    for(movesIterator = allMoves; movesIterator != NULL; movesIterator++){
        if(does_move_eat(board, *movesIterator)){
            mustEat = true;
            break;
        }
    }
    if(!mustEat) return allMoves;
    cvector_vector_type(Move) validMoves = NULL;
    int i;
    for(i = 0; i < cvector_size(allMoves); i++){
        if(does_move_eat(board, allMoves[i]))
            cvector_push_back(validMoves, allMoves[i]);
    }
    // TODO check this Davide
    return validMoves;
}

cvector_vector_type(Move) get_possible_moves_by_piece(Piece* board, Pos piecePos) {
    cvector_vector_type(Move) moves = NULL;
    Piece piece = board[get_index_from_pos(piecePos)];
    if(piece.color[0] == WHITE || piece.promoted) {
        int i;
        for(i = -1; i <=1; i += 2){
            Pos newPos = {piecePos.c + i, piecePos.r + 1};
            if(is_pos_valid(newPos)){
                Move move = {piecePos, newPos};
                if(is_move_valid(board, move)){
                    cvector_push_back(moves, move);
                }
            }
        }
    }
    if(piece.color[0] == BLACK || piece.promoted){
        int i;
        for(i = -1; i <=1; i += 2){
            Pos newPos = {piecePos.c + 1, piecePos.r + i};
            if(is_pos_valid(newPos)){
                Move move = {piecePos, newPos};
                if(is_move_valid(board, move)){
                    cvector_push_back(moves, move);
                }
            }
        }
    }
    return moves;
}

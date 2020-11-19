#include "logic.h"
#include "cvector.h"
#include <stdlib.h>

inline int get_index_from_pos(struct Pos pos){
    return pos.y * ROWS + pos.x;
}

void initialize_board(struct Piece* board){
    int r, c;
    for(r = 0; r < ROWS; r++){
        for(c = 0; c < COLUMNS; c++){
            // TODO Giulia
        }
    }
}

enum GameState compute_state(struct Piece* board){
    if(cvector_size(get_possible_moves_by_color(board, WHITE)) == 0) return BLACK_WIN;
    if(cvector_size(get_possible_moves_by_color(board, BLACK)) == 0) return WHITE_WIN;
    enum GameState state = PLAYING;
    // TODO Christian
    return state;
}

struct Move best_move_minimax(struct Piece* board, int depth, enum Color colorToMove, struct GameSettings settings){
    struct Move move;
    // TODO Davide
    return move;
}

bool apply_move(struct Piece* board, enum Color colorToMove, struct Move move){
    // Controlla se la mossa è valida, se è in quelle possibili per quel colore
    // get_possible_moves_by_color

    // Sposta i pezzi e li modifica nel caso qualcuno abbia mangiato
    // TODO Christian
    return true;
}

bool is_move_valid(struct Piece* board, struct Move move){
    bool res = is_pos_valid(move.from) && is_pos_valid(move.to);
    int dx = abs(move.from.x - move.to.x);
    int dy = abs(move.from.y - move.to.y);
    int maxDiff = does_move_eat(board, move) ? 2 : 1;
    res = res && dx <= maxDiff && dy <= maxDiff;
    return res;
}

inline bool is_pos_valid(struct Pos pos){
    return pos.x >=0 && pos.x < 7 && pos.y >=0 && pos.y < 7 && (pos.x % 2 == pos.y % 2 || (pos.x + pos.y) % 2 == 0);
}

bool does_move_eat(struct Piece* board, struct Move move) {
    //TODO Christian
    return 0;
}

cvector_vector_type(struct Move) get_possible_moves_by_color(struct Piece* board, enum Color color){
    cvector_vector_type(struct Move) allMoves = NULL;
    int r, c, pos;
    for(r = 0; r < ROWS; r++){
        for(c = 0; c < COLUMNS; c++){
            pos = r * COLUMNS + c;
            if((board + pos) != NULL && *board[pos].color == color){
                struct Pos currentPos = {r, c};
                cvector_vector_type(struct Move) pieceMoves = get_possible_moves_by_piece(board, currentPos);
                cvector_copy(pieceMoves, allMoves);
            }
        }
    }
    // Controlla se il colore che deve muovere è obbligato a mangiare
    struct Move* movesIterator;
    bool mustEat = false;
    for(movesIterator = allMoves; movesIterator != NULL; movesIterator++){
        if(does_move_eat(board, *movesIterator)){
            mustEat = true;
            break;
        }
    }
    if(!mustEat) return allMoves;
    cvector_vector_type(struct Move) validMoves = NULL;
    int i;
    for(i = 0; i < cvector_size(allMoves); i++){
        if(does_move_eat(board, allMoves[i]))
            cvector_push_back(validMoves, allMoves[i]);
    }
    // TODO check this Davide
    return validMoves;
}

cvector_vector_type(struct Move) get_possible_moves_by_piece(struct Piece* board, struct Pos piecePos) {
    cvector_vector_type(struct Move) moves = NULL;
    struct Piece piece = board[get_index_from_pos(piecePos)];
    if(piece.color[0] == WHITE || piece.promoted) {
        int i;
        for(i = -1; i <=1; i += 2){
            struct Pos newPos = {piecePos.x + i, piecePos.y + 1};
            if(is_pos_valid(newPos)){
                struct Move move = {piecePos, newPos};
                if(is_move_valid(board, move)){
                    cvector_push_back(moves, move);
                }
            }
        }
    }
    if(piece.color[0] == BLACK || piece.promoted){
        int i;
        for(i = -1; i <=1; i += 2){
            struct Pos newPos = {piecePos.x + 1, piecePos.y + i};
            if(is_pos_valid(newPos)){
                struct Move move = {piecePos, newPos};
                if(is_move_valid(board, move)){
                    cvector_push_back(moves, move);
                }
            }
        }
    }
    return moves;
}

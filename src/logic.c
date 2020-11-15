#include "logic.h"
#include <stdlib.h>

void initialize_board(struct Piece* board){
    int r, c;
    for(r = 0; r < ROWS; r++){
        for(c = 0; c < COLUMNS; c++){
            // TODO
        }
    }
}

enum GameState compute_state(struct Piece* board){
    enum GameState state = PLAYING;
    // TODO
    return state;
}

struct Move best_move_minimax(struct Piece* board, int depth, enum Color colorToMove, struct GameSettings settings){
    struct Move move;
    // TODO
    return move;
}

bool apply_move(struct Piece* board, struct Move move){
    // TODO
    return true;
}

bool does_move_eat(struct Piece* board, struct Move move) {
    //TODO
    return 0;
}

struct Move* get_possible_moves(struct Piece* board, struct Pos piecePos) {
    struct Move* moves = malloc(4 * sizeof(struct Move));
    if(moves != NULL){
        //TODO
    }
    return moves;
}

#include "logic.h"

enum GameState compute_state(struct Piece* board){
    enum GameState state = PLAYING;
    // TODO
    return state;
}

struct Move best_move_minimax(struct Piece* board, int depth, bool whiteToMove, struct GameSettings settings){
    struct Move move;
    // TODO
    return move;
}

bool apply_move(struct Piece* board, struct Move move){
    // TODO
    return true;
}
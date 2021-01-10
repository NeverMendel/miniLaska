#include "../src/logic.h"

void test_minimax(){
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos pos1, pos2;
    Move expected, actual;

    pos1 = initialize_pos(0, 0);
    pos2 = initialize_pos(1, 1);
    board[get_index_from_pos(pos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, 1, false);
    board[get_index_from_pos(pos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, 1, false);

    expected = initialize_move(pos1, initialize_pos(2, 2));
    actual = best_move_minimax(board, WHITE, EASY_DEPTH);

    assert(true == is_move_equal(expected, actual));
}

int main() {
    test_minimax();

    return 0;
}

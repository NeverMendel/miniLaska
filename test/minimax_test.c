#include <stdio.h>
#include "../src/logic.h"

void test_minimax_white_win() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos pos1, pos2, pos3;
    Move expected, actual;

    pos1 = initialize_pos(0, 0);
    pos2 = initialize_pos(5, 3);
    pos3 = initialize_pos(1, 1);
    board[get_index_from_pos(pos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);
    board[get_index_from_pos(pos2)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    board[get_index_from_pos(pos3)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    expected = initialize_move(pos1, initialize_pos(2, 2));
    actual = best_move_minimax(board, WHITE, EASY_DEPTH);

    assert(true == is_move_equal(expected, actual));
}

void test_minimax_black_win() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Move expected, actual;

    board[0] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);
    board[16] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    board[12] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    expected = initialize_move(get_pos_from_index(16), get_pos_from_index(8));
    actual = best_move_minimax(board, BLACK, EASY_DEPTH);

    assert(true == is_move_equal(expected, actual));
}

int main() {
    test_minimax_white_win();
    test_minimax_black_win();

    return 0;
}

#include "../src/logic.h"

void test_clone_board_copy() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Board copyBoard;
    int i;

    initialize_board(board);
    copyBoard = clone_board(board);

    for (i = 0; i < BOARD_SIZE; i++) {
        assert(true == is_piece_equal(board[i], copyBoard[i]));
    }
}

void test_clone_board_copy_and_change() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Board copyBoard;

    initialize_board(board);
    copyBoard = clone_board(board);

    board[0].color[0] = BLACK;

    assert(false == is_piece_equal(board[0], copyBoard[0]));
    assert(true == is_piece_equal(board[0], initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1)));
}

int main() {
    test_clone_board_copy();
    test_clone_board_copy_and_change();

    return 0;
}

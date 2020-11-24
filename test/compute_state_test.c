#include "../src/logic.h"
#include "../src/utility.h"

void test_compute_state_initial_state() {
    Piece *board = calloc(ROWS * COLUMNS, sizeof(Piece));
    GameState expected, actual;
    initialize_board(board);
    expected = PLAYING;
    actual = compute_state(board, WHITE);
    assert(expected == actual);
}

void test_compute_state_black_win() {
    Piece *board = calloc(ROWS * COLUMNS, sizeof(Piece));
    Pos piecePos;
    GameState expected, actual;

    piecePos = initialize_pos(2, 2);
    board[get_index_from_pos(piecePos)] = initialize_piece(BLACK, WHITE, UNDEFINED, false, 2);
    expected = BLACK_WIN;
    actual = compute_state(board, WHITE);
    assert(expected == actual);
}

int main() {
    test_compute_state_initial_state();
    test_compute_state_black_win();
}

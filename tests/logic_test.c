#include "minunit.h"
#include "../src/logic.h"

MU_TEST(test_compute_state) {
    struct Piece* board = malloc(ROWS * COLUMNS * sizeof(struct Piece));
    initialize_board(board);
    bool expected = PLAYING;
    bool actual = compute_state(board);
    mu_check(expected == actual);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_compute_state);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
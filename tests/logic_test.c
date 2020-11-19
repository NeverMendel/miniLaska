#include "minunit.h"
#include "../src/logic.h"

MU_TEST(test_compute_state_initial_state) {
    struct Piece* board = malloc(ROWS * COLUMNS * sizeof(struct Piece));
    initialize_board(board);
    bool expected = PLAYING;
    bool actual = compute_state(board);
    mu_check(expected == actual);
}

MU_TEST(test_compute_state_black_win) {
    // Inizializzi la scacchiera in una situazione di vittoria per il nero
    struct Piece* board = malloc(ROWS * COLUMNS * sizeof(struct Piece));
    // TODO Christian
    bool expected = BLACK_WIN;
    bool actual = compute_state(board);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_valid_pos1) {
    struct Pos pos = {4, 4};
    bool expected = true;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_valid_pos2) {
    struct Pos pos = {6, 0};
    bool expected = true;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_out_of_bound) {
    struct Pos pos = {7,2};
    bool expected = false;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_not_used_cell1) {
    struct Pos pos = {1,2};
    bool expected = false;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_not_used_cell2) {
    struct Pos pos = {3,6};
    bool expected = false;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_compute_state_initial_state);
    MU_RUN_TEST(test_compute_state_black_win);

    MU_RUN_TEST(test_is_pos_valid_valid_pos1);
    MU_RUN_TEST(test_is_pos_valid_valid_pos2);
    MU_RUN_TEST(test_is_pos_valid_out_of_bound);
    MU_RUN_TEST(test_is_pos_valid_not_used_cell1);
    MU_RUN_TEST(test_is_pos_valid_not_used_cell2);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
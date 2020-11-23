#include "minunit.h"
#include "../src/logic.h"
#include "../src/utility.h"

MU_TEST(test_does_move_eat1) {
    Piece* board = malloc(ROWS * COLUMNS * sizeof(Piece));
    initialize_board(board);

    Pos piecePos1 = {1,1};
    board[get_index_from_pos(piecePos1)] = (Piece) {{WHITE, UNDEFINED, UNDEFINED}, false, 1};

    Pos piecePos2 = {2,2};
    board[get_index_from_pos(piecePos2)] = (Piece) {{BLACK, UNDEFINED, UNDEFINED}, false, 1};
    
    Pos pos3 = {3,3};

    Move move = {piecePos1, pos3};

    bool actual = does_move_eat(board, move);

    mu_check(actual == true);
}

MU_TEST(test_does_move_eat2) {
    Piece* board = malloc(ROWS * COLUMNS * sizeof(Piece));
    initialize_board(board);

    Pos piecePos1 = {1,1};
    board[get_index_from_pos(piecePos1)] = (Piece) {{WHITE, UNDEFINED, UNDEFINED}, false, 1};

    Pos piecePos2 = {3,3};
    board[get_index_from_pos(piecePos2)] = (Piece) {{BLACK, UNDEFINED, UNDEFINED}, false, 1};
    
    Pos pos3 = {2,2};

    Move move = {piecePos1, pos3};

    bool actual = does_move_eat(board, move);

    mu_check(actual == false);
}

MU_TEST(test_does_move_eat3) {
    Piece* board = malloc(ROWS * COLUMNS * sizeof(Piece));
    initialize_board(board);

    Pos piecePos1 = {1,1};
    board[get_index_from_pos(piecePos1)] = (Piece) {{WHITE, UNDEFINED, UNDEFINED}, false, 1};

    Pos piecePos2 = {3,3};
    board[get_index_from_pos(piecePos2)] = (Piece) {{BLACK, UNDEFINED, UNDEFINED}, false, 1};
    
    Pos pos3 = {4,4};

    Move move = {piecePos1, pos3};

    bool actual = does_move_eat(board, move);

    mu_check(actual == false);
}

MU_TEST(test_compute_state_initial_state) {
    Piece* board = malloc(ROWS * COLUMNS * sizeof(Piece));
    initialize_board(board);
    GameState expected = PLAYING;
    GameState actual = compute_state(board);
    mu_check(expected == actual);
}

MU_TEST(test_compute_state_black_win) {
    // Inizializzi la scacchiera in una situazione di vittoria per il nero
    Piece* board = malloc(ROWS * COLUMNS * sizeof(Piece));
    // TODO Christian
    GameState expected = BLACK_WIN;
    GameState actual = compute_state(board);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_valid_pos1) {
    Pos pos = {4, 4};
    bool expected = true;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_valid_pos2) {
    Pos pos = {6, 0};
    bool expected = true;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_out_of_bound) {
    Pos pos = {7,2};
    bool expected = false;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_not_used_cell1) {
    Pos pos = {1,2};
    bool expected = false;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST(test_is_pos_valid_not_used_cell2) {
    Pos pos = {3,6};
    bool expected = false;
    bool actual = is_pos_valid(pos);
    mu_check(expected == actual);
}

MU_TEST(test_get_possible_moves_by_piece1) {
    Piece* board = calloc(ROWS * COLUMNS, sizeof(Piece));
    Pos piecePos = {1,1};
    board[get_index_from_pos(piecePos)] = (Piece) {{WHITE, UNDEFINED, UNDEFINED}, false, 1};
    cvector_vector_type(Move) expected = NULL;
    cvector_push_back(expected, ((Move){{1,1},{0,2}}));
    cvector_push_back(expected, ((Move){{1,1},{2,2}}));
    cvector_vector_type(Move) actual = get_possible_moves_by_piece(board, piecePos);

    mu_check(cvector_size(actual) == 2);
    mu_check( is_move_equal(expected[0], actual[0]) && is_move_equal(expected[1], actual[1]));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_compute_state_initial_state);
    MU_RUN_TEST(test_compute_state_black_win);

    MU_RUN_TEST(test_is_pos_valid_valid_pos1);
    MU_RUN_TEST(test_is_pos_valid_valid_pos2);
    MU_RUN_TEST(test_is_pos_valid_out_of_bound);
    MU_RUN_TEST(test_is_pos_valid_not_used_cell1);
    MU_RUN_TEST(test_is_pos_valid_not_used_cell2);

    MU_RUN_TEST(test_get_possible_moves_by_piece1);

    MU_RUN_TEST(test_does_move_eat1);
    MU_RUN_TEST(test_does_move_eat2);
    MU_RUN_TEST(test_does_move_eat3);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
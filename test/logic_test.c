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
    bool expected = true;

    mu_check(expected == actual);
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
    bool expected = false;

    mu_check(expected == actual);
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
    bool expected = false;

    mu_check(expected == actual);
}

MU_TEST(test_compute_state_initial_state) {
    Piece* board = malloc(ROWS * COLUMNS * sizeof(Piece));
    initialize_board(board);
    GameState expected = PLAYING;
    GameState actual = compute_state(board);
    mu_check(expected == actual);
}

MU_TEST(test_compute_state_black_win) {
    Piece* board = malloc(ROWS * COLUMNS * sizeof(Piece));

    Pos piecePos = {2,2};
    board[get_index_from_pos(piecePos)] = (Piece) {{BLACK, WHITE, UNDEFINED}, false, 2};

    GameState expected = BLACK_WIN;
    GameState actual = compute_state(board);
    mu_check(expected == actual);
}

MU_TEST(test_apply_move1) {
    Piece* board = malloc(ROWS * COLUMNS * sizeof(Piece));
    
    Pos piecePos1 = {3,1};
    board[get_index_from_pos(piecePos1)] = (Piece) {{WHITE, UNDEFINED, UNDEFINED}, false, 1};
    
    Pos piecePos2 = {3,3};
    board[get_index_from_pos(piecePos2)] = (Piece) {{WHITE, UNDEFINED, UNDEFINED}, false, 2};

    Pos piecePos3 = {4,4};
    board[get_index_from_pos(piecePos3)] = (Piece) {{BLACK, WHITE, UNDEFINED}, false, 2};

    Pos newPos1 = {2,2};
    Pos newPos2 = {1,3};

    Move move1 = {piecePos3, newPos1};
    assert(1 == apply_move(board, BLACK, move1));
    
    Move move2 = {piecePos1, newPos2};
    assert(1 == apply_move(board, WHITE, move2));

    Piece actual = board[get_index_from_pos(newPos2)];
    Piece expected = {{WHITE, BLACK, UNDEFINED}, false, 2};

    mu_check(is_piece_equal(expected,actual));
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

    MU_RUN_TEST(test_apply_move1);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
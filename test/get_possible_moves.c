#include "../src/logic.h"
#include "../src/utility.h"

void test_get_possible_moves_by_piece1() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos;
    Move move1, move2;
    cvector_vector_type(Move) expected = NULL;
    cvector_vector_type(Move) actual = NULL;

    piecePos = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);
    move1 = initialize_move(initialize_pos(1, 1), initialize_pos(0, 2));
    move2 = initialize_move(initialize_pos(1, 1), initialize_pos(2, 2));

    cvector_push_back(expected, move1);
    cvector_push_back(expected, move2);
    actual = get_possible_moves_by_piece(board, piecePos);

    assert((int) cvector_size(actual) == 2);
    assert(is_move_equal(expected[0], actual[0]) && is_move_equal(expected[1], actual[1]));
}

void test_get_possible_moves_by_piece2() {
    /* http://www.lasca.org/pictures/nx/2i.gif */
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos1, piecePos2;
    Move move1;
    cvector_vector_type(Move) expected = NULL;
    cvector_vector_type(Move) actual = NULL;

    piecePos1 = initialize_pos(0, 0);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    move1 = initialize_move(piecePos1, initialize_pos(2, 2));

    cvector_push_back(expected, move1);
    actual = get_possible_moves_by_piece(board, piecePos1);

    assert((int) cvector_size(actual) == 1);
    assert(is_move_equal(expected[0], actual[0]));
}

void test_get_possible_moves_by_piece3() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos1, piecePos2;
    Move move1;
    cvector_vector_type(Move) expected = NULL;
    cvector_vector_type(Move) actual = NULL;

    piecePos1 = initialize_pos(2, 0);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    cvector_push_back(expected, initialize_move(piecePos1, initialize_pos(0, 2)));
    cvector_push_back(expected, initialize_move(piecePos1, initialize_pos(3, 1)));
    actual = get_possible_moves_by_piece(board, piecePos1);

    assert((int) cvector_size(actual) == 2);
    assert(is_move_equal(expected[0], actual[0]));
}

void test_get_possible_moves_by_piece4() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos1, piecePos2;
    Move move1;
    cvector_vector_type(Move) expected = NULL;
    cvector_vector_type(Move) actual = NULL;

    piecePos1 = initialize_pos(2, 0);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, WHITE, WHITE, false, 3);

    cvector_push_back(expected, initialize_move(piecePos1, initialize_pos(0, 2)));
    cvector_push_back(expected, initialize_move(piecePos1, initialize_pos(3, 1)));
    actual = get_possible_moves_by_piece(board, piecePos1);

    assert((int) cvector_size(actual) == 2);
    assert(is_move_equal(expected[0], actual[0]));
}

void test_get_possible_moves_by_piece_black_move() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos;
    cvector_vector_type(Move) expected = NULL;
    cvector_vector_type(Move) actual = NULL;

    piecePos = initialize_pos(4, 4);
    board[get_index_from_pos(piecePos)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    cvector_push_back(expected, initialize_move(piecePos, initialize_pos(3, 3)));
    cvector_push_back(expected, initialize_move(piecePos, initialize_pos(5, 3)));
    actual = get_possible_moves_by_piece(board, piecePos);

    assert((int) cvector_size(actual) == 2);
    assert(is_move_equal(expected[0], actual[0]));
    assert(is_move_equal(expected[1], actual[1]));
}

void test_get_possible_moves_by_color1() {
    /* http://www.lasca.org/pictures/nx/2i.gif */
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos1, piecePos2;
    Move move1;
    cvector_vector_type(Move) expected = NULL;
    cvector_vector_type(Move) actual = NULL;

    piecePos1 = initialize_pos(0, 0);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    move1 = initialize_move(initialize_pos(0, 0), initialize_pos(2, 2));

    cvector_push_back(expected, move1);
    actual = get_possible_moves_by_color(board, WHITE);

    assert((int) cvector_size(actual) == 1);
    assert(is_move_equal(expected[0], actual[0]));
}

int main(int argc, char *argv[]) {
    test_get_possible_moves_by_piece1();
    test_get_possible_moves_by_piece2();
    test_get_possible_moves_by_piece3();
    test_get_possible_moves_by_piece4();
    test_get_possible_moves_by_piece_black_move();
    test_get_possible_moves_by_color1();

    return 0;
}

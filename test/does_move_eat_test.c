#include "../src/logic.h"
#include "../src/utility.h"

void test_does_move_eat1() {
    Piece *board = calloc(ROWS * COLUMNS, sizeof(Piece));
    Pos piecePos1, piecePos2, piecePos3;
    bool actual, expected;
    Move move;

    piecePos1 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(2, 2);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    piecePos3 = initialize_pos(3, 3);
    move = initialize_move(piecePos1, piecePos3);

    actual = does_move_eat(board, move);
    expected = true;

    assert(expected == actual);
}

void test_does_move_eat2() {
    Piece *board = calloc(ROWS * COLUMNS, sizeof(Piece));
    Pos piecePos1, piecePos2, piecePos3;
    Move move;
    bool actual, expected;

    piecePos1 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(3, 3);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    piecePos3 = initialize_pos(2, 2);
    move = initialize_move(piecePos1, piecePos3);

    actual = does_move_eat(board, move);
    expected = false;

    assert(expected == actual);
}

void test_does_move_eat3() {
    Piece *board = calloc(ROWS * COLUMNS, sizeof(Piece));
    Pos piecePos1, piecePos2, piecePos3;
    Move move;
    bool actual, expected;

    piecePos1 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(3, 3);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    piecePos3 = initialize_pos(4, 4);
    move = initialize_move(piecePos1, piecePos3);

    actual = does_move_eat(board, move);
    expected = false;

    assert(expected == actual);
}

int main() {
    test_does_move_eat1();
    test_does_move_eat2();
    test_does_move_eat3();
}

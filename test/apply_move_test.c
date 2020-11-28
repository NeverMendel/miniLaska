#include "../src/logic.h"
#include "../src/terminal.h"

void test_apply_move_eat() {
    Piece *board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos1, piecePos2, newPos1;
    Move move;
    Piece expectedPiece, actualPiece;
    bool expected, actual;

    piecePos1 = initialize_pos(2, 2);
    piecePos2 = initialize_pos(3, 3);

    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    newPos1 = initialize_pos(4, 4);
    move = initialize_move(piecePos1, newPos1);

    expected = true;
    actual = apply_move(board, WHITE, move);
    assert(actual == expected);

    expectedPiece = initialize_piece(WHITE, BLACK, UNDEFINED, false, 2);
    actualPiece = board[get_index_from_pos(newPos1)];

    assert(is_piece_equal(expectedPiece, actualPiece));

    assert(is_piece_null(board[get_index_from_pos(piecePos1)]) == true);
}

void test_apply_move_liberate_prisoner() {
    /* http://www.lasca.org/show?6V6
    http://www.lasca.org/pictures/nx/3ii.gif
    http://www.lasca.org/pictures/nx/3iii.gif
    http://www.lasca.org/pictures/nx/3iv.gif */

    Piece *board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos1, piecePos2, piecePos3;
    Pos newPos1, newPos3;
    Move move3, move1;
    Piece expectedPiece, actualPiece;
    bool expected, actual;

    piecePos1 = initialize_pos(2, 0);
    piecePos2 = initialize_pos(2, 2);
    piecePos3 = initialize_pos(3, 3);

    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);
    board[get_index_from_pos(piecePos2)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);
    board[get_index_from_pos(piecePos3)] = initialize_piece(BLACK, WHITE, UNDEFINED, false, 2);

    newPos3 = initialize_pos(1, 1);
    newPos1 = initialize_pos(0, 2);

    move3 = initialize_move(piecePos3, newPos3);

    expected = true;
    actual = apply_move(board, BLACK, move3);

    assert(expected == actual);

    move1 = initialize_move(piecePos1, newPos1);

    expected = true;
    actual = apply_move(board, WHITE, move1);

    assert(expected == actual);

    actualPiece = board[get_index_from_pos(newPos3)];
    expectedPiece = initialize_piece(WHITE, WHITE, UNDEFINED, false, 2);
    assert(is_piece_equal(expectedPiece, actualPiece));
}

int main() {
    test_apply_move_eat();
    test_apply_move_liberate_prisoner();

    return 0;
}

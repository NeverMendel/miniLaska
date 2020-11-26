#include "../src/logic.h"
#include "../src/utility.h"

void test_apply_move1() {
    /* http://www.lasca.org/show?6V6
    http://www.lasca.org/pictures/nx/3ii.gif
    http://www.lasca.org/pictures/nx/3iii.gif
    http://www.lasca.org/pictures/nx/3iv.gif */

    Piece *board = calloc(ROWS * COLUMNS, sizeof(Piece));
    Pos piecePos1, piecePos2, piecePos3;
    Pos newPos1, newPos2;
    Move move1, move2;
    Piece actualPiece, expectedPiece;
    bool expected, actual;

    piecePos1 = initialize_pos(2, 0);
    piecePos2 = initialize_pos(2, 2);
    piecePos3 = initialize_pos(3, 3);

    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);
    board[get_index_from_pos(piecePos2)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);
    board[get_index_from_pos(piecePos3)] = initialize_piece(BLACK, WHITE, UNDEFINED, false, 2);

    newPos1 = initialize_pos(1, 1);
    newPos2 = initialize_pos(0, 2);

    move1 = initialize_move(piecePos3, newPos1);

    expected = true;
    actual = apply_move(board, BLACK, move1);

    assert(expected == actual);

    move2 = initialize_move(piecePos1, newPos2);

    expected = true;
    actual = apply_move(board, WHITE, move2);
    assert(expected == actual);

    actualPiece = board[get_index_from_pos(newPos2)];
    expectedPiece = initialize_piece(WHITE, BLACK, UNDEFINED, false, 2);
    
    assert(is_piece_equal(expectedPiece, actualPiece));
}

int main() {
    test_apply_move1();
}

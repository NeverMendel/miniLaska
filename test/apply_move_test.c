#include "../src/logic.h"
#include "../src/utility.h"

void test_apply_move1() {
    Piece *board = calloc(ROWS * COLUMNS, sizeof(Piece));
    Pos piecePos1, piecePos2, piecePos3;
    Pos newPos1, newPos2;
    Move move1, move2;
    Piece actualPiece, expectedPiece;
    bool expected, actual;

    piecePos1 = initialize_pos(3, 1);
    piecePos2 = initialize_pos(3, 3);
    piecePos3 = initialize_pos(4, 4);

    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);
    board[get_index_from_pos(piecePos2)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);
    board[get_index_from_pos(piecePos3)] = initialize_piece(BLACK, WHITE, UNDEFINED, false, 2);

    newPos1 = initialize_pos(2, 2);
    newPos2 = initialize_pos(1, 3);

    move1 = initialize_move(piecePos3, newPos1);

    expected = true;
    actual = apply_move(board, BLACK, move1);

    assert(expected == actual);

    move2 = initialize_move(piecePos1, newPos2);

    expected = true;
    actual = apply_move(board, WHITE, move2);
    assert(expected == actual);

    actualPiece = board[get_index_from_pos(newPos2)];
    expectedPiece = initialize_piece(WHITE, BLACK, WHITE, false, 3);
    assert(is_piece_equal(expectedPiece, actualPiece));
}

int main() {
    test_apply_move1();
}

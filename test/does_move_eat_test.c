#include "../src/logic.h"
#include "../src/utility.h"

void test_does_move_eat_two_pieces() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos1, piecePos2, piecePos3;
    bool actual, expected;
    Move move;

    piecePos1 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(2, 2);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    piecePos3 = initialize_pos(3, 3);
    move = initialize_move(piecePos1, piecePos3);

    expected = true;
    actual = does_move_eat(board, move);

    assert(expected == actual);
}

void test_does_move_eat_invalid_move() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos1, piecePos2, piecePos3;
    Move move;
    bool actual, expected;

    piecePos1 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(3, 3);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    piecePos3 = initialize_pos(2, 2);
    move = initialize_move(piecePos1, piecePos3);

    expected = false;
    actual = does_move_eat(board, move);

    assert(expected == actual);
}

void test_does_move_eat_invalid_move2() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos piecePos1, piecePos2, piecePos3;
    Move move;
    bool actual, expected;

    piecePos1 = initialize_pos(1, 1);
    board[get_index_from_pos(piecePos1)] = initialize_piece(WHITE, UNDEFINED, UNDEFINED, false, 1);

    piecePos2 = initialize_pos(3, 3);
    board[get_index_from_pos(piecePos2)] = initialize_piece(BLACK, UNDEFINED, UNDEFINED, false, 1);

    piecePos3 = initialize_pos(4, 4);
    move = initialize_move(piecePos1, piecePos3);

    expected = false;
    actual = does_move_eat(board, move);

    assert(expected == actual);
}

test_does_move_eat_strong_column() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    Pos pos1, pos2, pos3;
    Move move;
    bool actual, expected;

    pos1 = initialize_pos(0, 6);
    board[get_index_from_pos(pos1)] = initialize_piece(WHITE, BLACK, BLACK, true, 3);

    pos2 = initialize_pos(1, 5);
    board[get_index_from_pos(pos2)] = initialize_piece(BLACK, BLACK, UNDEFINED, true, 2);

    pos3 = initialize_pos(2, 4);
    move = initialize_move(pos1, pos3);

    expected = true;
    actual = does_move_eat(board, move);

    assert(expected == actual);
}

int main() {
    test_does_move_eat_two_pieces();
    test_does_move_eat_invalid_move();
    test_does_move_eat_invalid_move2();
    test_does_move_eat_strong_column();

    return 0;
}

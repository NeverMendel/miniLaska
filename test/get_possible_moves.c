#include "../src/logic.h"
#include "../src/utility.h"

void test_get_possible_moves_by_piece1() {
    Piece *board = calloc(ROWS * COLUMNS, sizeof(Piece));
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

int main(int argc, char *argv[]) {
    test_get_possible_moves_by_piece1();
}

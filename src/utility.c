#include <stdio.h>
#include <string.h>
#include "utility.h"
#include "logic.h"

bool is_piece_null(Piece piece) {
    return piece.color[0] == UNDEFINED;
}

bool is_move_equal(Move a, Move b) {
    return is_pos_equal(a.from, b.from) && is_pos_equal(a.to, b.to);
}

bool is_pos_equal(Pos a, Pos b) {
    return a.c == b.c && a.r == b.r;
}

bool is_opposite_color(Color a, Color b) {
    return (a == WHITE && b == BLACK) || (a == BLACK && b == WHITE);
}

bool is_piece_equal(Piece a, Piece b) {
    int i;
    for (i = 0; i < MAX_HEIGHT; i++) {
        if (a.color[i] != b.color[i]) return false;
    }
    return (a.promoted == b.promoted) && (a.height == b.height);
}

Pos initialize_pos(int c, int r) {
    Pos pos;
    pos.c = c;
    pos.r = r;
    return pos;
}

Move initialize_move(Pos from, Pos to) {
    Move move;
    move.from = from;
    move.to = to;
    return move;
}

Piece initialize_piece(Color color0, Color color1, Color color2, bool promoted, int height) {
    Piece piece;
    piece.color[0] = color0;
    piece.color[1] = color1;
    piece.color[2] = color2;
    piece.promoted = promoted;
    piece.height = height;
    return piece;
}

Piece initialize_null_piece() {
    return initialize_piece(UNDEFINED, UNDEFINED, UNDEFINED, false, 0);
}

Color get_opposite_color(Color color) {
    return color == WHITE ? BLACK : WHITE;
}

Board clone_board(Board board) {
    Board newBoard = malloc(BOARD_SIZE * sizeof(Piece));
    if (newBoard == NULL) {
        printf("Error allocating the board in the memory");
        exit(EXIT_FAILURE);
    }
    memcpy(newBoard, board, BOARD_SIZE * sizeof(Piece));
    return newBoard;
}

cvector_vector_type(Pos) get_pieces_pos_by_color(Board board, Color color) {
    cvector_vector_type(Pos) pieces = NULL;
    int r, c;
    Pos pos;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLUMNS; c++) {
            pos = initialize_pos(c, r);
            if (is_pos_valid(pos) && board[get_index_from_pos(pos)].color[0] == color)
                cvector_push_back(pieces, pos);
        }
    }
    return pieces;
}

int count_pieces(Board board, Color color){
    int count = 0, i;
    for(i = 0; i < BOARD_SIZE; i++){
        if(board[i].color[0] == color)
            count++;
    }
    return count;
}

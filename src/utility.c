#include <stdio.h>
#include "utility.h"

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
    return a.promoted == b.promoted && a.height == b.height;
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

void print_moves(cvector_vector_type(Move) moves) {
    int i;
    printf("size: %d\n", (int) cvector_size(moves));
    for (i = 0; i < cvector_size(moves); i++) {
        printf("[%d] from: %d-%d, to %d-%d\n", i, moves[i].from.c, moves[i].from.r, moves[i].to.c, moves[i].to.r);
    }
}

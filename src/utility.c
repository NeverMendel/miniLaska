#include "utility.h"

bool is_piece_null(Piece piece){
    return piece.color[0] == UNDEFINED;
}

bool is_move_equal(Move a, Move b){
    return is_pos_equal(a.from, b.from) && is_pos_equal(a.to, b.to);
}

bool is_pos_equal(Pos a, Pos b){
    return a.c == b.c && a.r == b.r;
}

bool is_opposite_color(Color a, Color b){
    return (a == WHITE && b == BLACK) || (a == BLACK && b == WHITE);
}
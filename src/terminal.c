#include "terminal.h"

void display_board(struct Piece* board){
    int r;
    int c;
    for(r = 0; r < ROWS; r++){
        for(c = 0; c < COLUMNS; c++){
            if(board[r * COLUMNS + c].white){
                //TODO
            }
        }
    }
}
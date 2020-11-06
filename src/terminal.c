#include "terminal.h"
#include <stdio.h>

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

void display_winner(enum GameState state){
    switch (state) {
        case DRAW:
            printf("Draw");
            break;
        case WHITE_WIN:
            printf("The winner is white");
            break;
        case BLACK_WIN:
            printf("The winner is black");
            break;
        default:
            printf("Invalid state");
            break;
    };
}
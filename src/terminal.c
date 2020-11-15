#include "terminal.h"
#include <stdio.h>

void display_board(struct Piece* board){
    int r;
    int c;
    for(r = 0; r < ROWS; r++){
        for(c = 0; c < COLUMNS; c++){
            if(board[r * COLUMNS + c].color == WHITE){
                //TODO
            } else {

            }
        }
    }
}

struct GameSettings read_game_settings(){
    struct GameSettings settings;
    char input = 0;

    // white
    while(input != 'h' && input != 'c'){
        printf("Select the type of the white player (human or computer) by typing h or c\n");
        scanf(" %c", &input);
    }
    if(input == 'h') settings.white = HUMAN;
    else {
        settings.white = COMPUTER;
        while(input < '1' || input > '3'){
            printf("Select the level of the computer playing with white \n  1 - Easy\n  2 - Medium\n  3 - Hard\n");
            scanf(" %c", &input);
        }
        settings.whiteLevel = input - '1';
    }

    input = 0;
    // black
    while(input != 'h' && input != 'c'){
        printf("Select the type of the black player (human or computer) by typing h or c\n");
        scanf(" %c", &input);
    }
    if(input == 'h') settings.black = HUMAN;
    else {
        settings.black = COMPUTER;
        while(input < '1' || input > '3'){
            printf("Select the level of the computer playing with black \n  1 - Easy\n  2 - Medium\n  3 - Hard\n");
            scanf(" %c", &input);
        }
        settings.blackLevel = input - '1';
    }
    return settings;
}

struct Move read_player_move(){
    struct Move move;
    // TODO
    return move;
}

void display_error_incorrect_move(struct Move move){
    printf("The move {%d, %d} -> {%d, %d} is not valid", move.from.x, move.from.y, move.to.x, move.to.y);
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
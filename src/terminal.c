#include "terminal.h"
#include <stdio.h>

void display_board(Piece* board){
    int r;
    int c;
    for(r = 0; r < ROWS; r++){
        for(c = 0; c < COLUMNS; c++){
            // TODO Giulia
//            if(board[r * COLUMNS + c] == WHITE){
//
//            } else {
//
//            }
        }
    }
}

GameSettings read_game_settings(){
    GameSettings settings;
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

Move read_player_move(Piece* board, Color color){
    Move move;
    // Visualizza tutte le mosse che il giocatore può giocare e fa selezionare all'utente una di quelle
    // Es: 1 - a3-b4
    //     2 - c3-b4
    //     etc...
    // get_possible_moves_by_color
    // TODO Giulia
    return move;
}

void display_error_incorrect_move(Move move){
    printf("The move {%d, %d} -> {%d, %d} is not valid", move.from.c, move.from.r, move.to.c, move.to.r);
}

void display_winner(GameState state){
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
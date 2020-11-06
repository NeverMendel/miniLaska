#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constants.h"
#include "terminal.h"
#include "logic.h"

int main() {

    struct Piece* board = malloc(ROWS * COLUMNS * sizeof(struct Piece));
    enum GameState state = PLAYING;
    bool whiteTurn = true;
    struct GameSettings settings = read_game_settings();

    struct Move currentMove;
    enum PlayerType currentPlayer;

    while(state == PLAYING){
        display_board(board);

        if(whiteTurn) currentPlayer = settings.white;
        else currentPlayer = settings.black;

        bool toMove = true;
        while(toMove){
            if(currentPlayer == HUMAN) currentMove = read_player_move();
            else currentMove = best_move_minimax(board, 4, whiteTurn);
            toMove = !apply_move(board, currentMove);
            if(toMove) display_error_incorrect_move();
        }

        //TODO

        whiteTurn = !whiteTurn;
        state = compute_state(board);
    }

    whiteTurn = !whiteTurn;

    printf("The winner is ");
    printf((whiteTurn ? "white" : "black"));

    return 0;
}
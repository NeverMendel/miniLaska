#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "terminal.h"
#include "logic.h"

int main() {

    struct Piece* board = malloc(ROWS * COLUMNS * sizeof(struct Piece));

    if(board == NULL){
        printf("Error allocating the board in the memory");
        exit(EXIT_FAILURE);
    }

    initialize_board(board);

    enum GameState state = PLAYING;
    enum Color colorToMove = WHITE;
    struct GameSettings settings = read_game_settings();

    struct Move currentMove;
    enum PlayerType currentPlayer;

    while(state == PLAYING){
        display_board(board);

        if(colorToMove == WHITE) currentPlayer = settings.white;
        else currentPlayer = settings.black;

        if(currentPlayer == HUMAN) currentMove = read_player_move();
        else currentMove = best_move_minimax(board, 4, colorToMove, settings);

        //TODO

        colorToMove = (colorToMove == WHITE ? BLACK : WHITE);
        state = compute_state(board);
    }

    display_winner(state);

    free(board);

    return 0;
}
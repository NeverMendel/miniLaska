#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "utility.h"
#include "terminal.h"
#include "logic.h"

int main() {
    Piece* board = calloc(ROWS * COLUMNS, sizeof(Piece));
    GameState state;
    Color colorToMove;
    GameSettings settings;
    Move currentMove;
    PlayerType currentPlayer;

    if(board == NULL){
        printf("Error allocating the board in the memory");
        exit(EXIT_FAILURE);
    }

    initialize_board(board);

    state = PLAYING;
    colorToMove = WHITE;
    settings = read_game_settings();

    while(state == PLAYING){
        display_board(board);

        if(colorToMove == WHITE) currentPlayer = settings.white;
        else currentPlayer = settings.black;

        if(currentPlayer == HUMAN) currentMove = read_player_move(board, colorToMove);
        else currentMove = best_move_minimax(board, 4, colorToMove, settings);

        apply_move(board, colorToMove, currentMove);

        colorToMove = (colorToMove == WHITE ? BLACK : WHITE);
        state = compute_state(board, colorToMove);
    }

    display_board(board);

    display_winner(state);

    free(board);

    return 0;
}
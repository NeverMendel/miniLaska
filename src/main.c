#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "utility.h"
#include "terminal.h"
#include "logic.h"

int main() {
    Piece *board = calloc(BOARD_SIZE, sizeof(Piece));
    GameState state;
    Color colorToMove;
    GameSettings settings;
    Move currentMove;
    Player currentPlayer;

    if (board == NULL) {
        printf("Error allocating the board in the memory");
        exit(EXIT_FAILURE);
    }

    initialize_board(board);

    state = PLAYING;
    colorToMove = WHITE;
    settings = read_game_settings();

    while (state == PLAYING) {
#ifndef DEBUG
        system("cls");
#endif
        display_board(board);

        if (colorToMove == WHITE) currentPlayer = settings.white;
        else currentPlayer = settings.black;

        if (currentPlayer.type == HUMAN) currentMove = read_player_move(board, colorToMove);
        else {
            int depth;
            if (currentPlayer.level == EASY) depth = 2;
            else if (currentPlayer.level == MEDIUM) depth = 5;
            else depth = 7;

            currentMove = best_move_minimax(board, colorToMove, depth);
        }

        apply_move(board, colorToMove, currentMove);

        colorToMove = get_opposite_color(colorToMove);
        state = compute_state(board, colorToMove);
    }

    display_board(board);

    display_winner(state);

    free(board);

    return 0;
}

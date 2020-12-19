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

    do {
        initialize_board(board);

        state = PLAYING;
        colorToMove = WHITE;
        settings = read_game_settings();

        while (state == PLAYING) {
            /* clearConsole(); */
            display_board(board);

            if (colorToMove == WHITE) currentPlayer = settings.white;
            else currentPlayer = settings.black;

            display_player_to_move(colorToMove);

            if (currentPlayer.type == HUMAN) currentMove = read_player_move(board, colorToMove, settings);
            else {
                int depth;
                if (currentPlayer.level == EASY) depth = EASY_DEPTH;
                else if (currentPlayer.level == MEDIUM) depth = MEDIUM_DEPTH;
                else depth = HARD_DEPTH;

                currentMove = best_move_minimax(board, colorToMove, depth);
            }

            apply_move(board, colorToMove, currentMove);

            colorToMove = get_opposite_color(colorToMove);
            state = compute_state(board, colorToMove);

            if (state != PLAYING) {
                display_board(board);
                display_winner(state);
            }
        }
    } while (does_user_want_new_game());

    free(board);

    return 0;
}

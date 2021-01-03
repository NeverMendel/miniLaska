/**
 * @file main.c
 * @brief Gioco miniLaska
 * @mainpage Gioco miniLaska
 * @section intro_sec Introduzione
 * Progetto di Introduzione alla Programmazione 2020/2021, gioco miniLaska
 * @section description Descrizione del gioco
 * Gioco miniLaska con le regole definite nel sito http://www.lasca.org/ e le seguenti variazioni:
 * 1. Limite di una pedina mangiata per mossa
 * 2. L'altezza massima delle torri è di 3, nel caso in cui ci siano pedine in eccesso verranno rimosse a partire dal basso
 */

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "utility.h"
#include "terminal.h"
#include "logic.h"

int main() {
    Board board = calloc(BOARD_SIZE, sizeof(Piece));
    GameState state;
    Color colorToMove;
    GameSettings settings;
    Move currentMove;
    Player currentPlayer;
    int turn;

    if (board == NULL) {
        printf("Error allocating the board in the memory");
        exit(EXIT_FAILURE);
    }

    do {
        initialize_board(board);

        state = PLAYING;
        colorToMove = WHITE;
        settings = read_game_settings();
        turn = 0;

        while (state == PLAYING) {
            turn++;
            if (settings.clearConsole) clearConsole();
            display_board(board);

            if (colorToMove == WHITE) currentPlayer = settings.white;
            else currentPlayer = settings.black;

            display_player_to_move(turn, colorToMove);
            if(turn > 1) display_last_move(currentMove);

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
                if (settings.clearConsole) clearConsole();
                display_board(board);
                display_winner(state);
            }
        }
    } while (does_user_want_new_game());

    free(board);

    return 0;
}

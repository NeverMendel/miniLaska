#ifndef MINILASKA_TERMINAL_H
#define MINILASKA_TERMINAL_H

#include "constants.h"

/**
 * Visualizza la scacchiera
 * @param board, scacchiera da venire visualizzata
 */
void display_board(struct Piece* board);

/**
 * Chiede le impostazioni del gioco all'utente tramite terminale
 * @return GameSettings, impostazioni
 */
struct GameSettings read_game_settings();

/**
 * Legge la mossa dell'utente da terminale
 * @return Mossa inserita dall'utente
 */
struct Move read_player_move();

/**
 * Stampa un messaggio di errore per aver fatto una mossa non corretta sul terminale
 */
void display_error_incorrect_move(struct Move move);

/**
 * Stampa il vincitore sul terminale
 * @param state, stato della scacchiera
 */
void display_winner(enum GameState state);

#endif //MINILASKA_TERMINAL_H

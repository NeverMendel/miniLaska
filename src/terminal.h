#ifndef MINILASKA_TERMINAL_H
#define MINILASKA_TERMINAL_H

#include "constants.h"
#include "utility.h"

/**
 * Visualizza la scacchiera
 * @param board, scacchiera da venire visualizzata
 */
void display_board(Piece* board);

/**
 * Chiede le impostazioni del gioco all'utente tramite terminale
 * @return GameSettings, impostazioni
 */
GameSettings read_game_settings();

/**
 * Legge la mossa dell'utente da terminale
 * @param board, scacchiera sulla quale deve venire effettuata la mossa
 * @param color, colore del giocatore che deve effettuare la mossa
 * @return Mossa inserita dall'utente
 */
Move read_player_move(Piece* board, Color color);

/**
 * Stampa un messaggio di errore per aver fatto una mossa non corretta sul terminale
 */
void display_error_incorrect_move(Move move);

/**
 * Stampa il vincitore sul terminale
 * @param state, stato della scacchiera
 */
void display_winner(GameState state);

#endif

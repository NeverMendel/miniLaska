/**
 * @file terminal.h
 * @brief Gestione dell'interfaccia grafica del gioco miniLaska attraversio il terminale
 */

#ifndef MINILASKA_TERMINAL_H
#define MINILASKA_TERMINAL_H

#include "constants.h"
#include "utility.h"

/**
 * Stampa la scacchiera sul terminale
 * @param board scacchiera da venire visualizzata
 */
void display_board(Board board);

/**
 * Stampa l'ultima mossa effettuata sul terminale
 * @param move mossa da stampare
 */
void display_last_move(Move move);

/**
 * Stampa il numero del turno e il colore del giocatore che deve giocare sul terminale
 * @param turn numero del turno
 * @param playerToMove colore del giocatore
 */
void display_player_to_move(int turn, Color playerToMove);

/**
 * Chiede le impostazioni del gioco all'utente tramite terminale
 * @return GameSettings impostazioni
 */
GameSettings read_game_settings();

/**
 * Legge la mossa dell'utente da terminale
 * @param board scacchiera sulla quale deve venire effettuata la mossa
 * @param color colore del giocatore che deve effettuare la mossa
 * @param settings impostazioni del gioco
 * @return Move Mossa inserita dall'utente
 */
Move read_player_move(Board board, Color color, GameSettings settings);

/**
 * Stampa il vincitore sul terminale
 * @param state stato della scacchiera
 */
void display_winner(GameState state);

/**
 * Chiede all'utente se vuole giocare una nuova partita
 * @return bool true se l'utente vuole giocare una nuova partita, falso altrimenti
 */
bool does_user_want_new_game();

#endif

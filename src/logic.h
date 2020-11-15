#ifndef MINILASKA_LOGIC_H
#define MINILASKA_LOGIC_H

#include "constants.h"

/**
 * Inizializza la schacchiera allo stato di inizio gioco
 * @param board, schacchiera da inizializzare
 */
void initialize_board(struct Piece* board);

/**
 * Calcola lo stato della scacchiera
 * @param board, scacchiera di cui calcolare lo stato
 * @return GameState, stato della scacchiera
 */
enum GameState compute_state(struct Piece* board);

/**
 * Calcola la mossa migliore utilizzando l'algoritmo mini-max
 * @param board, scacchiara su cui calcolare la mossa
 * @param depth, profondità del calcolo della mossa
 * @param colorToMove, colore del giocatore che deve muovere
 * @param settings, impostazioni del gioco con la difficoltà del computer
 * @return Move, mossa migliore che può venire giocata
 */
struct Move best_move_minimax(struct Piece* board, int depth, enum Color colorToMove, struct GameSettings settings);

/**
 * Applica la mossa sulla scacchiera se la mossa è valida
 * @param board, scacchiera sulla quale applicare la mossa
 * @param move, mossa da applicare
 * @return bool, vero se la mossa è valida, falsa altrimenti
 */
bool apply_move(struct Piece* board, struct Move move);

/**
 * Controlla se una mossa prevede di mangiare una pedina dell'avversario
 * @param board, scacchiera sulla quale applicare la mossa
 * @param move, mossa da controllare
 * @return bool, vero se la mossa prevede di mangiare una pedina dell'avversario, falso altrimenti
 */
bool does_move_eat(struct Piece* board, struct Move move);

/**
 * Restituisce un array con tutte le mosse che un determinato pezzo può eseguire
 * @param board, scacchiera sulla quale applicare la mossa
 * @param piecePos, posizione del pezzo di cui calcolare le mosse possibili
 * @return Move*, array di mosse che il pezzo può eseguire
 */
struct Move* get_possible_moves(struct Piece* board, struct Pos piecePos);

#endif //MINILASKA_LOGIC_H

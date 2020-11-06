#ifndef MINILASKA_LOGIC_H
#define MINILASKA_LOGIC_H

#include <stdbool.h>
#include "constants.h"

/**
 * Calcola lo stato della scacchiera
 * @param board, scacchiera di cui calcolare lo stato
 * @return GameState, stato della scacchiera
 */
enum GameState compute_state(struct Piece* board);

/**
 * Calcola la mossa migliore utilizzando l'algoritmo min-max
 * @param board, scacchiara su cui calcolare la mossa
 * @param depth, profondità del calcolo della mossa
 * @param whiteTurn, vero se è il turno del bianco, falso altrimenti
 * @return Move, mossa migliore che può venire giocata
 */
struct Move best_move_minimax(struct Piece* board, int depth, bool whiteTurn);

/**
 * Applica la mossa sulla scacchiera se la mossa è valida
 * @param board, scacchiera sulla quale applicare la mossa
 * @param move, mossa da applicare
 * @return bool, vero se la mossa è valida, falsa altrimenti
 */
bool apply_move(struct Piece* board, struct Move move);

#endif //MINILASKA_LOGIC_H

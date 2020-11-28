#ifndef MINILASKA_LOGIC_H
#define MINILASKA_LOGIC_H

#include "constants.h"
#include "cvector.h"
#include "utility.h"

/**
 * Calcola la posizione di una cella all'interno della matrice
 * @param c, indice della colonna
 * @param r, indice della riga
 * @return int, indice della matrice
 */
int get_index_from_coordinates(int c, int r);

/**
 * Calcola la posizione di una cella all'interno della matrice
 * @param pos, posizione della scacchiera
 * @return int, indice della matrice
 */
int get_index_from_pos(Pos pos);

/**
 * Inizializza la schacchiera allo stato di inizio gioco
 * @param board, schacchiera da inizializzare
 */
void initialize_board(Piece *board);

/**
 * Calcola lo stato della scacchiera
 * @param board, scacchiera di cui calcolare lo stato
 * @param colorToMove, colore del giocatore che deve muovere
 * @return GameState, stato della scacchiera
 */
GameState compute_state(Piece *board, Color colorToMove);

/**
 * Calcola la mossa migliore utilizzando l'algoritmo mini-max
 * @param board, scacchiara su cui calcolare la mossa
 * @param depth, profondità del calcolo della mossa
 * @param colorToMove, colore del giocatore che deve muovere
 * @param settings, impostazioni del gioco con la difficoltà del computer
 * @return Move, mossa migliore che può venire giocata
 */
Move best_move_minimax(Piece *board, int depth, Color colorToMove, GameSettings settings);

/**
 * Applica la mossa sulla scacchiera se la mossa è valida
 * @param board, scacchiera sulla quale applicare la mossa
 * @param colorToMove, colore del giocatore che deve muovere
 * @param move, mossa da applicare
 * @return bool, vero se la mossa è valida, falsa altrimenti
 */
bool apply_move(Piece *board, Color colorToMove, Move move);

/**
 * Controlla se una mossa è valida
 * @param board, scacchiera sulla quale applicare la mossa
 * @param move, mossa da controllare
 * @return bool, vero se la mossa è valida, falso altrimenti
 */
bool is_move_valid(Piece *board, Move move);

/**
 * Controlla se una posizione è valida, se è all'interno della scacchiera ed è una cella utilizzata nel gioco Lasca
 * @param pos, posizione dellla cella
 * @return bool, vero se la cella è valida, falso altrimenti
 */
bool is_pos_valid(Pos pos);

/**
 * Controlla se una mossa prevede di mangiare una pedina dell'avversario
 * @param board, scacchiera sulla quale applicare la mossa
 * @param move, mossa da controllare
 * @return bool, vero se la mossa prevede di mangiare una pedina dell'avversario, falso altrimenti
 */
bool does_move_eat(Piece *board, Move move);

/**
 * Restituisce un array con tutte le mosse che un determinato colore può effettuare
 * @param board, scacchiera sulla quale applicare la mossa
 * @param color, colore del giocatore di cui calcolare le mosse possibili
 * @return Move*, array di mosse che il colore può eseguire
 */
cvector_vector_type(Move) get_possible_moves_by_color(Piece *board, Color color);

/**
 * Restituisce un array con tutte le mosse che un determinato pezzo può effettuare
 * @param board, scacchiera sulla quale applicare la mossa
 * @param piecePos, posizione del pezzo di cui calcolare le mosse possibili
 * @return Move*, array di mosse che il pezzo può eseguire
 */
cvector_vector_type(Move) get_possible_moves_by_piece(Piece *board, Pos piecePos);

/**
 * Restituisce un array con tutte le posizioni delle pedine di un determinato colore
 * @param board, scacchiera sulla quale cercare le pedine
 * @param color, colore del giocatore di cui cercare le pedine
 * @return Pos*, array di posizioni
 */
cvector_vector_type(Pos) get_pieces_pos_by_color(Piece *board, Color color);

#endif

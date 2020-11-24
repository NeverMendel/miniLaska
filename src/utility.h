#ifndef MINILASKA_UTILITY_H
#define MINILASKA_UTILITY_H

#include "constants.h"

/**
 * Rappresenta il colore di un giocatore
 */
typedef enum {
    UNDEFINED,
    WHITE,
    BLACK
} Color;

/**
 * Rappresenta un pezzo sulla scacchiera
 */
typedef struct {
    /* 0 - colore in cima, 1 - colore in mezzo, 2 - colore in fondo. UNDEFINED se non c'è nessuna pedina */
    Color color[MAX_HEIGHT];
    bool promoted;
    int height;
} Piece;

/**
 * Rappresenta una posizione nella scacchiera
 */
typedef struct {
    int c;
    int r;
} Pos;

/**
 * Rappresenta una mossa
 */
typedef struct {
    Pos from;
    Pos to;
} Move;

/**
 * Rappresenta il tipo di giocatore, umano o computer
 */
typedef enum {
    HUMAN,
    COMPUTER
} PlayerType;

/**
 * Difficoltà del giocatore Computer
 */
typedef enum {
    EASY,
    MEDIUM,
    HARD
} ComputerLevel;

/**
 * Impostazioni del gioco, determina chi gioca
 */
typedef struct {
    PlayerType white;
    ComputerLevel whiteLevel;
    PlayerType black;
    ComputerLevel blackLevel;
} GameSettings;

/**
 * Stato del gioco
 */
typedef enum {
    PLAYING,
    DRAW,
    WHITE_WIN,
    BLACK_WIN
} GameState;

/**
 * Controlla se un pezzo è nullo, ovvero se non c'è nessun pezzo
 * @param piece, pezzo da controllare
 * @return bool, vero se il pezzo è nullo, falso altrimenti
 */
bool is_piece_null(Piece piece);

/**
 * Compara due Move e restituisce vero se sono uguali
 * @param a, prima Move
 * @param b, seconda Move
 * @return bool, vero se le due Move sono uguali, falso altrimenti
 */
bool is_move_equal(Move a, Move b);

/**
 * Compara due Pos e restituisce vero se sono uguali
 * @param a, prima Pos
 * @param b, seconda Pos
 * @return bool, vero se le due Pos sono uguali, falso altrimenti
 */
bool is_pos_equal(Pos a, Pos b);

/**
 * Compara due Color e restituisce vero se sono opposti, es. Bianco e Nero
 * @param a, primo Color
 * @param b, secondo Color
 * @return bool, vero se i due Color sono opposti, falso altrimenti
 */
bool is_opposite_color(Color a, Color b);

/**
 * Compara due Piece e resituisce vero se sono uguali
 * @param a, primo Piece
 * @param b, secondo Piece
 * @return bool, vero se i due Piece sono uguali, falso altrimenti
 */
bool is_piece_equal(Piece a, Piece b);

Pos initialize_pos(int c, int r);

Move initialize_move(Pos from, Pos to);

Piece initialize_piece(Color color0, Color color1, Color color2, bool promoted, int height);

#endif

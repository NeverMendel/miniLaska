#ifndef MINILASKA_CONSTANTS_H
#define MINILASKA_CONSTANTS_H

#define ROWS 7
#define COLUMNS 7
#define MAX_HEIGHT 3
#define MAX_PIECES_PER_COLOR 11

#include <stdbool.h>

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
    // 0 - colore in cima, 1 - colore in mezzo, 2 - colore in fondo. UNDEFINED se non c'è nessuna pedina
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

#endif //MINILASKA_CONSTANTS_H

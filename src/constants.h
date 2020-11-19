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
enum Color{
    UNDEFINED,
    WHITE,
    BLACK
};

/**
 * Rappresenta un pezzo sulla scacchiera
 */
struct Piece{
    // 0 - colore in cima, 1 - colore in mezzo, 2 - colore in fondo. UNDEFINED se non c'è nessuna pedina
    enum Color color[MAX_HEIGHT];
    bool promoted;
    int height;
};

/**
 * Rappresenta una posizione nella scacchiera
 */
struct Pos{
    int c;
    int r;
};

/**
 * Rappresenta una mossa
 */
struct Move{
    struct Pos from;
    struct Pos to;
};

/**
 * Rappresenta il tipo di giocatore, umano o computer
 */
enum PlayerType{
    HUMAN,
    COMPUTER
};

/**
 * Difficoltà del giocatore Computer
 */
enum ComputerLevel{
    EASY,
    MEDIUM,
    HARD
};

/**
 * Impostazioni del gioco, determina chi gioca
 */
struct GameSettings{
    enum PlayerType white;
    enum ComputerLevel whiteLevel;
    enum PlayerType black;
    enum ComputerLevel blackLevel;
};

/**
 * Stato del gioco
 */
enum GameState{
    PLAYING,
    DRAW,
    WHITE_WIN,
    BLACK_WIN
};

#endif //MINILASKA_CONSTANTS_H

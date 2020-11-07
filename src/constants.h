#ifndef MINILASKA_CONSTANTS_H
#define MINILASKA_CONSTANTS_H

#define ROWS 7
#define COLUMNS 7

#include <stdbool.h>

/**
 * Rappresenta un pezzo sulla scacchiera
 */
struct Piece{
    bool white;
    bool promoted;
    int height;
};

/**
 * Rappresenta una posizione nella scacchiera
 */
struct Pos{
    int x;
    int y;
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

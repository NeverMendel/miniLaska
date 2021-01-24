/**
 * @file constants.h
 * @brief Dichiarazione delle costanti utilizzate nel gioco
 */

#ifndef MINILASKA_CONSTANTS_H
#define MINILASKA_CONSTANTS_H

#define ROWS (7)
#define COLUMNS (7)
#define BOARD_SIZE (25)
#define MAX_HEIGHT (3)

#define WHITE_SPRITE 'w'
#define BLACK_SPRITE 'b'

#define EASY_DEPTH (2)
#define MEDIUM_DEPTH (4)
#define HARD_DEPTH (6)

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define clearConsole() if(system("clear")) printf("Error while clearing the screen")
#endif
#if defined(_WIN32) || defined(_WIN64)
#define clearConsole() if(system("cls")) printf("Error while clearing the screen")
#endif

#ifndef max
#define max(a, b) ((a)>(b)?(a):(b))
#endif
#ifndef min
#define min(a, b) ((a)<(b)?(a):(b))
#endif

#define bool int
#define true 1
#define false 0

#endif

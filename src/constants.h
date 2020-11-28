#ifndef MINILASKA_CONSTANTS_H
#define MINILASKA_CONSTANTS_H

#define ROWS 7
#define COLUMNS 7
#define BOARD_SIZE ROWS*COLUMNS
#define MAX_HEIGHT 3
#define MAX_PIECES_PER_COLOR 11

#define DEBUG

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#define clearConsole() system("clear");
#endif
#if defined(_WIN32) || defined(_WIN64)
#define clearConsole() system("cls");
#endif

#define bool int
#define true 1
#define false 0

#endif

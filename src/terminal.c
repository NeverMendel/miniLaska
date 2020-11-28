#include "terminal.h"
#include "logic.h"
#include <stdio.h>

void display_board(Piece *board) {
    int c, r, i, height, currentChar;
    Piece piece;
    for (r = ROWS - 1; r >= 0; r--) {
        for(height = 2; height >= 0; height--){
            if (height == 1)
                printf("%d | ", r + 1);
            else
                printf("  | ");
        for (c = 0; c < COLUMNS ; c++) {
            if (is_pos_valid(initialize_pos(c, r))) {
                piece = board[get_index_from_coordinates(c, r)];
                for (i = 0; i < 3; i++) {
                    switch (piece.color[height]) {
                        case WHITE:
                            printf("%c", 'w' + (piece.promoted ? -32 : 0));
                            break;
                        case BLACK:
                            printf("%c", 'b' + (piece.promoted ? -32 : 0));
                            break;
                        case UNDEFINED:
                            printf(" ");
                            break;
                    }
                }
            } else {
                for (i = 0; i < 3; i++)
                    printf("*");
            }
            printf(" ");
        }
            printf("\n");
        }
    }
    printf("   ");
    for(i = 0; i < 28; i++)
        printf("-");
    printf("\n");
    printf("  ");
    for(currentChar = 'a'; currentChar <= 'g'; currentChar++)
        printf("   %c", currentChar);
    printf("\n");
}

GameSettings read_game_settings() {
    GameSettings settings;
    char input = 0;

    /* white */
    while (input != 'h' && input != 'c') {
        printf("Select the type of the white player (human or computer) by typing h or c\n");
        scanf(" %c", &input);
    }
    if (input == 'h') settings.white = HUMAN;
    else {
        settings.white = COMPUTER;
        while (input < '1' || input > '3') {
            printf("Select the level of the computer playing with white \n  1 - Easy\n  2 - Medium\n  3 - Hard\n");
            scanf(" %c", &input);
        }
        settings.whiteLevel = input - '1';
    }

    input = 0;
    /* black */
    while (input != 'h' && input != 'c') {
        printf("Select the type of the black player (human or computer) by typing h or c\n");
        scanf(" %c", &input);
    }
    if (input == 'h') settings.black = HUMAN;
    else {
        settings.black = COMPUTER;
        while (input < '1' || input > '3') {
            printf("Select the level of the computer playing with black \n  1 - Easy\n  2 - Medium\n  3 - Hard\n");
            scanf(" %c", &input);
        }
        settings.blackLevel = input - '1';
    }
    return settings;
}

Move read_player_move(Piece *board, Color color) {
    /* Visualizza tutte le mosse che il giocatore può giocare e fa selezionare all'utente una di quelle
         Es: 1 - a3-b4
             2 - c3-b4
             etc... */
    int i, input = -1;
    cvector_vector_type(Move) possible_moves = get_possible_moves_by_color(board, color);

    if (color == BLACK) {
        printf("Black turn\n");
    } else {
        printf("White turn\n");
    }

    printf("Possible moves:\n");

    for (i = 0; i < cvector_size(possible_moves); i++) {
        printf("%d - %c%d-%c%d\n", i + 1, possible_moves[i].from.c + 'a', possible_moves[i].from.r + 1,
               possible_moves[i].to.c + 'a', possible_moves[i].to.r + 1);
    }

    while (input < 1 || input > cvector_size(possible_moves)) {
        printf("Type the number of the selected move:\n");
        scanf(" %d", &input);
    }

    return possible_moves[input - 1];
}

void display_winner(GameState state) {
    switch (state) {
        case DRAW:
            printf("Draw");
            break;
        case WHITE_WIN:
            printf("The winner is white");
            break;
        case BLACK_WIN:
            printf("The winner is black");
            break;
        default:
            printf("Invalid state");
            break;
    };
}

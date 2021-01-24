#include "terminal.h"
#include "logic.h"
#include <stdio.h>

void display_board(Board board) {
    int c, r, i, height, currentChar;
    Piece piece;
    for (r = ROWS - 1; r >= 0; r--) {
        for (height = MAX_HEIGHT - 1; height >= 0; height--) {
            if (height == 1)
                printf("%d | ", r + 1);
            else
                printf("  | ");
            for (c = 0; c < COLUMNS; c++) {
                if (is_pos_valid(initialize_pos(c, r))) {
                    piece = board[get_index_from_coordinates(c, r)];
                    for (i = 0; i < 3; i++) {
                        int diff = piece.height - height - 1;
                        if (diff < 0)
                            printf(" ");
                        else if (piece.color[diff] == WHITE)
                            printf("%c", WHITE_SPRITE + (piece.promoted ? -32 : 0));
                        else
                            printf("%c", BLACK_SPRITE + (piece.promoted ? -32 : 0));
                        if (i != 2) printf(" ");
                    }
                } else {
                    for (i = 0; i < 5; i++) printf("#");
                }
                printf(" ");
            }
            printf("\n");
        }
    }
    printf("   ");
    for (i = 0; i < 42; i++) printf("-");
    printf("\n");
    printf(" ");
    for (currentChar = 'a'; currentChar <= 'g'; currentChar++) printf("     %c", currentChar);
    printf("\n");
}

void display_last_move(Move move) {
    printf("Last move: %c%d-%c%d\n", move.from.c + 'a', move.from.r + 1, move.to.c + 'a', move.to.r + 1);
}

void display_player_to_move(int turn, Color playerToMove) {
    printf("Turn %d - %s to move\n", turn, (playerToMove == WHITE ? "White" : "Black"));
}

GameSettings read_game_settings() {
    GameSettings settings;
    char input = 0;

    /* Selezione della modalità di gioco, giocatore vs giocatore oppure giocatore vs computer */
    while (input != '1' && input != '2') {
        printf("Select the game mode:\n 1 - Player VS Player\n 2 - Player VS Computer\n");
        if (scanf("%c", &input) != 1) printf("Invalid value\n");
        while (getchar() != '\n');
    }
    if (input == '1') {
        settings.white.type = HUMAN;
        settings.black.type = HUMAN;
    } else {
        Player *computerPlayer;
        input = 0;
        while (input != '1' && input != '2') {
            printf("Do you want to play with white or black pieces?\n 1 - White\n 2 - Black\n");
            if (scanf("%c", &input) != 1) printf("Invalid value\n");
            while (getchar() != '\n');
        }
        if (input == '1') {
            settings.white.type = HUMAN;
            computerPlayer = &settings.black;
        } else {
            settings.black.type = HUMAN;
            computerPlayer = &settings.white;
        }
        input = 0;
        while (input < '1' || input > '3') {
            printf("Select the level of the computer \n  1 - Easy\n  2 - Medium\n  3 - Hard\n");
            if (scanf("%c", &input) != 1) printf("Invalid value\n");
            while (getchar() != '\n');
        }
        computerPlayer->level = input - '1';
    }

    /* Chiede all'utente se abilitare gli aiuti */
    settings.helpAllowed = false;
    while (input != 'Y' && input != 'y' && input != 'N' && input != 'n') {
        printf("Allow hints [Y/N]: ");
        if (scanf(" %c", &input) != 1) printf("Invalid value\n");
        while (getchar() != '\n');
    }
    if (input == 'Y' || input == 'y') settings.helpAllowed = true;

    input = 0;
    settings.clearConsole = false;
    /* Chiede all'utente se vuole che il terminale venga pulito ad ogni turno */
    while (input != 'Y' && input != 'y' && input != 'N' && input != 'n') {
        printf("Clear console after every move [Y/N]: ");
        if (scanf("%c", &input) != 1) printf("Invalid value\n");
        while (getchar() != '\n');
    }
    if (input == 'Y' || input == 'y') settings.clearConsole = true;

    return settings;
}

Move read_player_move(Board board, Color color, GameSettings settings) {
    /* Visualizza tutte le mosse che il giocatore può giocare e fa selezionare all'utente una di quelle
         Es: 1 - a3-b4
             2 - c3-b4
             etc... */
    int i, input = -1;
    cvector_vector_type(Move) possible_moves = get_possible_moves_by_color(board, color);
    Move move;

    printf("Possible moves:\n");

    if (settings.helpAllowed) {
        printf("0 - Hint\n");
    }

    for (i = 0; i < cvector_size(possible_moves); i++) {
        printf("%d - %c%d-%c%d\n", i + 1, possible_moves[i].from.c + 'a', possible_moves[i].from.r + 1,
               possible_moves[i].to.c + 'a', possible_moves[i].to.r + 1);
    }

    while (input < 1 || input > cvector_size(possible_moves)) {
        printf("Type the number of the selected move: ");
        if (scanf("%d", &input) != 1) printf("Invalid value\n");
        while (getchar() != '\n');
        if (settings.helpAllowed && input == 0) {
            Move bestMove = best_move_minimax(board, color, 8);
            printf("Best move: %c%d-%c%d\n", bestMove.from.c + 'a', bestMove.from.r + 1, bestMove.to.c + 'a',
                   bestMove.to.r + 1);
        }
    }

    move = possible_moves[input - 1];
    cvector_free(possible_moves);
    return move;
}

void display_winner(GameState state) {
    switch (state) {
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
    printf("\n");
}

bool does_user_want_new_game() {
    char input;
    printf("The game has ended. Do you want to play another match? [y/N]");
    if (scanf("%c", &input) != 1) printf("Invalid value\n");
    while (getchar() != '\n');

    return input == 'y' || input == 'Y';
}

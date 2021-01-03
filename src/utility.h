/**
 * @file utility.h
 * @brief Dichiarazione enum, struts e funzioni di supporto
 */

#ifndef MINILASKA_UTILITY_H
#define MINILASKA_UTILITY_H

#include "constants.h"
#include "cvector.h"

/**
 * Rappresenta il colore di un giocatore
 */
typedef enum {
    UNDEFINED = 0,
    WHITE = 1,
    BLACK = 2
} Color;

/**
 * Rappresenta il tipo di giocatore, umano o computer
 */
typedef enum {
    HUMAN = 0,
    COMPUTER = 1
} PlayerType;

/**
 * Stato del gioco
 */
typedef enum {
    PLAYING = 0,
    WHITE_WIN = 1,
    BLACK_WIN = 2
} GameState;

/**
 * Difficoltà del giocatore Computer
 */
typedef enum {
    EASY = 0,
    MEDIUM = 1,
    HARD = 2
} ComputerLevel;

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
 * Rappresenta un pezzo sulla scacchiera
 */
typedef struct {
    /** Colore della peina. 0 - colore in cima, 1 - colore in mezzo, 2 - colore in fondo. UNDEFINED se non c'è nessuna pedina */
    Color color[MAX_HEIGHT];
    /** Vero se la pedina è promossa, falso altrimenti */
    bool promoted;
    /** Altezza della pedina */
    int height;
} Piece;

#define Board Piece*

/**
 * Rappresenta un giocatore
 */
typedef struct {
    /** Tipo del giocatore */
    PlayerType type;
    /** Livello del giocatore nel caso fosse di tipo computer */
    ComputerLevel level;
} Player;

/**
 * Impostazioni del gioco
 */
typedef struct {
    /** Giocatore che gioca con le pedine bianche */
    Player white;
    /** Giocatore che gioca con le pedine nere */
    Player black;
    /** Vero se gli aiuti sono ammessi, falso altrimenti */
    bool helpAllowed;
    /** Vero se l'utente vuole che il terminale venga pulito dopo ogni mossa */
    bool clearConsole;
} GameSettings;

/**
 * Controlla se un pezzo è nullo, ovvero se non c'è nessun pezzo
 * @param piece pezzo da controllare
 * @return bool vero se il pezzo è nullo, falso altrimenti
 */
bool is_piece_null(Piece piece);

/**
 * Compara due Move e restituisce vero se sono uguali
 * @param a prima Move
 * @param b seconda Move
 * @return bool vero se le due Move sono uguali, falso altrimenti
 */
bool is_move_equal(Move a, Move b);

/**
 * Compara due Pos e restituisce vero se sono uguali
 * @param a prima Pos
 * @param b seconda Pos
 * @return bool vero se le due Pos sono uguali, falso altrimenti
 */
bool is_pos_equal(Pos a, Pos b);

/**
 * Compara due Color e restituisce vero se sono opposti, es. Bianco e Nero
 * @param a primo Color
 * @param b secondo Color
 * @return bool vero se i due Color sono opposti, falso altrimenti
 */
bool is_opposite_color(Color a, Color b);

/**
 * Compara due Piece e resituisce vero se sono uguali
 * @param a primo Piece
 * @param b secondo Piece
 * @return bool vero se i due Piece sono uguali, falso altrimenti
 */
bool is_piece_equal(Piece a, Piece b);

/**
 * Inizializza una struct Pos con la colonna e riga
 * @param c colonna
 * @param r riga
 * @return Pos struct Pos inizializzata
 */
Pos initialize_pos(int c, int r);

/**
 * Inizializza una struct Move
 * @param from posizione di inizio della mossa
 * @param to posizione di fine della mossa
 * @return Move struct Move inizializzata
 */
Move initialize_move(Pos from, Pos to);

/**
 * Inizializza una struct Piece
 * @param color0 colore del pezzo in cima alla pedina
 * @param color1 colore del pezzo in mezzo alla pedina
 * @param color2 colore del pezzo alla base della pedina
 * @param promoted vero se la pedina è promossa, falso altrimenti
 * @param height altezza della pedina
 * @return Piece struct Piece inizializzato
 */
Piece initialize_piece(Color color0, Color color1, Color color2, bool promoted, int height);

/**
 * Inizializza un Piece vuoto
 * @return Piece struct Piece vuota
 */
Piece initialize_null_piece();

/**
 * Dato un colore di un giocatore restituisce l'opposto
 * @param color colore del quale si vuole l'opposto
 * @return Color colore opposto
 */
Color get_opposite_color(Color color);

/**
 * Esegue una deep-copy della scacchiera
 * @param board scacchiera da copiare
 * @return Piece* - copia della scacchiera
 */
Board clone_board(Board board);

/**
 * Restituisce un array con tutte le posizioni delle pedine di un determinato colore
 * @param board scacchiera sulla quale cercare le pedine
 * @param color colore del giocatore di cui cercare le pedine
 * @return Pos*, array di posizioni
 */
cvector_vector_type(Pos) get_pieces_pos_by_color(Board board, Color color);

/**
 * Conta i pezzi che ci sono nella scacchiera di un determinato colore
 * @param board scacchiera sulla quale contare i pezzi
 * @param color colore dei pezzi da contare
 * @return int, numero di pezzi del colore dato
 */
int count_pieces(Board board, Color color);

#endif

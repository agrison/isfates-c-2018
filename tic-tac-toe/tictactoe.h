#ifndef TICTACTOE_H
#define TICTACTOE_H

// type custom permettant de représenter
// l'état d'une case du morpion
typedef enum
{
    EMPTY = 0,
    PLAYER1,
    PLAYER2
} square_state_t;

typedef enum
{
    NOT_FINISHED,
    DRAW,
    PLAYER1_WON,
    PLAYER2_WON
} game_status;

void draw_game(square_state_t *game_state);

int read_choice(int player, square_state_t *game_state);

void update_game(int current_player, int choice, square_state_t *game_state);

void next_player(int *player);

game_status is_finished(square_state_t *game_state);

void show_result(game_status status);

#endif
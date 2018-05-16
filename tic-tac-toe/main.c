#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <readline/readline.h>
#include "tictactoe.h"

square_state_t STATE[] = {EMPTY, EMPTY, EMPTY,
                          EMPTY, EMPTY, EMPTY,
                          EMPTY, EMPTY, EMPTY};

int current_player = 1;
game_status status = NOT_FINISHED; // etat de base du jeu
bool wants_to_play = true;

void run_the_game()
{
    do
    {
        draw_game(STATE);
        int choice = read_choice(current_player, STATE);
        update_game(current_player, choice, STATE);
        next_player(&current_player);
        status = is_finished(STATE);
    } while (status == NOT_FINISHED);

    draw_game(STATE);
    show_result(status);
}

int main(int argc, char **argv)
{
    while (wants_to_play)
    {
        run_the_game();
        char *input = readline("Do you still want to play ? [Y/N] ");
        int size = strlen(input);
        if (size == 0 || (size > 0 && input[0] == 'Y'))
        {
            // reinitialiser le jeu
            current_player = 1;
            for (int i = 0; i < 9; ++i)
                STATE[i] = EMPTY;
        }
        else
        {
            wants_to_play = false;
        }
    }

    return 0;
}

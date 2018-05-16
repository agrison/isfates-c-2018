#include <stdio.h>
#include <stdlib.h> // pour avoir system()
#include <readline/readline.h>
#include "tictactoe.h"
#include "grid.h"
#include <stdbool.h>

bool is_correct_choice(int choice, square_state_t *game_state)
{
    // vérifier que choice est bien compris entre 1 et 9
    if (choice < 1 || choice > 9)
        return false;

    // vérifier que l'état de la case est bien à EMPTY
    return game_state[choice - 1] == EMPTY; // 2 symboles egal
}

int read_choice(int player, square_state_t *game_state)
{
    // créer la chaine de caractère a affiché utilisant le player
    char text[100];
    sprintf(text,
            "%sPlayer %d%s, please select a square: ",
            (player == 1 ? COLOR1 : COLOR2), // color, il y a bien deux égal
            player,
            NORMAL // remet la couleur à zéro
    );

    int choice;
    do
    {
        char *input = readline(text);
        choice = atoi(input);
        free(input); // toujours libérer la mémoire de readline
    } while (!is_correct_choice(choice, game_state));
    return choice;
}

char *square_state(square_state_t state)
{
    if (state == PLAYER1)
        return COLOR1 "X" NORMAL;
    else if (state == PLAYER2)
        return COLOR2 "O" NORMAL;
    else            // EMPTY
        return " "; // espace
}

void draw_game(square_state_t *game_state)
{
    system("clear"); // system("cls") sur windows.
    printf(GRID,
           square_state(game_state[0]),
           square_state(game_state[1]),
           square_state(game_state[2]),
           square_state(game_state[3]),
           square_state(game_state[4]),
           square_state(game_state[5]),
           square_state(game_state[6]),
           square_state(game_state[7]),
           square_state(game_state[8]));
}

void update_game(int player, int choice, square_state_t *game_state)
{
    game_state[choice - 1] = player == 1 ? PLAYER1 : PLAYER2;
}

void next_player(int *player)
{
    *player = *player == 1 ? 2 : 1;
}

game_status is_finished(square_state_t *s)
{
    // premiere ligne
    if (s[0] == s[1] && s[0] == s[2] && s[0] != EMPTY)
        return s[0] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    // deuxieme ligne
    if (s[3] == s[4] && s[3] == s[5] && s[3] != EMPTY)
        return s[3] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    // troisieme ligne
    if (s[6] == s[7] && s[6] == s[8] && s[6] != EMPTY)
        return s[6] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    // premiere colonne
    if (s[0] == s[3] && s[0] == s[6] && s[0] != EMPTY)
        return s[0] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    // deuxieme colonne
    if (s[1] == s[3] && s[1] == s[7] && s[1] != EMPTY)
        return s[1] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    // troisieme colonne
    if (s[2] == s[5] && s[2] == s[8] && s[2] != EMPTY)
        return s[2] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    // premiere diagonale
    if (s[0] == s[4] && s[0] == s[8] && s[0] != EMPTY)
        return s[0] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;
    // deuxieme diagonale
    if (s[2] == s[4] && s[2] == s[6] && s[2] != EMPTY)
        return s[2] == PLAYER1 ? PLAYER1_WON : PLAYER2_WON;

    // recherche si le jeu est nul
    for (int i = 0; i < 9; ++i)
    {
        if (s[i] == EMPTY)
            return NOT_FINISHED;
    }

    return DRAW;
}

void show_result(game_status status)
{
    if (status == PLAYER1_WON)
        printf(COLOR1 "Congratulations Player 1 \n" NORMAL);
    else if (status == PLAYER2_WON)
        printf(COLOR2 "Congratulations Player 2 \n" NORMAL);
    else
        printf("This is a draw!\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

int main(int argc, char **argv)
{
    char **names = NULL;

    printf("Saisissez autant de prénoms que vous voulez.\nTerminez par un prénom vide pour quitter.\n\n");
    names = malloc(1 * sizeof(char *));
    int number = 1;
    for (;; number++)
    {
        // number - 1 car les tableaux commencent à l'indice 0
        names[number - 1] = readline("Prénom: ");
        if (strlen(names[number - 1]) == 0)
        {
            break;
        }
        // ici number + 1 car on ajoute un car on veut allouer
        // de la mémoire pour un prochain prénom
        names = realloc(names, (number + 1) * sizeof(char *));
    }

    for (int i = 0; i < number; ++i)
    {
        if (strlen(names[i]))
        {
            printf("Vous avez saisi: %s\n", names[i]);
        }
        // ne pas oublier de libérer chaque chaîne alloué par readline()
        free(names[i]);
    }

    // ne pas oublier de libérer la mémoire allouée plus tot
    free(names);

    return 0;
}

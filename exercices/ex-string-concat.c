#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

int main(int argc, char **argv)
{
    // demander à l'utilisateur une premiere chaine
    char *text1 = readline("Tapez une phrase svp: ");

    // demander à l'utilisateur une deuxième chaine
    char *text2 = readline("Tapez une autre phrase svp: ");

    // concaténer les chaines
    char result[100];
    strlcat(result, text1, sizeof(result));
    strlcat(result, text2, sizeof(result));

    // aficher la chaine résultat
    printf("Résultat: %s\n", result);

    // afficher sa taille
    printf("Taille: %d\n", strlen(result));

    return 0;
}


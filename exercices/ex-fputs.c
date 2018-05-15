#include <stdio.h>
#include <string.h>
#include <errno.h>

void rot13(char *str)
{
    int size = strlen(str);
    for (int i = 0; i < size; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = (str[i] - 'a' + 13) % 26 + 'a';
        }
    }
}

int main(int argc, char **argv)
{
    // ouvrir un fichier "rot13.txt" en mode "r"
    FILE *f = fopen("rot13.txt", "r");
    // si erreur, afficher l'erreur
    if (f == NULL)
    {
        printf("Erreur: %s\n", strerror(errno));
        return 1;
    }

    // ouvrir un fichier "rot13-2.txt" en mode "w"
    FILE *f2 = fopen("rot13-2.txt", "w");

    char content[100] = "";
    // parcourir le fichier ligne par ligne
    while (fgets(content, 100, f) != NULL)
    {
        rot13(content);
        // ecrire dans le fichier rot13-2.txt
        fputs(content, f2);
    }

    // fermer les fichiers
    fclose(f);
    fclose(f2);

    return 0;
}


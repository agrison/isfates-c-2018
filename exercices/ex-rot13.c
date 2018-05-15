#include <stdio.h>
#include <string.h>

void rot13(char *str)
{
    int size = strlen(str);
    for (int i = 0; i < size; ++i)
    {
        str[i] = (str[i] - 'a' + 13) % 26 + 'a';
    }
}

void rot13_2(char *str)
{
    while (*str)
    {
        *str = (*str - 'a' + 13) % 26 + 'a';
        str++;
    }
}

// gcc -o ex4 ex4.c
int main(int argc, char **argv)
{
    char str[] = "coucou";
    rot13(str);
    printf("%s\n", str);
    rot13_2(str);
    printf("%s\n", str);

    return 0;
}


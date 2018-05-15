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

// gcc -o ex4 ex4.c
int main(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        printf("argv[%d] -> %-10s", i, argv[i]);
        rot13(argv[i]);
        printf(" -> %-10s\n", argv[i]);
    }

    return 0;
}


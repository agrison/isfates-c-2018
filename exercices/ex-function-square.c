#include <stdio.h>

int square(int num)
{
    return num * num;
}

// gcc -o ex3 ex3.c
int main(int argc, char **argv)
{
    int sq = square(10);
    printf("%d\n", sq);

    return 0;
}


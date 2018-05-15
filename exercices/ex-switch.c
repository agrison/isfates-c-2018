#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i = 50;

    switch (i)
    {
    case 50:
        printf("C'est 50\n");
        break;
    case 5:
        printf("C'est 5\n");
        break;
    default:
        printf("Je ne sais pas\n");
        break;
    }

    return 0;
}


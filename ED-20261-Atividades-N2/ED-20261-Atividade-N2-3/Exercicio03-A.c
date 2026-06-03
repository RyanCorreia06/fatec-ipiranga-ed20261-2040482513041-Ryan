//RA: 2040482513041 - Ryan Correia Ferreira
#include <stdio.h>
void hanoi(int n, char origem, char destino, char auxiliar)
{
    if(n == 1)
    {
        printf("%c -> %c\n", origem, destino);
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino);

    printf("%c -> %c\n", origem, destino);

    hanoi(n - 1, auxiliar, destino, origem);
}

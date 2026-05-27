//RA:2040482513041 - Ryan Correia Ferreira

#include <stdio.h>

void trocar (int *a, int *b){

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;   
} 
int main()
{
    int x=10;
    int y=5;
    
    printf("ANTES\n valor: x=%d | y=%d\n endereço x=%p | y=%p", x, y, &x, &y);
    trocar(&x,&y);
    printf("\nDEPOIS\n valor: x=%d | y=%d\n endereço x=%p | y=%p", x, y, &x, &y);

    return 0;
}

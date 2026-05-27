//RA: 2040482513041 - Ryan Correia Ferreira
#include <stdio.h>
int movimentos = 0;
void hanoi(int n, char origem, char destino, char auxiliar, int nivel){
    if(n==1){
        for(int i = 0; i < nivel; i++){
            printf("");
        }
        printf("%c->%c\n", origem, destino);
       
        movimentos++;
        return;
        
    }
    hanoi(n - 1,origem,auxiliar,destino,nivel+1);
    for(int i = 0; i< nivel; i++){
        printf(" ");
}
        printf("%c->%c\n", origem, destino);
        movimentos++;
        
        hanoi(n-1,auxiliar,destino,origem,nivel+1);
}


int main()
{
    int n = 3;
    hanoi(n, 'A', 'C', 'B', 0);
    
    printf("\nMovimentos: %d\n", movimentos);
    
    return 0;
}


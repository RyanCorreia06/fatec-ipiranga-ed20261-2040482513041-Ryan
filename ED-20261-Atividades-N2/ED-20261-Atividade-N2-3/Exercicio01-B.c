//RA:2040482513041 - Ryan Correia Ferreira
#include <stdio.h>

int main()
{
  int v[] = {10, 20, 30, 40, 50 };
  int *begin = v;// begin recebe o endereço do primeiro elemento do vetor
  int *end = v + 4;// end recebe o endereço do último elemento do vetor
  
  while (begin < end)
 {
        int aux = *begin;// *begin acessa o valor armazenado no endereço apontado
        *begin = *end; // copia o valor apontado por end para a posição apontada por begin 
        *end = aux;// o valor do último elemento do vetor é substituído pelo valor que estava no begin
        begin++;
        end--;
}
    for( int i = 0; i<5; i++){
        printf(" {%d}", *(v + i));
    }
    return 0;
}

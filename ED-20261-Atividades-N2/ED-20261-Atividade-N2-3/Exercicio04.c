//RA: 2040482513041 - Ryan Correia Ferreira
#include <stdio.h>

int chamadasBusca = 0;
int chamadasPotencia = 0;
int buscaBinaria(int *vet, int inicio,int fim, int alvo)
{
    chamadasBusca++;
    if(inicio > fim)
    {
        return -1;
    }

    int meio = (inicio + fim) / 2;
    if(*(vet + meio) == alvo)
    {
        return meio;
    }
    if(alvo < *(vet + meio))
    {
        return buscaBinaria(vet, inicio, meio - 1,  alvo);
    }
    return buscaBinaria(vet,
   meio + 1,fim,alvo);
}

long long potenciaRapida(long long base,
                         int exp)
{
    chamadasPotencia++;

    // caso base
    if(exp == 0)
    {
        return 1;
    }

    if(exp % 2 == 0)
    {
        long long metade =
            potenciaRapida(base, exp / 2);

        return metade * metade;
    }
    return base *
           potenciaRapida(base, exp - 1);
}

int main()
{
    int dados[] =
    {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};

    int tamanho = 10;

    int buscas[] = {23, 91, 2};

    printf("=== BUSCA BINARIA ===\n\n");

    for(int i = 0; i < 3; i++)
    {
        chamadasBusca = 0;

        int resultado =
            buscaBinaria(dados,
                         0,
                         tamanho - 1,
                         buscas[i]);

        printf("Alvo: %d\n", buscas[i]);

        printf("Indice: %d\n", resultado);

        printf("Chamadas recursivas: %d\n\n",
               chamadasBusca);
    }

    printf("=== POTENCIACAO RAPIDA ===\n\n");

    int expoentes[] = {10, 7, 12};

    for(int i = 0; i < 3; i++)
    {
        chamadasPotencia = 0;

        long long resultado =
            potenciaRapida(2,
                           expoentes[i]);

        printf("2^%d = %lld\n",
               expoentes[i],
               resultado);

        printf("Chamadas recursivas: %d\n\n",
               chamadasPotencia);
    }

    return 0;
}

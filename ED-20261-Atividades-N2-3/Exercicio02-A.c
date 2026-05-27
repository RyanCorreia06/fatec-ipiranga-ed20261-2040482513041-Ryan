//RA:2040482513041 - Ryan Correia Ferreira
#include <stdio.h>
float calcularMedia(float *vet, int n){
    float soma = 0;
    float *ptr = vet;
    for (int i=0; i<n;i++){
        soma += *ptr;
        ptr++;
    }
    return soma/n;
}
void encontrarExtremos(float *vet, int n, float *maior, float *menor){
    float *ptr = vet;
    *maior = *ptr;
    *menor = *ptr;
    ptr++;
    for(int i = 1; i < n; i++){
        if(*ptr > *maior){
            *maior = *ptr;
        }
        if(*ptr < *menor){
            *menor = *ptr;
        }
        ptr++;
    }
}

void normalizar (float *vet, int n){
    float maior, menor;
    encontrarExtremos(vet, n, &maior, &menor);
    float *ptr = vet;
    for(int i = 0; i < n; i++){
        *ptr = *ptr/maior;
        ptr++;
    }
}
void imprimirVetor(float *vet, int n, const char *titulo){
    printf("\n%s\n", titulo);
    float *ptr = vet;
    for (int i = 0; i< n; i ++){
        printf("%.2f", *ptr);
        ptr++;
    }
}

int main()
{
    float notas[] = {6.5f, 5.2f, 7.5f, 2.6f , 8.4f };
    int n = 5;
    
    float media;
    float maior;
    float menor;
    
    imprimirVetor(notas, n, "Vetor original:");
    media = calcularMedia(notas, n);
    encontrarExtremos(notas, n, &maior, &menor);
    
    printf ("\nMedia: %.2f\n", media);
    printf("maior valor : %.2f\n", maior);
    printf("menor valor: %.2f\n", menor);
    
    normalizar(notas, n);
    
    imprimirVetor( notas, n, "vetor normalizado");
    

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "MINHABIB.h"

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL) return;
    if (raiz->esq != NULL || raiz->dir != NULL) {
        printf("%d ", raiz->valor); 
    }
    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL) return;
    if (raiz->esq == NULL && raiz->dir == NULL) {
        printf("%d ", raiz->valor);
    }
    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

void imprimir_niveis(No* raiz, int nivel_atual) {
    if (raiz == NULL) return;
    printf("Nivel: %d | Valor: %d\n", nivel_atual, raiz->valor);
    imprimir_niveis(raiz->esq, nivel_atual + 1);
    imprimir_niveis(raiz->dir, nivel_atual + 1);
}
int calcular_altura(No* no) {
    if (no == NULL) return -1;
    int AltEsq = calcular_altura(no->esq);
    int AltDir = calcular_altura(no->dir);
    return (AltEsq > AltDir ? AltEsq : AltDir) + 1;
}
int calcular_profundidade(No* raiz, int valors, int profundidade) {
    if (raiz == NULL) return -1;
    if (raiz->valor == valors) return profundidade;

    int esquerda = calcular_profundidade(raiz->esq, valors, profundidade + 1);
    if (esquerda != -1) return esquerda;
    
    return calcular_profundidade(raiz->dir, valors, profundidade + 1);
}
void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) return;
    
    printf("%d ", raiz->valor);
    if (valor < raiz->valor)
        imprimir_ancestrais(raiz->esq, valor);
    else
        imprimir_ancestrais(raiz->dir, valor);
}

void imprimir_descendentes(No* no) {
    if (no == NULL) return;
    printf("%d ", no->valor);
    imprimir_descendentes(no->esq);
    imprimir_descendentes(no->dir);
}
void analisar_arvore(No* raiz, int valorBusca) {
    if (raiz == NULL) return;
    
    printf("\n--- DIAGNOSTICO GERAL ---");
    printf("\nRaiz: %d", raiz->valor);
    printf("\nNos Internos: "); imprimir_nos_internos(raiz);
    printf("\nNos Folhas: "); imprimir_folhas(raiz);
    printf("\nExibicao por Niveis:\n"); imprimir_niveis(raiz, 0);

    No* atual = raiz;
    while (atual != NULL && atual->valor != valorBusca) {
        if (valorBusca < atual->valor) atual = atual->esq;
        else atual = atual->dir;
    }

    if (atual == NULL) {
        printf("\nValor %d nao encontrado.\n", valorBusca);
        return;
    }

    printf("\n--- DIAGNOSTICO ESPECIFICO (No %d) ---", valorBusca);
    printf("\nGrau do No: %d", (atual->esq != NULL) + (atual->dir != NULL));
    printf("\nAncestrais: "); imprimir_ancestrais(raiz, valorBusca);
    printf("\nDescendentes: "); imprimir_descendentes(atual);
    printf("\nAltura: %d", calcular_altura(atual));
    printf("\nProfundidade: %d", calcular_profundidade(raiz, valorBusca, 0));

    printf("\n--- EXTRACAO DE SUB-ARVORE ---\n");
    imprimir_niveis(atual, 0);
}

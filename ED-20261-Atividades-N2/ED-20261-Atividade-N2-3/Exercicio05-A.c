//RA: 2040482513041 - Ryan Correia Ferreira
#include <stdio.h>
No* inserir(No *raiz, int valor)
{
    if(raiz == NULL)
    {
        No *novo = malloc(sizeof(No));

        novo->dado = valor;

        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if(valor < raiz->dado)
    {
        raiz->esq =
            inserir(raiz->esq, valor);
    }
    else
    {
        raiz->dir =
            inserir(raiz->dir, valor);
    }

    return raiz;
}

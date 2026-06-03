//RA: 2040482513041 - Ryan Correia Ferreira
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esq;
    struct No *dir;

} No;

/* ================= INSERIR ================= */

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

/* ================= ANCESTRAIS ================= */

void imprimirAncestral(No *raiz,
                       int valor)
{
    if(raiz == NULL)
    {
        return;
    }

    if(raiz->dado == valor)
    {
        return;
    }

    printf("%d ", raiz->dado);

    if(valor < raiz->dado)
    {
        imprimirAncestral(
            raiz->esq,
            valor
        );
    }
    else
    {
        imprimirAncestral(
            raiz->dir,
            valor
        );
    }
}

/* ================= DESCENDENTES ================= */

void emOrdemDesc(No *no)
{
    if(no != NULL)
    {
        emOrdemDesc(no->esq);

        printf("%d ", no->dado);

        emOrdemDesc(no->dir);
    }
}

void imprimirDescendentes(No *raiz,
                          int valor)
{
    if(raiz == NULL)
    {
        return;
    }

    if(raiz->dado == valor)
    {
        /* não imprime o próprio nó */
        emOrdemDesc(raiz->esq);

        emOrdemDesc(raiz->dir);

        return;
    }

    if(valor < raiz->dado)
    {
        imprimirDescendentes(
            raiz->esq,
            valor
        );
    }
    else
    {
        imprimirDescendentes(
            raiz->dir,
            valor
        );
    }
}

/* ================= CONTAR NÓS ================= */

int contarNos(No *no)
{
    if(no == NULL)
    {
        return 0;
    }

    return 1
           + contarNos(no->esq)
           + contarNos(no->dir);
}

/* ================= CONTAR DESCENDENTES ================= */

int contarDescendentes(No *no)
{
    if(no == NULL)
    {
        return 0;
    }

    return contarNos(no->esq)
           + contarNos(no->dir);
}

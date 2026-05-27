//RA: 2040482513041 - Ryan Correia Ferreira
#include <stdio.h>
int alturaNo(No *no)
{
    if(no == NULL)
    {
        return -1;
    }

    int altEsq =
        alturaNo(no->esq);

    int altDir =
        alturaNo(no->dir);

    if(altEsq > altDir)
    {
        return altEsq + 1;
    }

    return altDir + 1;
}
int profundidadeNo(No *raiz,
                   int valor,
                   int prof)
{
    if(raiz == NULL)
    {
        return -1;
    }

    if(raiz->dado == valor)
    {
        return prof;
    }

    if(valor < raiz->dado)
    {
        return profundidadeNo(
               raiz->esq,
               valor,
               prof + 1);
    }

    return profundidadeNo(
           raiz->dir,
           valor,
           prof + 1);
}
int grauNo(No *no)
{
    int grau = 0;

    if(no->esq != NULL)
    {
        grau++;
    }

    if(no->dir != NULL)
    {
        grau++;
    }

    return grau;
}
void emOrdem(No *no)
{
    if(no != NULL)
    {
        emOrdem(no->esq);

        printf("%d ", no->dado);

        emOrdem(no->dir);
    }
}
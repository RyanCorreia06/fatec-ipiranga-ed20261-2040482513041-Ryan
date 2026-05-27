//RA: 2040482513041 - Ryan Correia Ferreira
#include <stdio.h>
#include <stdlib.h>
/* ================= BUSCAR ================= */

No* buscar(No *raiz, int valor)
{
    if(raiz == NULL)
    {
        return NULL;
    }

    if(raiz->dado == valor)
    {
        return raiz;
    }

    if(valor < raiz->dado)
    {
        return buscar(raiz->esq,
                      valor);
    }

    return buscar(raiz->dir,
                  valor);
}

/* ================= ALTURA ================= */

int alturaNo(No *no)
{
    if(no == NULL)
    {
        return -1;
    }

    int esq =
        alturaNo(no->esq);

    int dir =
        alturaNo(no->dir);

    if(esq > dir)
    {
        return esq + 1;
    }

    return dir + 1;
}

/* ================= PROFUNDIDADE ================= */

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

/* ================= GRAU ================= */

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

/* ================= RELATÓRIO ================= */

void relatorioNo(No *raiz,
                 int valor)
{
    No *no = buscar(raiz, valor);

    if(no == NULL)
    {
        printf("\nValor %d nao encontrado.\n",
               valor);

        return;
    }

    printf("\n+------------------------------+\n");

    printf("| RELATORIO DO NO: %-11d |\n",
           valor);

    printf("+------------------------------+\n");

    printf("| Profundidade : %-12d |\n",
           profundidadeNo(
               raiz,
               valor,
               0));

    printf("| Altura       : %-12d |\n",
           alturaNo(no));

    printf("| Grau         : %-12d |\n",
           grauNo(no));

    printf("| Ancestrais   : ");

    imprimirAncestral(raiz,
                      valor);

    printf("\n");

    printf("| Descendentes : ");

    imprimirDescendentes(raiz,
                         valor);

    printf("\n");

    printf("| Qtd Descend. : %-12d |\n",
           contarDescendentes(no));

    printf("+------------------------------+\n");
}

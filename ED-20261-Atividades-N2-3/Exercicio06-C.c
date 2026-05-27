//RA: 2040482513041 - Ryan Correia Ferreira
#include <stdio.h>
#include <stdlib.h>
/*
Árvore construída:

                     50
                  /      \
               30          70
             /   \       /    \
           20     40    60     80
          /  \      \      \
        10   25     45      65
*/

/* ================= LIBERAR ÁRVORE ================= */

void liberarArvore(No *raiz)
{
    if(raiz != NULL)
    {
        liberarArvore(raiz->esq);

        liberarArvore(raiz->dir);

        free(raiz);
    }
}

/* ================= MAIN ================= */

int main()
{
    int valores[] =
    {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    No *raiz = NULL;

    /* monta a ABB */
    for(int i = 0; i < 11; i++)
    {
        raiz =
            inserir(raiz,
                     valores[i]);
    }

    printf("=== TESTES SISTEMATICOS ===\n");

    /* raiz */
    relatorioNo(raiz, 50);

    /* nó intermediário */
    relatorioNo(raiz, 30);

    /* folha */
    relatorioNo(raiz, 10);

    /* nó intermediário */
    relatorioNo(raiz, 70);

    /* teste de erro */
    relatorioNo(raiz, 999);

    liberarArvore(raiz);

    return 0;
}
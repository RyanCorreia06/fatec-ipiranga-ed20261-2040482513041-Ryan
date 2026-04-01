// AUTOR: RYAN CORREIA
#include <stdio.h>   // funções de entrada e saída
#include <stdlib.h>  // uso de exit()
#include <ctype.h>   // função isdigit()

// ================= PILHA =================

// Tamanho máximo da pilha
#define MAX 5

// Vetor que armazena os elementos da pilha
int pilha[MAX];

// Variável que indica o topo da pilha
// Começa em -1 → pilha vazia
int topo = -1;

// Função para inserir elemento na pilha (PUSH)
void push(int valor) {
    if (topo == MAX - 1) {
        printf("Erro: pilha cheia!\n");
        exit(1);
    }

    pilha[++topo] = valor;
}

// Função para remover elemento da pilha (POP)
int pop() {
    if (topo == -1) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }

    return pilha[topo--];
}

// Exibe todos os elementos da pilha
void mostrar() {
    if (topo == -1) {
        printf("Pilha vazia\n");
        return;
    }

    printf("Pilha: ");
    for (int i = 0; i <= topo; i++) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

// Mostra apenas o elemento do topo
void mostrarTopo() {
    if (topo == -1) {
        printf("Topo: pilha vazia\n");
    } else {
        printf("Topo: %d\n", pilha[topo]);
    }
}

// ================= RPN =================

// Verifica se o caractere é um operador válido
int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Realiza o cálculo entre dois valores
int calcular(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// ================= PROGRAMA PRINCIPAL =================

int main() {

    char expr[100];

    printf("Digite a expressao em RPN (ex: 34+2*): ");
    scanf("%s", expr);

    int i = 0;

    while (expr[i] != '\0') {

        printf("\nProcessando: %c\n", expr[i]);

        // CASO 1: É número
        if (isdigit(expr[i])) {

            int valor = expr[i] - '0';

            printf("Inserindo na pilha: %d\n", valor);
            push(valor);
        }

        // CASO 2: É operador
        else if (ehOperador(expr[i])) {

            if (topo < 1) {
                printf("Erro: expressao invalida!\n");
                return 1;
            }

            int b = pop();
            int a = pop();

            printf("Calculando: %d %c %d\n", a, expr[i], b);

            int resultado = calcular(a, b, expr[i]);

            printf("Resultado parcial: %d\n", resultado);

            push(resultado);
        }

        // CASO INVÁLIDO
        else {
            printf("Erro: caractere invalido!\n");
            return 1;
        }

        mostrar();
        mostrarTopo();

        i++;
    }

    // Validação final
    if (topo != 0) {
        printf("Erro: expressao invalida!\n");
    } else {
        printf("\nResultado final: %d\n", pop());
    }

    return 0;
}
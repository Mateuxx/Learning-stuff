#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_LENGTH 100

typedef struct {
    char data[MAX_EXPRESSION_LENGTH];
    int top;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->top = -1;
}

bool pilhaVazia(Pilha *pilha) {
    return pilha->top == -1;
}

void empilharElemento(Pilha *pilha, char item) {
    if (pilha->top < MAX_EXPRESSION_LENGTH - 1) {
        pilha->data[++pilha->top] = item;
    } else {
        printf("Erro: Pilha cheia.\n");
        exit(1);
    }
}

char desempilharElemento(Pilha *pilha) {
    if (!pilhaVazia(pilha)) {
        return pilha->data[pilha->top--];
    } else {
        printf("Erro: Pilha vazia.\n");
        exit(1);
    }
}

bool ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool ehDigito(char c) {
    return isdigit(c);
}

bool trataErros(const char *expressao) {
    int tamanho = strlen(expressao);
    int algarismosConsecutivos = 0;
    int operadoresConsecutivos = 0;

    if (ehOperador(expressao[tamanho - 1])) {
        printf("Erro: Ausência de termo após o operador.\n");
        return false;
    }

    Pilha pilhaNumeros;
    inicializarPilha(&pilhaNumeros);

    for (int i = 0; i < tamanho; i++) {
        if (ehOperador(expressao[i])) {
            if (pilhaVazia(&pilhaNumeros)) {
                printf("Erro: Ausência de termo antes do operador.\n");
                return false;
            }
            algarismosConsecutivos = 0;
            operadoresConsecutivos++;
            if (operadoresConsecutivos > 1) {
                printf("Erro: Excesso de operador.\n");
                return false;
            }
        } else if (ehDigito(expressao[i])) {
            empilharElemento(&pilhaNumeros, expressao[i]);
            operadoresConsecutivos = 0;
            algarismosConsecutivos++;
            if (algarismosConsecutivos > 1) {
                printf("Erro: Excesso de algarismo.\n");
                return false;
            }
        } else if (expressao[i] == ' ') {
            continue;
        } else {
            printf("Erro: Caractere inválido na expressão.\n");
            return false;
        }
    }

    if (pilhaVazia(&pilhaNumeros)) {
        printf("Erro: Ausência de termo após o operador.\n");
        return false;
    }

    return true;
}

void converterParaNotacaoPolonesa(const char *expressao) {
    if (!trataErros(expressao)) {
        return;
    }

    Pilha pilhaOperadores;
    inicializarPilha(&pilhaOperadores);

    int tamanho = strlen(expressao);

    for (int i = 0; i < tamanho; i++) {
        if (ehDigito(expressao[i])) {
            printf("%c", expressao[i]);
        } else if (ehOperador(expressao[i])) {
            while (!pilhaVazia(&pilhaOperadores) &&
                   ehOperador(pilhaOperadores.data[pilhaOperadores.top]) &&
                   pilhaOperadores.data[pilhaOperadores.top] != '(' &&
                   ((expressao[i] != '*' && expressao[i] != '/') ||
                    (pilhaOperadores.data[pilhaOperadores.top] != '+' && pilhaOperadores.data[pilhaOperadores.top] != '-'))) {
                printf("%c", desempilharElemento(&pilhaOperadores));
            }
            empilharElemento(&pilhaOperadores, expressao[i]);
        } else if (expressao[i] == ' ') {
            continue;
        } else {
            printf("Erro: Caractere inválido na expressão.\n");
            return;
        }
    }

    while (!pilhaVazia(&pilhaOperadores)) {
        printf("%c", desempilharElemento(&pilhaOperadores));
    }
    printf("\n");
}

int main() {
    char expressao[MAX_EXPRESSION_LENGTH];
    char continuar;

    do {
        printf("Digite uma expressão matemática: ");
        fgets(expressao, MAX_EXPRESSION_LENGTH, stdin);

        int tamanho = strlen(expressao);
        if (expressao[tamanho - 1] == '\n') {
            expressao[tamanho - 1] = '\0';
        }

        converterParaNotacaoPolonesa(expressao);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);

        while ((getchar()) != '\n');

    } while (continuar == 's' || continuar == 'S');

    return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

// Função para verificar se um caractere é um operador aritmético
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Função para verificar se um caractere é um dígito
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Função para verificar a sintaxe de uma expressão aritmética simples
bool parseExpression(const char *expression) {
    int i = 0;
    bool expectOperand = true;  // Começamos esperando um operando (número ou parêntese aberto)
    
    while (expression[i] != '\0') {
        char current = expression[i];

        if (isspace(current)) {
            // Ignora espaços em branco
            i++;
            continue;
        }

        if (isDigit(current)) {
            // Se encontrar um número, espera um operador ou um fim
            expectOperand = false;
            while (isDigit(expression[i])) i++;  // Avança enquanto for um dígito
        } else if (isOperator(current)) {
            // Se encontrar um operador, espera um operando depois
            if (expectOperand) {
                printf("Erro de sintaxe: operador '%c' inesperado na posição %d\n", current, i);
                return false;
            }
            expectOperand = true;
            i++;
        } else if (current == '(') {
            // Se encontrar um parêntese aberto, espera um operando depois
            expectOperand = true;
            i++;
        } else if (current == ')') {
            // Se encontrar um parêntese fechado, espera um operador depois ou fim
            if (expectOperand) {
                printf("Erro de sintaxe: parêntese fechado inesperado na posição %d\n", i);
                return false;
            }
            i++;
        } else {
            // Qualquer outro caractere é inválido
            printf("Erro de sintaxe: caractere inválido '%c' na posição %d\n", current, i);
            return false;
        }
    }

    if (expectOperand) {
        printf("Erro de sintaxe: expressão incompleta\n");
        return false;
    }

    return true;
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Digite uma expressão aritmética: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove o caractere de nova linha da entrada
    input[strcspn(input, "\n")] = 0;

    if (parseExpression(input)) {
        printf("Expressão válida!\n");
    } else {
        printf("Expressão inválida!\n");
    }

    return 0;
}

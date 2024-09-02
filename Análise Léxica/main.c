#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100

// Tipos de tokens
typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_UNKNOWN
} TokenType;

// Função para identificar se uma string é uma palavra-chave
int is_keyword(const char *str) {
    const char *keywords[] = { "int", "float", "return", "if", "else", "while", "for" };
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Função para imprimir o tipo de token
void print_token(const char *token, TokenType type) {
    const char *type_str;
    switch (type) {
        case TOKEN_KEYWORD:
            type_str = "Keyword";
            break;
        case TOKEN_IDENTIFIER:
            type_str = "Identifier";
            break;
        case TOKEN_NUMBER:
            type_str = "Number";
            break;
        case TOKEN_OPERATOR:
            type_str = "Operator";
            break;
        default:
            type_str = "Unknown";
            break;
    }
    printf("Token: '%s' | Type: %s\n", token, type_str);
}

// Função para analisar a string e identificar tokens
void analyze_tokens(const char *source) {
    char token[MAX_TOKEN_LENGTH];
    int token_index = 0;
    
    for (int i = 0; source[i] != '\0'; ++i) {
        if (isspace(source[i])) {
            if (token_index > 0) {
                token[token_index] = '\0';
                if (is_keyword(token)) {
                    print_token(token, TOKEN_KEYWORD);
                } else if (isdigit(token[0])) {
                    print_token(token, TOKEN_NUMBER);
                } else if (isalpha(token[0])) {
                    print_token(token, TOKEN_IDENTIFIER);
                } else {
                    print_token(token, TOKEN_UNKNOWN);
                }
                token_index = 0;
            }
        } else if (strchr("+-*/=<>!;", source[i])) { // Identifica operadores
            if (token_index > 0) {
                token[token_index] = '\0';
                if (is_keyword(token)) {
                    print_token(token, TOKEN_KEYWORD);
                } else if (isdigit(token[0])) {
                    print_token(token, TOKEN_NUMBER);
                } else if (isalpha(token[0])) {
                    print_token(token, TOKEN_IDENTIFIER);
                } else {
                    print_token(token, TOKEN_UNKNOWN);
                }
                token_index = 0;
            }
            token[0] = source[i];
            token[1] = '\0';
            print_token(token, TOKEN_OPERATOR);
        } else {
            token[token_index++] = source[i];
        }
    }
    
    if (token_index > 0) {
        token[token_index] = '\0';
        if (is_keyword(token)) {
            print_token(token, TOKEN_KEYWORD);
        } else if (isdigit(token[0])) {
            print_token(token, TOKEN_NUMBER);
        } else if (isalpha(token[0])) {
            print_token(token, TOKEN_IDENTIFIER);
        } else {
            print_token(token, TOKEN_UNKNOWN);
        }
    }
}

// Função principal
int main() {
    const char *code = "int x = 10; float y = 20.5; if (x < y) return x + y;";
    
    printf("Analyzing code:\n%s\n\n", code);
    analyze_tokens(code);
    
    return 0;
}

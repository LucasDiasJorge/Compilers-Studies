#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 100
#define MAX_LINE_LENGTH 256

// Estrutura para armazenar informações sobre variáveis
typedef struct {
    char name[50];
    char type[20];
    int initialized; // 1 se inicializado, 0 se não
} Symbol;

// Tabela de símbolos
Symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

// Função para adicionar um símbolo à tabela
void add_symbol(const char *name, const char *type) {
    for (int i = 0; i < symbol_count; ++i) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            // Já existe, apenas atualize o tipo se necessário
            strcpy(symbol_table[i].type, type);
            return;
        }
    }
    // Adicionar novo símbolo
    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].type, type);
    symbol_table[symbol_count].initialized = 0;
    ++symbol_count;
}

// Função para marcar um símbolo como inicializado
void initialize_symbol(const char *name) {
    for (int i = 0; i < symbol_count; ++i) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            symbol_table[i].initialized = 1;
            return;
        }
    }
}

// Função para verificar se um símbolo está inicializado
int is_symbol_initialized(const char *name) {
    for (int i = 0; i < symbol_count; ++i) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].initialized;
        }
    }
    return 0;
}

// Função para analisar uma linha de código
void parse_line(const char *line) {
    char var_name[50], type[20], op[10];
    int scanned = sscanf(line, "%s %s %s", type, var_name, op);
    
    if (scanned == 2) { // Declaração de variável
        add_symbol(var_name, type);
    } else if (scanned == 3) { // Inicialização
        if (strcmp(op, "=") == 0) {
            if (isalpha(var_name[0])) { // Verifica se é um identificador
                initialize_symbol(var_name);
            } else {
                printf("Erro: Inicialização de variável inválida!\n");
            }
        }
    }
}

// Função principal para ler e analisar o arquivo
void analyze_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parse_line(line);
    }

    fclose(file);
}

// Função para verificar erros de semântica
void check_semantics() {
    for (int i = 0; i < symbol_count; ++i) {
        if (!symbol_table[i].initialized) {
            printf("Erro: Variável '%s' do tipo '%s' não inicializada!\n",
                   symbol_table[i].name, symbol_table[i].type);
        }
    }
}

// Função principal
int main() {
    const char *filename = "code.txt"; // Nome do arquivo com o código-fonte

    analyze_file(filename);
    check_semantics();

    return 0;
}

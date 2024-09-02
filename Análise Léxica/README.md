### O Que É Análise Léxica?

A análise léxica é a primeira fase do processo de compilação ou interpretação. Ela transforma o código-fonte (texto) em uma sequência de tokens. Os tokens são as unidades básicas de significado, como palavras-chave, identificadores, números e operadores.

### Passos Detalhados da Análise Léxica

#### 1. **Entrada**

- **Código-Fonte**: É o texto que você escreve em uma linguagem de programação. Exemplo:
  ```c
  int x = 10;
  ```

#### 2. **Leitura do Código-Fonte**

- **Leitor de Texto**: O código-fonte é lido linha por linha ou caractere por caractere.
- **Exemplo**: Lê o primeiro caractere, depois o segundo, e assim por diante.

#### 3. **Divisão em Tokens**

- **Tokenização**: O texto é dividido em tokens com base em regras específicas.
- **Tipos de Tokens**:
  - **Palavras-chave**: `int`, `if`, `return`, etc.
  - **Identificadores**: Nomes de variáveis como `x`, `y`, etc.
  - **Números**: Literais numéricos como `10`, `3.14`.
  - **Operadores**: `+`, `=`, `*`.
  - **Delimitadores**: Pontuação como `;`, `,`, `(`, `)`.

**Exemplo**:
Para o código `int x = 10;`, os tokens seriam:
- `int` (palavra-chave)
- `x` (identificador)
- `=` (operador)
- `10` (número)
- `;` (delimitador)

#### 4. **Classificação dos Tokens**

- **Identificação**: Cada token é classificado de acordo com sua categoria.
- **Como Funciona**:
  - **Palavras-chave**: Verifica se o token é uma palavra reservada da linguagem.
  - **Identificadores**: Verifica se o token é um nome válido para variáveis ou funções.
  - **Números**: Verifica se o token representa um valor numérico.
  - **Operadores**: Verifica se o token é um operador matemático ou lógico.
  - **Delimitadores**: Identifica sinais de pontuação e separadores.

**Exemplo**:
- `int` é classificado como `KEYWORD`.
- `x` é classificado como `IDENTIFIER`.
- `=` é classificado como `OPERATOR`.
- `10` é classificado como `NUMBER`.
- `;` é classificado como `DELIMITER`.

#### 5. **Emissão dos Tokens**

- **Saída**: Os tokens identificados são emitidos para a próxima fase do compilador ou interpretador.
- **Formato**: Pode ser uma lista de tokens com seus tipos ou uma estrutura de dados mais complexa.

**Exemplo de Saída**:
```plaintext
Token: 'int' | Type: Keyword
Token: 'x' | Type: Identifier
Token: '=' | Type: Operator
Token: '10' | Type: Number
Token: ';' | Type: Delimiter
```

### Exemplos de Código para Análise Léxica

Aqui está um exemplo simples de como você pode implementar a análise léxica em C. O código abaixo analisa uma string e imprime os tokens encontrados.

```c
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
    TOKEN_DELIMITER,
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
        case TOKEN_DELIMITER:
            type_str = "Delimiter";
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
        if (isspace(source[i]) || strchr("+-*/=<>!;", source[i]) || source[i] == '(' || source[i] == ')') {
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
            if (strchr("+-*/=<>!;", source[i])) {
                token[0] = source[i];
                token[1] = '\0';
                print_token(token, TOKEN_OPERATOR);
            } else if (source[i] == '(' || source[i] == ')') {
                token[0] = source[i];
                token[1] = '\0';
                print_token(token, TOKEN_DELIMITER);
            }
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
```

### Explicação do Código

1. **Definição de Tipos de Tokens**:
   - `TOKEN_KEYWORD`, `TOKEN_IDENTIFIER`, `TOKEN_NUMBER`, `TOKEN_OPERATOR`, `TOKEN_DELIMITER`, `TOKEN_UNKNOWN`.

2. **Função `is_keyword()`**:
   - Verifica se um token é uma palavra-chave.

3. **Função `print_token()`**:
   - Imprime o token e seu tipo.

4. **Função `analyze_tokens()`**:
   - Analisa a string de código-fonte e identifica tokens.
   - Divide o código em tokens com base em espaços e operadores.
   - Identifica e imprime o tipo de cada token.

5. **Função `main()`**:
   - Define um exemplo de código-fonte e chama `analyze_tokens()` para processá-lo.

### Resumo

- **Leitura**: O código-fonte é lido caractere por caractere.
- **Tokenização**: O código é dividido em tokens com base em espaços e delimitadores.
- **Classificação**: Cada token é identificado como uma palavra-chave, identificador, número, operador ou delimitador.
- **Emissão**: Os tokens são passados para a próxima fase do compilador ou interpretador.

Essa abordagem fornece uma visão clara de como a análise léxica funciona em um compilador ou interpretador.
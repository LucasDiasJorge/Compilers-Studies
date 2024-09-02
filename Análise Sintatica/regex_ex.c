#include <stdio.h>
#include <regex.h>

int main() {
    regex_t regex;
    int reti;

    // Compilar a expressão regular para números e operadores simples
    reti = regcomp(&regex, "^[0-9]+(\\s*[-+*/]\\s*[0-9]+)*$", REG_EXTENDED);

    if (reti) {
        fprintf(stderr, "Não foi possível compilar o regex\n");
        return 1;
    }

    // Expressão de teste
    const char *input = "3 + 4 * 2";

    // Executar correspondência de regex
    reti = regexec(&regex, input, 0, NULL, 0);

    if (!reti) {
        printf("Expressão válida!\n");
    } else if (reti == REG_NOMATCH) {
        printf("Expressão inválida!\n");
    } else {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Erro de regex: %s\n", msgbuf);
        return 1;
    }

    // Liberar memória usada pelo regex
    regfree(&regex);

    return 0;
}
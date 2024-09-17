#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

void check_regex(const char *pattern, const char *string) {
    regex_t regex;
    int reti;

    // Compilar a expressão regular
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    // Aplicar regex na string de teste
    reti = regexec(&regex, string, 0, NULL, 0);
    if (!reti) {
        printf("Pattern '%s' matches the string '%s'\n", pattern, string);
    } else if (reti == REG_NOMATCH) {
        printf("Pattern '%s' does not match the string '%s'\n", pattern, string);
    } else {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
    }

    // Liberar a memória alocada pela compilação do regex
    regfree(&regex);
}

int main() {
    // 1. Literal Match
    check_regex("hello", "hello world");

    // 2. . (Qualquer caractere)
    check_regex("h.llo", "hello");

    // 3. ^ e $ (Início e fim da string)
    check_regex("^hello", "hello world");
    check_regex("world$", "hello world");

    // 4. [] (Classes de caracteres)
    check_regex("[Hh]ello", "Hello world");
    check_regex("[a-z]", "abcDEF");

    // 5. Quantificadores (*, +, ?)
    check_regex("a*", "aaabbb");
    check_regex("a+", "aaabbb");
    check_regex("a?", "bcaaa");

    // 6. {n}, {n,}, {n,m} (Quantificadores exatos)
    check_regex("a{3}", "aaabbb");
    check_regex("a{2,}", "aaabbb");
    check_regex("a{2,4}", "aaaabbb");

    // 7. Alternância (|)
    check_regex("abc|def", "def");

    // 8. Agrupamento com parênteses ()
    check_regex("(abc)+", "abcabcabc");

    // 9. Retrovisores (\1)
    check_regex("(a)b\1", "aba");

    // 10. Classes predefinidas (\d, \w, \s)
    check_regex("\\d+", "123abc");
    check_regex("\\w+", "abc123");
    check_regex("\\s", "hello world");

    // 11. Lookahead positivo (?=) e negativo (?!)
    check_regex("foo(?=bar)", "foobar"); // 'foo' seguido de 'bar'
    check_regex("foo(?!bar)", "foobaz"); // 'foo' não seguido de 'bar'

    return 0;
}

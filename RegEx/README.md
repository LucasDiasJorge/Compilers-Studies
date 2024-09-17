# RegEx

Expressões regulares (**regex**) são uma poderosa ferramenta para correspondência de padrões em strings. Elas são compostas de símbolos especiais que definem padrões de busca e manipulação. Abaixo, vamos passar por todas as principais regras de expressões regulares, abrangendo caracteres especiais, operadores e quantificadores.

### 1. **Caractere Literal**
   - Qualquer caractere literal corresponde a ele mesmo.
   - Exemplos:
     - `a` corresponde ao caractere 'a'.
     - `hello` corresponde à string 'hello'.

### 2. **Metacaracteres Especiais**
   Os metacaracteres têm significados especiais e são usados para construir padrões mais complexos. Para corresponder a um metacaractere como literal, use uma barra invertida (`\`) para escapar.

   - **. (Ponto)**: Corresponde a qualquer caractere (exceto nova linha em alguns engines).
     - Exemplo: `a.b` corresponde a 'aXb', 'a1b', 'a@b', etc.
   
   - **^ (Circunflexo)**: Corresponde ao início da string.
     - Exemplo: `^abc` corresponde a 'abc' apenas se estiver no início da string.
   
   - **$ (Cifrão)**: Corresponde ao fim da string.
     - Exemplo: `xyz$` corresponde a 'xyz' apenas se estiver no fim da string.
   
   - **\ (Barra invertida)**: Usado para escapar metacaracteres ou para adicionar significados especiais a caracteres.
     - Exemplo: `\.` corresponde a um ponto literal.
   
   - **[] (Colchetes)**: Define uma classe de caracteres. Corresponde a um único caractere qualquer dentro dos colchetes.
     - Exemplo: `[abc]` corresponde a 'a', 'b' ou 'c'.

### 3. **Classes de Caracteres**
   Uma classe de caracteres corresponde a qualquer um dos caracteres listados dentro dos colchetes.

   - **[abc]**: Corresponde a 'a', 'b', ou 'c'.
   - **[a-z]**: Corresponde a qualquer letra minúscula de 'a' a 'z'.
   - **[A-Z]**: Corresponde a qualquer letra maiúscula de 'A' a 'Z'.
   - **[0-9]**: Corresponde a qualquer dígito de '0' a '9'.
   - **[^abc]**: Corresponde a qualquer caractere exceto 'a', 'b' ou 'c'.
   - **[a-zA-Z]**: Corresponde a qualquer letra, tanto maiúscula quanto minúscula.

### 4. **Quantificadores**
   Quantificadores determinam quantas vezes o padrão anterior deve aparecer.

   - **\***: Corresponde a 0 ou mais ocorrências.
     - Exemplo: `a*` corresponde a '', 'a', 'aa', 'aaa', etc.
   
   - **+**: Corresponde a 1 ou mais ocorrências.
     - Exemplo: `a+` corresponde a 'a', 'aa', 'aaa', etc., mas não a ''.
   
   - **?**: Corresponde a 0 ou 1 ocorrência.
     - Exemplo: `a?` corresponde a '' ou 'a'.
   
   - **{n}**: Corresponde exatamente a 'n' ocorrências.
     - Exemplo: `a{3}` corresponde a 'aaa'.
   
   - **{n,}**: Corresponde a 'n' ou mais ocorrências.
     - Exemplo: `a{2,}` corresponde a 'aa', 'aaa', 'aaaa', etc.
   
   - **{n,m}**: Corresponde entre 'n' e 'm' ocorrências.
     - Exemplo: `a{2,4}` corresponde a 'aa', 'aaa', ou 'aaaa'.

### 5. **Âncoras e Limites**
   Âncoras não correspondem a caracteres, mas a posições na string.

   - **^**: Corresponde ao início da string.
     - Exemplo: `^abc` corresponde a 'abc' no início da string.
   
   - **$**: Corresponde ao fim da string.
     - Exemplo: `abc$` corresponde a 'abc' no final da string.
   
   - **\b**: Corresponde a uma borda de palavra (entre um caractere de palavra e um caractere não-palavra).
     - Exemplo: `\bword\b` corresponde à palavra 'word' isolada.
   
   - **\B**: Corresponde a qualquer lugar que não seja uma borda de palavra.
     - Exemplo: `\Bword\B` não corresponderá se 'word' for isolada.

### 6. **Grupos e Alternância**
   Grupos e alternância permitem construir padrões mais complexos.

   - **()**: Agrupa subexpressões.
     - Exemplo: `(abc)+` corresponde a uma ou mais ocorrências de 'abc'.
   
   - **| (OU lógico)**: Alternância, corresponde ao padrão à esquerda ou à direita.
     - Exemplo: `abc|def` corresponde a 'abc' ou 'def'.
   
   - **(?: )**: Grupo não capturador, agrupa sem criar uma captura.
     - Exemplo: `(?:abc)+` corresponde a 'abc' repetidamente, mas não captura o grupo.

### 7. **Retrovisores (Backreferences)**
   Retrovisores permitem referir-se a capturas anteriores na expressão regular.

   - **\n**: Refere-se ao enésimo grupo capturado anteriormente.
     - Exemplo: `([a-z])\1` corresponde a letras repetidas como 'aa', 'bb', etc. Aqui, `\1` refere-se ao conteúdo do primeiro grupo.

### 8. **Classes de Caracteres Predefinidas**
   - **.**: Corresponde a qualquer caractere exceto uma nova linha.
   - **\d**: Corresponde a qualquer dígito (equivalente a `[0-9]`).
   - **\D**: Corresponde a qualquer caractere que não seja um dígito (equivalente a `[^0-9]`).
   - **\w**: Corresponde a qualquer caractere de palavra (letras, dígitos e sublinhado, equivalente a `[a-zA-Z0-9_]`).
   - **\W**: Corresponde a qualquer caractere que não seja de palavra (equivalente a `[^a-zA-Z0-9_]`).
   - **\s**: Corresponde a qualquer caractere de espaço em branco (espaços, tabs, novas linhas).
   - **\S**: Corresponde a qualquer caractere que não seja de espaço em branco.

### 9. **Lookahead e Lookbehind (Avanços e Retrocessos)**
   Essas são formas avançadas de garantir que um padrão seja ou não seguido/precedido por outro padrão, sem consumi-lo na correspondência.

   - **Lookahead positivo (`(?=...)`)**: Verifica se há uma correspondência à frente, sem consumi-la.
     - Exemplo: `foo(?=bar)` corresponde a 'foo' apenas se for seguido de 'bar'.
   
   - **Lookahead negativo (`(?!...)`)**: Verifica se *não* há uma correspondência à frente.
     - Exemplo: `foo(?!bar)` corresponde a 'foo' apenas se *não* for seguido de 'bar'.
   
   - **Lookbehind positivo (`(?<=...)`)**: Verifica se há uma correspondência atrás do ponto atual.
     - Exemplo: `(?<=foo)bar` corresponde a 'bar' apenas se for precedido de 'foo'.
   
   - **Lookbehind negativo (`(?<!...)`)**: Verifica se *não* há uma correspondência atrás do ponto atual.
     - Exemplo: `(?<!foo)bar` corresponde a 'bar' apenas se *não* for precedido de 'foo'.

---

### Exemplos:

1. **Validar um endereço de e-mail simples**:
   ```regex
   ^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$
   ```
   - Corresponde a um e-mail do tipo `nome@dominio.com`.

2. **Encontrar números de telefone (formato americano)**:
   ```regex
   \(\d{3}\) \d{3}-\d{4}
   ```
   - Corresponde a números no formato `(123) 456-7890`.

3. **Extrair um número de 5 dígitos**:
   ```regex
   \b\d{5}\b
   ```
   - Corresponde a qualquer sequência de exatamente 5 dígitos.

---

Essas são as principais regras para trabalhar com expressões regulares. O poder do regex está na combinação desses elementos, permitindo buscas e manipulações muito flexíveis de strings.
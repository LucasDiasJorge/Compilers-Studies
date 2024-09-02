# Análise Sintática

A análise sintática, também conhecida como parsing, é uma fase essencial na compilação de código e interpretação de linguagens de programação. Ela envolve o processo de leitura de uma sequência de tokens (geralmente provenientes de uma análise léxica) e a construção de uma estrutura de dados que representa a estrutura gramatical do código de entrada. Esta estrutura de dados é muitas vezes uma árvore sintática (ou árvore de derivação), que mostra como a entrada pode ser derivada das regras da gramática de uma linguagem.

### Passo a Passo da Análise Sintática

1. **Entrada de Tokens**:
   - A análise sintática começa com uma sequência de tokens. Tokens são "pedaços" do código que foram identificados durante a análise léxica (a etapa anterior). Por exemplo, se o código de entrada é `x = 3 + 5;`, os tokens podem ser:
     - `IDENTIFIER(x)`
     - `ASSIGN_OP(=)`
     - `NUMBER(3)`
     - `PLUS(+)`
     - `NUMBER(5)`
     - `SEMICOLON(;)`

2. **Regras Gramaticais**:
   - A linguagem de programação tem um conjunto de regras gramaticais que definem como esses tokens podem ser combinados para formar construções válidas. Essas regras são normalmente escritas em uma forma formal chamada "Gramática Livre de Contexto" (CFG, do inglês Context-Free Grammar).
   - Por exemplo, uma regra gramatical simples para uma expressão aritmética pode ser:
     - `EXPRESSION -> IDENTIFIER ASSIGN_OP TERM`
     - `TERM -> TERM PLUS FACTOR | FACTOR`
     - `FACTOR -> NUMBER`

3. **Construção de uma Estrutura Hierárquica (Árvore Sintática)**:
   - A análise sintática usa essas regras para agrupar os tokens em uma estrutura hierárquica que representa a construção da linguagem. Esta estrutura é chamada de **árvore sintática**.
   - A **árvore sintática** é uma representação que mostra como a entrada é derivada das regras da gramática.
   - Para o exemplo `x = 3 + 5;`, a árvore sintática poderia ser algo assim:

```
            EXPRESSION
           /    |     \
    IDENTIFIER ASSIGN_OP TERM
      (x)       (=)     /   \
                      TERM  FACTOR
                      (3)     (5)
                           |
                         NUMBER
                          (+)
```

4. **Métodos de Análise Sintática**:
   - Existem vários métodos de análise sintática, mas os dois principais são:
     - **Análise Descendente**: Começa a análise pela raiz da árvore sintática e tenta expandir a partir daí usando regras gramaticais. Um exemplo é o **analisador recursivo descendente**, que é simples de implementar mas não funciona bem para todas as gramáticas.
     - **Análise Ascendente**: Começa a partir dos tokens (as folhas da árvore) e tenta combinar tokens em construções maiores até chegar à raiz. Um exemplo é o **analisador LR (Left-to-right, Rightmost derivation)**.

### Exemplo de Funcionamento de Análise Sintática

Vamos fazer um exemplo simples de como uma análise descendente funcionaria para a expressão `x = 3 + 5;` usando uma abordagem recursiva.

#### Etapas da Análise Descendente

1. **Início na Raiz**: O analisador começa tentando encontrar uma correspondência para a regra de gramática que define um `EXPRESSION`.

2. **Aplicação de Regras**: O analisador encontra a regra `EXPRESSION -> IDENTIFIER ASSIGN_OP TERM` e tenta corresponder a cada parte.
   - O primeiro token é `IDENTIFIER(x)`, que corresponde.
   - O segundo token é `ASSIGN_OP(=)`, que também corresponde.
   - O próximo não-terminal é `TERM`.

3. **Expansão do Não-terminal `TERM`**:
   - O analisador usa a regra `TERM -> TERM PLUS FACTOR | FACTOR`.
   - O próximo token é `NUMBER(3)`, que corresponde a `FACTOR`.
   - Agora, o analisador vê um `PLUS(+)` e reconhece que deve continuar com a regra de `TERM` expandindo para `TERM PLUS FACTOR`.
   - Continua com o próximo `NUMBER(5)`, que é um `FACTOR`.

4. **Construção da Árvore Sintática**:
   - À medida que os tokens são processados, o analisador constrói a árvore sintática, agrupando os tokens conforme as regras gramaticais são aplicadas.

5. **Finalização**:
   - O analisador continua até que todos os tokens tenham sido processados e a árvore sintática esteja completa.
   - Se todos os tokens forem processados corretamente e as regras gramaticais forem seguidas, a expressão é considerada **sintaticamente correta**.

6. **Erro Sintático**:
   - Se o analisador encontrar um token onde não deveria estar ou não conseguir aplicar uma regra gramatical, ocorre um **erro sintático**.
   - Por exemplo, em `x = 3 + ;`, a árvore não pode ser completada porque um `FACTOR` (número) é esperado após o operador `+`, mas está faltando.

### Conclusão

A análise sintática é fundamental para assegurar que um código fonte segue as regras gramaticais da linguagem de programação. Ela constrói uma representação estrutural (como uma árvore sintática) da entrada, que pode ser utilizada em etapas posteriores, como análise semântica ou geração de código. Ao verificar a sequência e a estrutura dos tokens, o analisador sintático garante que o código é organizado e compreensível, permitindo que seja executado corretamente ou gerado um código equivalente.

### Comparação com Regex

**Semelhanças:**

1. **Verificação de Padrões**: Assim como uma regex, o código examina uma sequência de caracteres para determinar se ela corresponde a um padrão específico. No caso do código de análise sintática, ele verifica se a expressão segue as regras de sintaxe para uma expressão aritmética válida (por exemplo, números seguidos de operadores).

2. **Processamento de Strings**: Ambos trabalham diretamente com strings e examinam caracteres individuais para decidir se um padrão ou regra é satisfeito.

3. **Detecção de Erros**: Assim como regex pode falhar ao tentar combinar uma string que não corresponde ao padrão especificado, o analisador sintático pode detectar erros se a expressão aritmética não seguir a sintaxe correta.

**Diferenças:**

1. **Complexidade e Flexibilidade**: Expressões regulares são projetadas para especificar padrões complexos de correspondência de strings de uma forma muito compacta e expressiva. O código de análise sintática, por outro lado, é um algoritmo imperativo explícito, o que pode torná-lo mais detalhado e específico para a linguagem ou regras que você deseja implementar.

2. **Capacidade de Extensão**: Um analisador sintático como o que demonstrei pode ser facilmente estendido para realizar ações mais complexas (por exemplo, construção de árvores sintáticas abstratas, interpretação ou tradução de código). Regex, por sua natureza, é mais restrito a correspondência de padrões e manipulação de strings, sem compreensão semântica.

3. **Manutenção de Estado**: O código de análise sintática que escrevi mantém um estado entre iterações (`expectOperand`), o que facilita a implementação de regras de contexto (por exemplo, "depois de um operador deve haver um operando"). Regex, por sua vez, não tem um mecanismo de estado de longo prazo, embora possa usar grupos de captura e outras construções para gerenciar algumas formas de estado limitado.

4. **Hierarquia e Aninhamento**: Regex é limitado em sua capacidade de lidar com padrões aninhados complexos, como parênteses balanceados ou expressões aninhadas, sem se tornar muito complicado. Um analisador sintático pode gerenciar facilmente tais estruturas usando uma pilha ou recursão para acompanhar contextos aninhados.
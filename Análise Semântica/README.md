### O Que É Análise Semântica?

A análise semântica é a etapa do compilador ou interpretador que verifica se o código-fonte é logicamente correto e segue as regras da linguagem de programação. Enquanto a análise sintática foca na estrutura gramatical, a análise semântica foca no significado e uso correto dos elementos do código.

### Passos Detalhados da Análise Semântica

#### 1. **Leitura do Código**

- **Entrada**: O código-fonte é lido do arquivo de entrada e transformado em uma estrutura de dados apropriada, como uma árvore sintática ou uma lista de tokens, após a análise sintática.

#### 2. **Criação da Tabela de Símbolos**

- **O Que é**: Uma estrutura de dados que armazena informações sobre variáveis, funções, tipos e outros identificadores.
- **Como Funciona**:
  - **Inserção**: Quando uma variável ou função é declarada, adiciona-se uma entrada na tabela de símbolos.
  - **Atualização**: Se uma variável ou função é redefinida ou inicializada, a entrada na tabela é atualizada.
  - **Consulta**: Quando o código faz referência a uma variável ou função, a tabela é consultada para verificar a declaração e os detalhes dessa referência.

**Exemplo**:
  - Declaração: `int x;` cria uma entrada na tabela de símbolos com o nome `x` e o tipo `int`.

#### 3. **Verificação de Tipos**

- **O Que é**: Verificar se as operações e expressões estão sendo realizadas com tipos de dados apropriados e compatíveis.
- **Como Funciona**:
  - **Checagem de Operações**: Verifica se operações entre diferentes tipos (por exemplo, `int` + `float`) são permitidas ou se necessitam de conversão.
  - **Tipos de Retorno**: Verifica se funções retornam tipos de dados compatíveis com sua declaração.

**Exemplo**:
  - A operação `int a = 5; float b = a + 1.5;` é válida porque `a` é convertido para `float` antes da adição.

#### 4. **Verificação de Declarações e Inicializações**

- **O Que é**: Garantir que todas as variáveis e funções foram declaradas antes de serem usadas e que variáveis são inicializadas antes do uso.
- **Como Funciona**:
  - **Declarações**: Verifica se todas as variáveis e funções foram declaradas antes de seu uso.
  - **Inicializações**: Verifica se variáveis são inicializadas antes de serem usadas para evitar o uso de valores não definidos.

**Exemplo**:
  - **Declaração**: `int x;` deve ser declarada antes de `x = 10;`.
  - **Inicialização**: Se você tentar usar `x` antes de `x = 10;`, isso resulta em um erro.

#### 5. **Verificação de Escopo**

- **O Que é**: Garantir que identificadores (variáveis, funções) são acessados dentro de seu escopo válido e não há conflitos de nomes.
- **Como Funciona**:
  - **Escopo Local e Global**: Verifica se uma variável local não está sendo confundida com uma variável global com o mesmo nome.
  - **Sombra de Variáveis**: Verifica se variáveis locais não estão escondendo variáveis globais.

**Exemplo**:
  - **Escopo Global**:
    ```c
    int x; // Variável global

    void func() {
        int x; // Variável local
        x = 5; // Usa a variável local 'x'
    }
    ```

#### 6. **Verificação de Coerência Semântica**

- **O Que é**: Verifica se o código segue as regras semânticas e lógicas da linguagem.
- **Como Funciona**:
  - **Estruturas de Controle**: Verifica se estruturas como loops e condicionais estão corretas.
  - **Chamadas de Função**: Garante que chamadas de funções têm o número correto e tipos de argumentos.

**Exemplo**:
  - **Estrutura de Controle**:
    ```c
    while (condition) {
        // Corpo do loop
    }
    ```
  - **Chamada de Função**:
    ```c
    void func(int a) {
        // Código
    }

    func(1); // Correto
    func(1, 2); // Erro: número incorreto de argumentos
    ```

### Resumo do Processo de Análise Semântica

1. **Criar a Tabela de Símbolos**:
   - Adicionar variáveis e funções à tabela com informações sobre seus tipos e escopos.

2. **Verificar Tipos**:
   - Garantir que operações e expressões utilizam tipos de dados apropriados e compatíveis.

3. **Verificar Declarações e Inicializações**:
   - Garantir que variáveis e funções são declaradas antes de serem usadas e que variáveis são inicializadas antes de seu uso.

4. **Verificar Escopo**:
   - Garantir que variáveis e funções são usadas dentro de seu escopo válido e não há conflitos de nomes.

5. **Verificar Coerência Semântica**:
   - Garantir que o código segue as regras semânticas da linguagem e é logicamente consistente.

A análise semântica é crucial para assegurar que o código não apenas está corretamente estruturado, mas também é logicamente correto e segue as regras da linguagem de programação.
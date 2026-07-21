# Introdução:

## Linguagens procedurais x orientadas a objetos

* **Procedurais:** Em uma linguagem procedural, como o C, a unidade básica de programação é a função. Um programa procedural realiza uma tarefa através da execução coordenada de diversas funções.
* **Orientada a Objetos:** Em uma linguagem OO (Java), a unidade básica de programação é a classe. Um programa OO executa uma tarefa através da criação de objetos (instâncias) de tipos variados que interagem entre si (através das chamadas de métodos).

## Classe vs Objeto

* **Classe:** Define um tipo de dado. É composta por Atributos (dados) e Métodos (operações associadas).

* **Objeto (ou Instância):** É o representante concreto e fisico de uma classe. Cada instancia possui seu próprio contexto e seu conjunto particular de atributos na memoria. Emboras todas as instancias compartilhem o mesmo código para os métodos, a execução de um método só enxerga os atributos do objeto em especifico que realizou a chamada.

*Em suma, a classe é o molde e o objeto é aquilo formado pelo molde.*

## A linguagem Java

* Criada em 1995

* Utiliza uma **Virtual Machine(JVM)**, compilando  os programas para *bytecod*, o que possibilita a filosofia *"Write once, run everywhere"*.

* Possui sintaxe, parecida com com C/C++, mas com menos recursos de baixo nível.

* Apresenta uma extensa biblioteca de classes e o recurso **Garbage Collector**, que facilita o gerenciamento de memória ao liberar de forma automática os objetos que não possuem mais nenhuma referência apontando para eles.

## Encapsulamento

O **encapsulamento** consiste em ocultar o estado interno de um objeto perante o mundo exterior, expondo apenas o mínimo necessário para que os usuários possam usufruir de suas funcionalidades.

* O encapsulamento adequado é obtido com o bom uso dos **modificadores de acesso** (`public`, `protected`, `<default>`, `private`), para se restringir o que não deve ser visto/usado, e permitir acesso ao que pode ser usado.

## Tipos Primitivos vs Objetos (Referências)

No Java, variáveis e atributos podem ser dividos em dois tipos:

* **Tipos Primitivos:** Tipos elementares de dados (como: `int`, `double`, `boolean`, `char`), similares aos tipos nativos do processador e da linguagem C. 

* **Objetos:** Tudo aquilo que é instância de uma classe (incluindo Strings e arrays).Variáveis e atributos cujo tipo é uma classe, são na verdade ponteiros para as instâncias alocadas. No Java estes ponteiros são chamados de **referências**.

Saber esta diferença é especialmente importante para entender o que
acontece na passagem de parâmetros a métodos:

* Tipos primitivos são passados como cópia (parâmetro recebido é uma cópia do valor passado na chamada).
* Objetos são passados como referência, ou seja, ele passa uma copia do endereço da memória onde aquele objeto está.

## Instanciação e Construtores

Ao executar um comando de instanciação como Stack stack = new Stack():

1. **Alocação de memória:** Memória suficiente é alocada para representar o objeto.

2. **Execução do Construtor:** O código do construtor é executado para preparar e inicializar o objeto recém-criado.

3. **Atribuição:** Ao final, o endereço de memória do objeto já inicializado é devolvido e atribuído à variável de referência local.

## Modificadores de Acesso

Eles controlam a visibilidade dos recursos da classe:

* **`public`:** Atributos e métodos visiveis para qualquer classe.

* **`protected`:** Visíveis para classes do mesmo pacote e também para subclasses (mesmo que estejam em pacotes distintos).

* **`<default>` (sem modificador declarado):** Visíveis apenas para classes que pertencem ao mesmo pacote

* **`private`:** Atributos e métodos são visíveis exclusivamente para o código da própria classe que os declarou

### O modificador `static`

* Por padrão, os atributos declarados em uma classe existem de forma independente em cada instância criada.

* O modificador `static` declara um atributo ou método como pertencente à classe, de modo que exista **apenas uma cópia** dessa informação compartilhada por todas as instâncias.

* Métodos `static` são úteis para comportamentos que independem da existência de um objeto específico para atuar (como os métodos utilitários da classe Math). 

* Alerta: O abuso de membros `static` induz a um estilo de programação procedural em vez de orientado a objetos, de forma que o `static` não deve ser frequente em sistemas orientados a objetos bem projetados
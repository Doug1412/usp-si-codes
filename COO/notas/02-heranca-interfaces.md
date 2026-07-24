# Herança e Interfaces

## Herança

A **herança** é um mecanismo que permite a criação de uma nova classe (classe derivada ou subclasse) baseada na declaração de uma classe já existente (classe base ou superclasse).  Os atributos e métodos da classe base são automaticamente incorporados na classe derivada sem a necessidade de copiar e colar código. A subclasse pode estender as funcionalidades da classe base adicionando novos membros ou modificando comportamentos existentes através da sobrescrita de métodos (**overriding**).

As principais vantagens da herança são a facilidade de reutilização de código e a criação de uma hierarquia de tipos que possibilita explorar o **polimorfismo**.

> **Polimorfismo:** refere-se à capacidade de objetos diferentes responderem à mesma instrução cada um a sua maneira

Exemplo:
``` Java
// Superclasse
public class Funcionario {
    protected String nome;
    protected double salario;

    public Funcionario(String nome, double salario) {
        this.nome = nome;
        this.salario = salario;
    }

    public void exibirDados() {
        System.out.println("Nome: " + nome + " | Salário: R$" + salario);
    }
}

// Subclasse
public class Gerente extends Funcionario {
    private String departamento;

    public Gerente(String nome, double salario, String departamento) {
        super(nome, salario); // Chama o construtor da superclasse
        this.departamento = departamento;
    }

    // Sobrescrevendo um método (Polimorfismo)
    @Override
    public void exibirDados() {
        super.exibirDados();
        System.out.println("Departamento: " + departamento);
    }
}
```

**O perigo da Herança:** Ela cria um forte acoplamento (dependência). Ao alterar a classe mãe, todas as classes filhas serão afetadas.

## Interface

Uma **interface** define um conjunto de funcionalidades (métodos) que as classes que a implementam são obrigadas a fornecer. Ela funciona como um contrato: ela especifica o que uma classe deve fazer, mas não como fazer. Interfaces definem uma categoria de classes que compartilham as mesmas operações, permitindo a manipulação polimórfica das instâncias.

Exemplo:
``` Java
// A interface define o contrato
public interface Pagavel {
    void processarPagamento(double valor);
}

// Classe 1 implementando o contrato
public class CartaoCredito implements Pagavel {
    @Override
    public void processarPagamento(double valor) {
        System.out.println("Pagamento de R$" + valor + " aprovado no Cartão de Crédito.");
    }
}

// Classe 2 (totalmente diferente da Classe 1) implementando o mesmo contrato
public class Pix implements Pagavel {
    @Override
    public void processarPagamento(double valor) {
        System.out.println("Transferência PIX de R$" + valor + " realizada com sucesso.");
    }
}
```

## Composição

A **composição** consiste em estabelecer uma relação entre classes em tempo de execução. Em vez de criar uma classe que herda de outra, você cria uma classe que contém uma instância da outra como um atributo.

Exemplo:
``` Java
// O componente (Peça)
public class Motor {
    private int potencia;

    public Motor(int potencia) {
        this.potencia = potencia;
    }

    public void ligar() {
        System.out.println("Motor de " + potencia + " cavalos roncando!");
    }
}

// O todo (Composição)
public class Carro {
    private String modelo;
    private Motor motor; // O Carro "tem um" Motor, mas não "é um" Motor.

    public Carro(String modelo, Motor motor) {
        this.modelo = modelo;
        this.motor = motor;
    }

    public void darPartida() {
        System.out.println("Iniciando o " + modelo + "...");
        motor.ligar(); // Delegando a ação para o componente
    }
}
```

## Lembretes e regras de Sintaxe do Java

* **`super`:** É uma palavra chave analoga ao `this`, mas referes-e estritamente aos membros da superclasse.

* **Herança Simples:** Na linguagem Java, toda classe possui apenas uma superclasse direta. Não existe herança múltipla de classes (como ocorre em C++)

* **Classe `Object`:** Qualquer classe que não declare explicitamente uma superclasse herda implicitamente de `Object`. É por isso que todas as classes em Java possuem métodos como `toString()`, `equals()` e `clone()`.

* **`abstract`:** Classes ou métodos declarados como abstratos definem lacunas/lacunas de comportamento na superclasse que devem ser preenchidas obrigatoriamente pelas subclasses concretas para que o código compile. Uma classe abstrata não pode ser instanciada diretamente (tentar executar new Produto() em uma classe abstrata gera erro de compilação).

* **`final`**: 
    * **Classe final:** Uma classe marcada como final não pode ser herdada. A classe String do Java é o maior exemplo disso (ninguém pode fazer class MinhaString extends String).
    * **Método final:** Um método marcado como final não pode ser sobrescrito (@Override) pelas subclasses. Garante que o comportamento original seja preservado.

* **Herança ou Composição:** 
    * A classe A é um tipo específico de B? (Ex: Gerente é um Funcionario) -> Usar Herança.
    * A classe A tem um B para funcionar? (Ex: Carro tem um Motor) -> Usar Composição.
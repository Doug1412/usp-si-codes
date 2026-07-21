// Modificação do exemplo TesteLista1, em que é feito
// o uso de interfaces visando eliminar a redundância de 
// código presente nos métodos que filtram os elementos 
// da lista, além de melhorar muito a extensibilidade da 
// estrutura no que diz respeito a criação de novos 
// critérios de filtragem.

class Lista {

	private int [] a;
	private int livre;

	public Lista(int max){

		a = new int[max];
		livre = 0;
	}

	public Lista(int [] v){

		a = new int[v.length];
		livre = 0;
		
		for(int i : v) adiciona(i);
	}

	public void adiciona(int i){

		a[livre] = i;
		livre++;
	}

	public void imprime(){

		System.out.print("lista:");

		for(int i = 0; i < livre; i++){

			System.out.print(" " + a[i]);
		}

		System.out.println();
	}

	// Nesta versão tem-se apenas um método para filtrar
	// os elementos. O critério que define se um elemento 
	// deve ou não ser adicionado na resposta esta implementado
	// no objeto "crit", do tipo "Criterio".
	//
	// "Criterio" é uma interface, ou seja, define qual
	// o conjunto de métodos que deve ser oferecido por 
	// uma classe concreta que implementa um determinado 
	// critério de filtragem. Assim, "Critério" é supertipo
	// de todas as classes que implementam algum critério e
	// isso permite que o método filtra possa trabalhar com
	// variadas implementações de critérios, sem conhecer de 
	// fato o tipo real do objeto recebido como argumento
	// do método.  

	public Lista filtra(Criterio crit){

		Lista res = new Lista(a.length);

		for(int i = 0; i < livre; i++){

			if(crit.verifica(a[i])) res.adiciona(a[i]);
		}

		return res;
	}

}

// Interface "Critério". Define o conjunto de métodos que 
// uma classes que implementa um critério deve disponibilizar.
// Note que não existe implementação. Podemos dizer, portanto,
// que a interface define uma "categoria" de objetos e o que eles
// "devem" fazer, mas não "como" fazer. O "como" fazer fica a cargo
// das classes que implementam cada um dos critérios.
//
// Observe que, apesar de todas as classes que definem algum
// tipo de critério possuirem o método "verifica", a implementação
// de cada critério específico varia muito. Assim, neste exemplo,
// usar interface para definir um supertipo comum é muito mais 
// adequado do que usar herança. Herança só é indicado, se as 
// subclasses podem de fato aproveitar alguma implementação existente
// na superclasse (o que claramente não aconteceria neste exemplo).

interface Criterio {

	// Uma instancia de critério recebe um valor x
	// e devolve um boolean indicando se x deve ou não
	// ser adicionado na sublista resposta.

	public boolean verifica(int x);
}

// Implementação de um critério para filtrar os elementos pares

class Pares implements Criterio {

	public boolean verifica(int x){

		return (x % 2 == 0);
	}
}

// Implementação de um critério para filtrar os elementos iguais a zero

class Zeros implements Criterio {

	public boolean verifica(int x){

		return (x == 0);
	}
}

// Implementação de um critério para filtrar os elementos maiores que um certo valor

class MaioresOuIguais implements Criterio {

	private int k;

	public MaioresOuIguais(int k){

		this.k = k;
	}

	public boolean verifica(int x){

		return (x >= k);
	}
}

// Implementação de um critério para filtrar os elementos menores que um certo valor

class MenoresQue implements Criterio {

	private int k;

	public MenoresQue(int k){

		this.k = k;
	}

	public boolean verifica(int x){

		return (x < k);
	}
}

// Perceba que os criterios Pares e Zeros são casos particulares dos
// critérios mais gerais a seguir (e, portanto, com maior potencial de
// reutilização). Tente reescrever, como exercício, o as classes Pares
// e Zeros a partir dos critérios mais gerais abaixo:

class Igual implements Criterio {

	private int k;

	public Igual(int k){
	
		this.k = k;
	}

	public boolean verifica(int x){

		return x == k;
	}
}

class RestoDivZero implements Criterio {

	private int k;

	public RestoDivZero(int k){
	
		this.k = k;
	}

	public boolean verifica(int x){

		return x % k == 0;
	}
}

// Indo um pouco mais além, e aplicando também o conceito de composição,
// podemos implementar critérios compostos por outros critérios, como os
// abaixo:

class Not implements Criterio {

	private Criterio c;

	public Not(Criterio c){

		this.c = c;
	}

	public boolean verifica(int x){

		return !c.verifica(x);
	}
}

class And implements Criterio {

	private Criterio c1;
	private Criterio c2;

	public And(Criterio c1, Criterio c2){

		this.c1 = c1;
		this.c2 = c2;
	}

	public boolean verifica(int x){

		return c1.verifica(x) && c2.verifica(x);
	}
}

class Or implements Criterio {

	private Criterio c1;
	private Criterio c2;

	public Or(Criterio c1, Criterio c2){

		this.c1 = c1;
		this.c2 = c2;
	}

	public boolean verifica(int x){

		return c1.verifica(x) || c2.verifica(x);
	}
}

// Observe que com um conjunto básico de criterios (Igual, RestoDivZero, MaioresOuIguais, Menores)
// e os critérios booleanos que são compostos por outros critérios, é possível criar uma variadade
// indefinida de novos critérios. Quando definimos de critérios através da composição de outros critérios 
// é como se novas classes fossem criadas dinamicamente em tempo de execução, mas sem que novas classes
// sejam criadas de fato. O vinculo entre diversos criterios que se estabelece para compor um novo criterio
// acontece apenas em tempo de execução (ou seja, é algo dinâmico), não é um vinculo estático que está 
// declarado em código (como o que acontece entre uma classe base e uma classe derivada). É por isso
// que dizemos que composição é uma alternativa mais flexível do que a herança (além de permitir a
// obtenção do mesmo resultado em termos de funcionalidade). Questão para pensar: seria possível a 
// criação de um conjunto abrangente de critérios distintos usando apenas herança?

// Programa de teste

public class TesteLista2 {

	public static void main(String [] args){

		int [] v = { 7, 0, 3, 2, 1, 4, 8, 9, 6, 5, 9, 3, 4, 1, 2, 3, 3, 5, 0, 3, 2, 3, 4, 0 };

		Lista l, res;

		l = new Lista(v);
		l.imprime();

		res = l.filtra(new Pares());
		res.imprime();

		res = l.filtra(new Zeros());
		res.imprime();

		res = l.filtra(new MaioresOuIguais(5));
		res.imprime();

		res = l.filtra(new MenoresQue(6));
		res.imprime();

		res = l.filtra(new Not(new Zeros()));
		res.imprime();

		res = l.filtra(new Or(new And(new RestoDivZero(2), new RestoDivZero(3)), new MaioresOuIguais(7)));
		res.imprime();

		System.out.println("---------------------------------------------------------");
	}
}

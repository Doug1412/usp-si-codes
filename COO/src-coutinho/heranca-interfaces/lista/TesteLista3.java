// Tentativa de resolução o mesmo problema, mas usando herança.
// Este exemplo é mais usado como um exercício de como resolver
// o mesmo problema usando uma abordagem alternativa, uma vez que
// são bastantes perceptíveis as limitações que esta abordagem
// possui quando comparada à versão que emprega interface.
// 
// Embora a questão da redundância de código seja resolvida,
// esta solução é bem menos flexível que a versão baseada
// em interface.

abstract class ListaAbstrata { // Esta classe é abstratra pois ela não é uma classe completa. 
			       // Há uma 'lacuna' (método abstrato) a ser preenchida.

	private int [] a;
	private int livre;

	public ListaAbstrata(int max){

		a = new int[max];
		livre = 0;
	}

	public ListaAbstrata(int [] v){

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

	public ListaAbstrata filtra(){

		// Não é legal ter que fixar o tipo da lista que
		// guarda os valores selecionados pela filtragem
		// pois isso determinará qual tipo de filtragem
		// a lista devolvida como resposta irá suportar.
		// Contudo, não parece haver uma solução simples
		// em relação a isto...

		ListaAbstrata res = new Lista(a.length); 

		for(int i = 0; i < livre; i++){

			if(seleciona(a[i])) res.adiciona(a[i]);
		}

		return res;
	}

	public abstract boolean seleciona(int x); // A 'lacuna' a ser preenchida pelas subclasses.
						  // Cada subclasse irá implementar um critério
						  // próprio de filtragem. 

}

// Cada tipo concreto de lista só será capaz de executar
// a filtragem de seus elementos por um critério fixo!
// Não é possível escolher o tipo de critério usado para
// cada chamada do método 'filtra()'.

class Lista extends ListaAbstrata {

	public Lista(int max){

		super(max);
	}

	public boolean seleciona(int x){

		return true;
	}
}

class ListaFiltraPares extends ListaAbstrata {

	public ListaFiltraPares(int [] v){

		super(v);
	}

	public boolean seleciona(int x){

		return (x % 2 == 0);
	}
}

class ListaFiltraZeros extends ListaAbstrata {

	public ListaFiltraZeros(int [] v){

		super(v);
	}

	public boolean seleciona(int x){

		return (x == 0);
	}
}

class ListaMaioresOuIguais extends ListaAbstrata {

	private int k;

	public ListaMaioresOuIguais(int [] v, int k){

		super(v);
		this.k = k;
	}

	public boolean seleciona(int x){

		return (x >= k);
	}
}

class ListaMenoresQue extends ListaAbstrata {

	private int k;

	public ListaMenoresQue(int []v, int k){

		super(v);
		this.k = k;
	}

	public boolean seleciona(int x){

		return (x < k);
	}
}

// Programa de teste

public class TesteLista3 {

	public static void main(String [] args){

		int [] v = { 7, 0, 3, 2, 1, 4, 8, 9, 6, 5, 9, 3, 4, 1, 2, 3, 3, 5, 0, 3, 2, 3, 4, 0 };

		ListaAbstrata l, res;

		l = new ListaFiltraPares(v);
		l.imprime();

		res = l.filtra();
		res.imprime();

		// Uma vez que uma lista esteja instanciada, nunca mais podemos solicitar a filtragem
		// por um critério diferente daquele que ela "sabe" fazer. Desta forma, sempre que 
		// desejarmos fazer a filtragem por um novo critério, seremos obrigados a instanciar 
		// uma nova lista (de acordo com o critério desejado).

		l = new ListaFiltraZeros(v);
		res = l.filtra();
		res.imprime();

		l = new ListaMaioresOuIguais(v, 5);
		res = l.filtra();
		res.imprime();

		l = new ListaMenoresQue(v, 6);
		res = l.filtra();
		res.imprime();

		System.out.println("---------------------------------------------------------");
	}
	
}

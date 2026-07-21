// Motivção para um exemplo sobre interfaces: a classe
// Lista que implementa uma coleção de elementos do tipo
// inteiro, organizados internamente em um vetor (array).
// A classe Lista oferece uma série de métodos que devolvem
// sublistas a partir de determinados critérios. Note que
// os metodos que filtram os elementos a partir de um certo
// critério são quase idênticos, com exceção da condição
// que testa se um elemento deve ou não fazer parte da sublista.
// Este exemplo é um cenário tipico onde o uso de interfaces
// pode ser benéfico.

class Lista {

	private int [] a;
	private int livre;

	public Lista(int max){

		a = new int[max];
		livre = 0;
	}

	public Lista(int [] v){

		this(v.length); // chama o outro construtor que aloca o vetor

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

	public Lista filtraPares(){
	
		Lista res = new Lista(a.length);

		for(int i = 0; i < livre; i++){

			if(a[i] % 2 == 0) res.adiciona(a[i]);
		}

		return res;
	}

	public Lista filtraZeros(){

		Lista res = new Lista(a.length);

		for(int i = 0; i < livre; i++){

			if(a[i] == 0) res.adiciona(a[i]);
		}

		return res;
		
	}


	public Lista filtraMaioresOuIguais(int x){

		Lista res = new Lista(a.length);

		for(int i = 0; i < livre; i++){

			if(a[i] >= x) res.adiciona(a[i]);
		}

		return res;		
	}

	public Lista filtraMenoresQue(int x){

		Lista res = new Lista(a.length);

		for(int i = 0; i < livre; i++){

			if(a[i] < x) res.adiciona(a[i]);
		}

		return res;		
	}
}

// Programa de teste

public class TesteLista1 {

	public static void main(String [] args){

		int [] v = { 7, 0, 3, 2, 1, 4, 8, 9, 6, 5, 9, 3, 4, 1, 2, 3, 3, 5, 0, 3, 2, 3, 4, 0 };

		Lista l, res;

		l = new Lista(v);
		l.imprime();

		res = l.filtraPares();
		res.imprime();

		res = l.filtraZeros();
		res.imprime();

		res = l.filtraMaioresOuIguais(5);
		res.imprime();

		res = l.filtraMenoresQue(6);
		res.imprime();

		System.out.println("---------------------------------------------------------");
	}
}


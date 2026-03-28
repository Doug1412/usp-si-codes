class Pessoa{

	int id;
	String nome;
	String endereco;

	// Construtor adequado para a classe Pessoa

	Pessoa(int id, String nome, String endereco) {

		this.id = id;
		this.nome = nome;
		this.endereco = endereco;
	}
}

class TestePessoa{

	public static void main(String [] args){

		// Instanciando os objetos do tipo pessoa através do construtor...

		Pessoa p1 = new Pessoa(1234, "Pedro", "Rua A, numero 10");
		Pessoa p2 = new Pessoa(2345, "Maria", "Rua B, numero 20");

		// Mas isso aqui ainda não está legal...

		System.out.println("Pessoa: id = " + p1.id + ", nome = " + p1.nome + ", endereco = " + p1.endereco);
		System.out.println("Pessoa: id = " + p2.id + ", nome = " + p2.nome + ", endereco = " + p2.endereco);
	}
}

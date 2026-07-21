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

	// método que imprime as informações do objeto 

	void imprimeInfo(){

		System.out.println("Pessoa: id = " + this.id + ", nome = " + this.nome + ", endereco = " + this.endereco);
	} 
}

class TestePessoa{

	public static void main(String [] args){

		// Instanciando os objetos do tipo pessoa através do construtor...

		Pessoa p1 = new Pessoa(1234, "Pedro", "Rua A, numero 10");
		Pessoa p2 = new Pessoa(2345, "Maria", "Rua B, numero 20");

		// E executando as chamadas do método responsável por imprimir as informações dos objetos criados...

		p1.imprimeInfo(); 
		p2.imprimeInfo();
	}
}

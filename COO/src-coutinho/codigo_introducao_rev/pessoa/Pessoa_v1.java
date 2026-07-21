class Pessoa{

	int id;
	String nome;
	String endereco;
}

class TestePessoa{

	public static void main(String [] args){

		// Como não instanciar objetos de uma classe...

		Pessoa p1 = new Pessoa();
		Pessoa p2 = new Pessoa();

		p1.id = 1234;
		p1.nome = "Pedro";
		p1.endereco = "Rua A, numero 10";

		p2.id = 2345;
		p2.nome = "Maria";
		p2.endereco = "Rua B, numero 20";
		
		System.out.println("Pessoa: id = " + p1.id + ", nome = " + p1.nome + ", endereco = " + p1.endereco);
		System.out.println("Pessoa: id = " + p2.id + ", nome = " + p2.nome + ", endereco = " + p2.endereco);
	}
}

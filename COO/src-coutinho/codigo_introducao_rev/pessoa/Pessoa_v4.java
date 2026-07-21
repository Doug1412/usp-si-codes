class Pessoa{

	// Melhorando ainda mais: restringindo a visibilidade dos atributos...
	
	private int id;
	private String nome;
	private String endereco;

	// Construtor adequado para a classe Pessoa

	public Pessoa(int id, String nome, String endereco) {

		this.id = id;
		this.nome = nome;
		this.endereco = endereco;
	}

	// método que imprime as informações do objeto 

	public void imprimeInfo(){

		System.out.println("Pessoa: id = " + this.id + ", nome = " + this.nome + ", endereco = " + this.endereco);
	} 

	// getter e setter para acessar / modificar o endereco
	// (assumindo que os "usuários" classe Pessoa precisam 
	// ser capazes de acessar / modificar o valor de tal atributo).

	public String getEndereco(){

		return this.endereco;
	}

	public void setEndereco(String endereco){

		this.endereco = endereco;
	}

	// getters para os atributos id e nome. Estamos assumindo
	// que "usuários" da classe pessoam precisam ter acesso à
	// estes atributos, mas não podem modificar os valores dos
	// mesmos.

	public int getId(){

		return this.id;
	}

	public String getNome(){

		return this.nome;
	}  
}

class TestePessoa{

	public static void main(String [] args){

		// Instanciando os objetos do tipo pessoa através do construtor...

		Pessoa p1 = new Pessoa(1234, "Pedro", "Rua A, numero 10");
		Pessoa p2 = new Pessoa(2345, "Maria", "Rua B, numero 20");

		// E executando as chamadas de método responsáveis por imprimir as informações dos objetos criados...

		p1.imprimeInfo(); 
		p2.imprimeInfo();

		// atualizando os ids...

		System.out.println("redefinindo endereço para '" + p1.getNome() + "' (id = " + p1.getId() + ")" );
		p1.setEndereco("Rua C, numero 30");

		System.out.println("redefinindo endereço para '" + p2.getNome() + "' (id = " + p2.getId() + ")");
		p2.setEndereco("Rua D, numero 40");

		// imprimindo novamente as informações referentes a cada objeto...

		p1.imprimeInfo(); 
		p2.imprimeInfo();
	}
}

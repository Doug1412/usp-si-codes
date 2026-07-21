// Esta versão visa atingir o mesmo objetivo dos exemplos anteriores,
// porém sem empregar o uso de herança. Isto é conseguido através do 
// uso composição combinado ao uso de interfaces. Note que para o 
// "cliente/usuário" das classes que representam produtos (ou seja, o 
// método 'main' no caso do nosso exemplo), praticamente nada mudou em 
// relação ao exemplo anterior.

// Interface comum a todos os produtos, para permitir a manipulação
// polimórfica de produtos. Define o conjunto de funcionalidades
// básicas que qualquer produto deve possuir.

interface IProduto {

	public String getDescricao();
	public double getPreco();
	public void setPreco(double d);
}

// Classe que implementa o "produto básico".

class Produto implements IProduto{

	private String descricao;
	private double preco;

	public Produto(String descricao, double preco){

		this.descricao = descricao;
		this.preco = preco;
	}

	public String getDescricao(){

		return descricao;
	}

	public double getPreco(){

		return preco;
	}

	public void setPreco(double d){

		preco = d;
	}
}

// Classe que implementa a contagem de chamadas a 'setPreco(...)', além 
// de possuir as funcionalidades mínimas de um "produto básico". Observe,
// contudo, que não foi empregado o mecanismo de herança para fazer com 
// que 'ProdutoContador' recebesse por herança as funcionalidades de 'Produto'.
//
// Ao invés disso, foi usada composição, para incorporar as funcionalidades
// de um produto qualquer dentro da classe 'ProdutoContador'. Essencialmente,
// a classe 'ProdutoContador' mantem uma referência para uma instância do tipo
// 'IProduto' (que neste exemplo é instanciada no ato da execução do construtor,
// mas que poderia ter sido recebida já pronta como parâmetro do construtor, ou 
// ainda recebida através de algum outro método), que é responsável por fornecer
// os comportamentos "básicos" de um produto.

class ProdutoContador implements IProduto{

	private IProduto p; // É aqui que a composição acontece! 
	private int contador;

	public ProdutoContador(String descricao, double preco){

		p = new Produto(descricao, preco);
		contador = 0;
	}

	public String getDescricao(){

		// delegando a execução de 'getDescricao()' à referencia
		// 'p' mantida por esta instância de 'ProdutoContador'.

		return p.getDescricao(); 
	}

	public double getPreco(){

		// idem para 'getPreco()'

		return p.getPreco();
	}

	public void setPreco(double d){

		// idem para 'setPreco(...)', juntamente com o 
		// implementação que, de fato, estende o comportamento
		// original (mas sem usar herança).

		p.setPreco(d);
		contador++;
	}

	public int getContador(){

		return contador;
	}
}

class TesteProduto {

	// O único impacto para esta classe, que está no papel de "usuária"
	// das classes Produto e ProdutoContador, foi a mudança dos tipos das 
	// variáveis/parâmetros de 'Produto' para 'IProduto', uma vez que o 
	// topo de hierarquia de classes/interfaces associadas aos produtos 
	// mudou de nome. Tirando este detalhe, a mudança realizada na estrutura
	// das classes foi totalmente transparente para quem está no papel de
	// "usuários" destas classes, o que é ótimo!

	public static void aplicaDesconto(IProduto p, int desconto){

		double d = (100 - desconto) / 100.0;

		p.setPreco(p.getPreco() * d);
	}

	public static void processaProduto(IProduto p){

		System.out.println("----------------------------------------------------------");
	

		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
		aplicaDesconto(p, 10);
		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
		aplicaDesconto(p, 20);
		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
	}

	public static void main(String [] args){

		IProduto [] produtos = new IProduto[3];

		produtos[0] = new ProdutoContador("Notebook", 2000.00);
		produtos[1] = new ProdutoContador("Teclado", 100.00);
		produtos[2] = new Produto("Monitor", 400.00);

		for(IProduto p : produtos){

			processaProduto(p);

			if(p instanceof ProdutoContador){

				ProdutoContador pc = (ProdutoContador) p;
				System.out.println("Contador de atualizações = " + pc.getContador());
			}
		}
	}
}


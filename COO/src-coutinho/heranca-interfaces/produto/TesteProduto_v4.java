// Melhorias sobre a versão que emprega composição para torná-la
// mais flexível, permitindo anexar a um 'Produto' mais de uma 'camada'
// que extende seu comportamento de alguma forma. Esta nova versão aplica 
// o que é conhecido como o Padrão Decorator (Decorador), um conhecido
// Padrão de Projeto.

// Interface comum a todos os produtos, para permitir a manipulação
// polimórfica de produtos. Define o conjunto de funcionalidades
// básicas que qualquer produto deve possuir.

interface IProduto {

	public String getDescricao();
	public double getPreco();
	public void setPreco(double d);
}

// Interface comum a todos as classes que implementam decoradores.
// Ou seja, atuam como uma camada extra de funcionalidade que pode 
// ser anexada sobre um IProduto.

interface Decorador {

	public IProduto getDecorado();	// este devolve a referência ao objeto produto 
					//sendo decorado pelo objeto decorador.
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

class ProdutoContador implements IProduto, Decorador{

	private IProduto p; 
	private int contador;

	// Note que o construtor não mais instancia atributo p.
	// A instância de IProduto a ser decorada já é recebida
	// 'pronta' pelo construtor.

	public ProdutoContador(IProduto p){

		this.p = p;
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

	public IProduto getDecorado(){

		return p;
	}
}

// Aproveitando o embalo desta nova versão do exemplo que implementa o
// Padrão Decorator, vamos criar uma outra classe que também estende,
// de maneira diferente, o comportamento do método 'setPreco'.

class ProdutoMinMax implements IProduto, Decorador {

	private IProduto p; 
	private double menorPreco, maiorPreco;

	// Note que o construtor não mais instancia atributo p.
	// A instância de IProduto a ser decorada já é recebida
	// 'pronta' pelo construtor.

	public ProdutoMinMax(IProduto p){

		this.p = p;
		this.menorPreco = this.maiorPreco = this.p.getPreco();
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
		menorPreco = p.getPreco() < menorPreco ? p.getPreco() : menorPreco;
		maiorPreco = p.getPreco() > maiorPreco ? p.getPreco() : maiorPreco;
	}

	public double getMenorPreco(){

		return menorPreco;
	}

	public double getMaiorPreco(){

		return maiorPreco;
	}

	public IProduto getDecorado(){

		return p;
	}
}

class TesteProduto {

	public static void aumentaPreco(IProduto p, double aumentoAbsoluto){

		p.setPreco(p.getPreco() + aumentoAbsoluto);
	}

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
		aumentaPreco(p, 400);
		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
	}

	public static void main(String [] args){

		IProduto [] produtos = new IProduto[4];

		produtos[0] = new Produto("PS5", 4800.00);
		produtos[1] = new ProdutoMinMax(new ProdutoContador(new Produto("Notebook", 2000.00)));
		produtos[2] = new ProdutoContador(new Produto("Teclado", 100.00));
		produtos[3] = new ProdutoMinMax(new Produto("Monitor", 400.00));

		for(IProduto p : produtos){

			processaProduto(p);

			while(p instanceof Decorador){

				if(p instanceof ProdutoContador){

					ProdutoContador pc = (ProdutoContador) p;
					System.out.println("O preço deste produto foi atualizado " + pc.getContador() + " vezes");
				}

				if(p instanceof ProdutoMinMax){

					ProdutoMinMax pmm = (ProdutoMinMax) p;
					System.out.println("Menor preço que o produto já teve: R$" + pmm.getMenorPreco());
					System.out.println("Maior preço que o produto já teve: R$" + pmm.getMaiorPreco());
				}

				p = ((Decorador)p).getDecorado();
			}
		}
	}
}


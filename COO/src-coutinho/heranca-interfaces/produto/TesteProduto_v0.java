// Solução "copy e paste" para a criação da nova variação da classe Produto... certamente não é uma boa ideia.

class Produto {

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

// Note a redundância de código que existente nas classes Produto e ProdutoContador

class ProdutoContador {

	private String descricao;
	private double preco;
	private int contador;

	public ProdutoContador(String descricao, double preco){

		this.descricao = descricao;
		this.preco = preco;
		this.contador = 0;
	}

	public String getDescricao(){

		return descricao;
	}

	public double getPreco(){

		return preco;
	}

	public void setPreco(double d){

		preco = d;
		contador++;
	}

	public int getContador(){

		return contador;
	}
}

class TesteProduto {

	// Este método funciona apenas para objetos do tipo Produto.
	// Para funcionar com a nova classe, teríamos que criar uma
	// nova versão (identica) deste método mas recebendo como
	// parâmetro um objeto do tipo ProdutoContador. Perceba como,
	// se insistirmos nesta ideia, a redundancia de código irá
	// envolver não só a nova classe, mas todo o código já existente 
	// que usa a versão inicial da classe Produto.

	public static void aplicaDesconto(Produto p, int desconto){

		double d = (100 - desconto) / 100.0;

		p.setPreco(p.getPreco() * d);
	}

	// Idem para este metodo.

	public static void processaProduto(Produto p){

		System.out.println("----------------------------------------------------------");	

		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
		aplicaDesconto(p, 10);
		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
		aplicaDesconto(p, 20);
		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
	}

	public static void main(String [] args){

		// O metodo main tambem seria afetado. Teriamos que usar arrays 
		// diferentes para guardar os objetos dois dois tipos de produto,
		// e replicar o for também.

		Produto [] produtos = new Produto[3];

		produtos[0] = new Produto("Notebook", 2000.00);
		produtos[1] = new Produto("Teclado", 100.00);
		produtos[2] = new Produto("Monitor", 400.00);

		for(Produto p : produtos){

			processaProduto(p);
		}
	}
}


// Código base para discussão do exemplo envolvendo herança.

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

class TesteProduto {

	public static void aplicaDesconto(Produto p, int desconto){

		double d = (100 - desconto) / 100.0;

		p.setPreco(p.getPreco() * d);
	}

	public static void processaProduto(Produto p){

		System.out.println("----------------------------------------------------------");
	
		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
		aplicaDesconto(p, 10);
		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
		aplicaDesconto(p, 20);
		System.out.println("Produto: " + p.getDescricao() + " --- R$" + p.getPreco());
	}

	public static void main(String [] args){

		Produto [] produtos = new Produto[3];

		produtos[0] = new Produto("Notebook", 2000.00);
		produtos[1] = new Produto("Teclado", 100.00);
		produtos[2] = new Produto("Monitor", 400.00);

		for(Produto p : produtos){

			processaProduto(p);
		}
	}
}


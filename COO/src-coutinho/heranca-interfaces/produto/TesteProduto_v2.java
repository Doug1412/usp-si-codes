// Uma solução melhor usando herança para a criação da nova variação da classe Produto.

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

// Nesta versão mantemos o 'preco' da superclasse como private, evitando uma brecha
// de encapsulamento. Mas como iremos atualizar o preço na chamada a 'setPreco(...)'
// se o atributo da superclasse é privado, e portanto não pode ser acessado por qualquer
// outra classe?
//
// É simples, basta utilizar o setter para o preço já existente na super classe. Assim, 
// reutilizamos a implementação responsável por atribuir um novo valor ao atributo 'preco',
// ao invés de reimplementar tal funcionalidade. Fazemos isso invocando o método 'setPreco(...)' 
// da superclasse usando a palavra chave "super" para indicar que desejamos executar a versão 
// de um método declarada especificamente na superclasse. A grande vantagem em chamar o método 
// da superclasse é evitar a redundância na implementação da funcionalidade de atualização de 
// preço. Se no futuro o processo pelo qual o preço de um produto é atualizado sofrer mudanças, 
// as atualizações estarão restritas ao método 'setPreco(...)' da superclasse (pois o método 
// 'setPreco(...)' desta subclasse delega a tarefa de atualização de preço propriamente dita à
// superclasse e o trabalho efetivamente realizado pela implementação desta classe consiste apenas
// em incrementar o contador).   

class ProdutoContador extends Produto {

	private int contador;

	public ProdutoContador(String descricao, double preco){

		super(descricao, preco);
	}
	
	public void setPreco(double d){

		super.setPreco(d); // reaproveitamos funcionalidade da superclasse ao invés de reimplementá-la.
		contador++;
	}

	public int getContador(){

		return contador;
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
		produtos[1] = new ProdutoContador("Teclado", 100.00);
		produtos[2] = new ProdutoContador("Monitor", 400.00);

		for(Produto p : produtos){

			processaProduto(p);

			if(p instanceof ProdutoContador){

				ProdutoContador pc = (ProdutoContador) p;
				System.out.println("Contador de atualizações = " + pc.getContador());
			}
		}
	}
}


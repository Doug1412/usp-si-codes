// Uma solução usando herança (ainda sujeita a melhorias) para a criação da nova variação da classe Produto.

class Produto {

	private String descricao;
	protected double preco;

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

// O mecanismo de herança pode ser usado quando queremo criar um novo tipo (subclasse) 
// a partir de um outro já existente (classe base, ou superclasse), geralmente para
// adicionar novos comportamentos, ou fazer a alteração pontual de comportamentos já 
// existentes. Note que, não faz muito sentido usar herança em cenários em que praticamente
// todo o comportamento já existente (e herdado) pela subclasse deve ser alterado. Nestes 
// casos, usar interfaces provavelmente é um caminho melhor.
// 
// No exemplo abaixo, a classe ProdutoContador estende a classe Produto, para modificar um 
// comportamento herdado. Em particular, queremos que um ProdutoContador mantenha um atributo
// 'contador' que indique a quantidade de vezes que o método 'setPreco(...)' é chamado. Para 
// implementar este comportamento, o método 'setPreco(...)' é sobreescrito para, além de atualizar 
// o atributo 'preco' também incrementar o novo atributo 'contador'.
//
// Para que seja possível a reimplementação do método 'setPreco(...)' atualizar o valor do
// atributo 'preco', precisamos modificar o grau de visibilidade deste atributo na super 
// classe de 'private' para 'protected' (para se tornar visível nas subclasses). Isso, não 
// é muito interssante pois, além de se tornar visível nas subclasses de Produto, o atributo 
// também passa a ser visível nas classes 'vizinhas' (ou seja, percentences ao mesmo pacote) 
// que é o caso da classe de teste. Esta solução, portanto, apesar de funcionar e já ilustrar
// alguns beneficios do mecanismo de herança (afinal esta versão é muito superior à solução
// "copy e paste"), apresenta uma brecha no que diz respeito ao encapsulamento da classe Produto.

class ProdutoContador extends Produto {

	private int contador; // novo atributo necessário na subclasse para implementar a nova funcionalidade.
	
	public ProdutoContador(String descricao, double preco){

		super(descricao, preco); // chamada ao construtor da superclasse para iniciar os atributos 'descricao' e 'preco'.
		contador = 0;
	}

	// Sobreescrita do método 'setPreco(...)'. Quando este método for 
	// chamado em uma instância desta classe é esta versão do método
	// que será executada (e não a versão herdada).

	public void setPreco(double d){

		preco = d; // perceba que nesta linha há redundância de implementação em relação ao 'setPreco(...)' da superclasse.
		contador++;
	}
	
	// Um getter para o novo atributo criado, específico desta subclasse. 

	public int getContador(){

		return contador;
	}
}

class TesteProduto {

	// Os dois metodos abaixo irão funcionar tanto para objetos do tipo
	// Produto, quanto ProdutoContador. Para estes dois métodos, é irrelevante
	// saber qual o tipo real do objeto recebido. Basta saber que é (ao menos)
	// um Produto. Perceba ainda que, mesmo que o método não saiba qual o tipo
	// exato do Produto recebido, quando este for ProdutoContador, a nova 
	// funcionalidade particular deste subtipo será executada. Logo os efeitos
	// concretos da execução destes métodos pode variar de acordo com o tipo
	// concreto do objeto recebido.

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

		// Como objetos do tipo ProdutosContador também são do tipo Produto, podemos
		// misturar ambos os tipos em um array de Produto. Isso facilita a manipulação
		// uniforme de objetos de tipos diferentes.

		Produto [] produtos = new Produto[3];

		produtos[0] = new ProdutoContador("Notebook", 2000.00);
		produtos[1] = new Produto("Teclado", 100.00);
		produtos[2] = new ProdutoContador("Monitor", 400.00);

		for(Produto p : produtos){

			processaProduto(p);

			// Teste para verificar se, em uma execução arbitrária do laço, o objeto p
			// é um ProdutoContador. Caso seja, realizamos a conversão de tipo para que
			// seja possível utilizar a funcionalidade exclusiva do subtipo. 

			if(p instanceof ProdutoContador){

				ProdutoContador pc = (ProdutoContador) p;
				System.out.println("Contador de atualizações = " + pc.getContador());
			}
		}
	}
}


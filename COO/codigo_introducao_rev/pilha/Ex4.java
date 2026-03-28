import java.util.*;

class Stack {

	int [] values;
	int free;

	Stack(){

		values = new int[100];
		free = 0;
	}

	void push(int value){

		values[free] = value;
		free++;
	}

	int pop(){

		free--;
		return values[free];
	}

	boolean empty(){

		return free == 0;
	}
}

class Ex4 {

	public static void main(String [] args){

		int value;
		Stack stack = new Stack();		
		Scanner scanner = new Scanner(System.in);

		while( (value = scanner.nextInt()) > 0){

			stack.push(value);	
		}

		System.out.print("Conteudo em ordem reversa:");
	
		while(!stack.empty()) {

			value = stack.pop();
			System.out.print(" " + value);
		}

		System.out.println();
	}
}

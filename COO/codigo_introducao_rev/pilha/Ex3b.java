import java.util.*;

class Stack {

	int [] values;
	int free;
}

class Ex3b {

	static void init(Stack stack){

		stack.values = new int[100];
		stack.free = 0;
	}

	static void push(Stack stack, int value){

		stack.values[stack.free] = value;
		stack.free++;
	}

	static int pop(Stack stack){

		stack.free--;
		return stack.values[stack.free];	
	}

	static boolean empty(Stack stack){

		return stack.free == 0;
	}

	public static void main(String [] args){
	
		int value;
		Stack stack = new Stack();
		Scanner scanner = new Scanner(System.in);
	  
		init(stack);
	  
		while( (value = scanner.nextInt()) > 0){
	    
			push(stack, value);	
	  	}
	  
		System.out.print("Conteudo em ordem reversa:");
	  
		while(!empty(stack)) {
    
			value = pop(stack);
	    		System.out.print(" " + value);
	  	}
	
		System.out.println();
	}
}

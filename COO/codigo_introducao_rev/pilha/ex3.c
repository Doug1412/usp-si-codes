#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int values[100];
	int free;

} Stack;

void init(Stack * stack){

	stack->free = 0;
}

void push(Stack * stack, int value){

	stack->values[stack->free] = value;
	stack->free++;
}

int pop(Stack * stack){

	stack->free--;
	return stack->values[stack->free];	
}

int empty(Stack * stack){

	return stack->free == 0;
}

int main(){
	
	Stack * stack = (Stack *) malloc(sizeof(Stack));
	int value;
  
	init(stack);
  
	while(scanf("%d", &value) == 1 && value > 0){
    
		push(stack, value);	
  	}
  
	printf("Conteudo em ordem reversa:");
  
	while(!empty(stack)) {
    
		value = pop(stack);
    		printf(" %d", value);
  	}
	
	printf("\n");
	return 0;
}

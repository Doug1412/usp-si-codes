#include <stdio.h>

void push(int * stack, int * free, int value){

	stack[*free] = value;
	(*free)++;
}

int pop(int * stack, int * free){

	(*free)--;
	return stack[*free];	
}

int empty(int * stack, int * free){

	return *free == 0;
}

int main(){
	
	int stack[100];
	int free = 0;
	int value;

	while(scanf("%d", &value) == 1 && value > 0){

		push(stack, &free, value);	
	}

	printf("Conteudo em ordem reversa:");
	
	while(!empty(stack, &free)) {

		value = pop(stack, &free);
		printf(" %d", value);
	}
	
	printf("\n");
	return 0;
}

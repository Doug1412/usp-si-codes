#include <stdio.h>

int main(){
	
	int stack[100];
	int free = 0;
	int value;

	while (scanf("%d", &value) == 1 && value > 0){

		stack[free] = value;
		free++;	
	}

	printf("Conteudo em ordem reversa:");
	
	while (free > 0) {

		free--;
		printf(" %d", stack[free]);
	}
	
	printf("\n");
	return 0;
}

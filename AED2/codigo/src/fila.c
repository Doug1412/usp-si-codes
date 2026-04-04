#include <stdio.h>
#include <stdlib.h>

#include "../include/fila.h"

void inicializarFila(Fila *fila) {
    
	fila->inicio = NULL;
	fila->fim = NULL;
}

bool filaVazia(Fila *fila) {
	return fila->inicio == NULL;
}

void entrarFila(Fila *fila, int valor) {
	NoFila *novo = (NoFila *) malloc(sizeof(NoFila));
	if (!novo) {
		return;
	}

	novo->valor = valor;
	novo->prox = NULL;

	if (fila->fim == NULL) {
		fila->inicio = novo;
		fila->fim = novo;
		return;
	}

	fila->fim->prox = novo;
	fila->fim = novo;
}

int sairFila(Fila *fila) {
    if (filaVazia(fila)) {
        return -1;
    }

    NoFila *primeiro = fila->inicio;
    int valorSalvo = primeiro->valor; 

    fila->inicio = primeiro->prox;
    fila->fim = fila->inicio ? fila->fim : NULL;
    
    free(primeiro);
    
    return valorSalvo;
}

void limparFila(Fila *fila) {
	while (!filaVazia(fila)) {
		sairFila(fila);
	}
}

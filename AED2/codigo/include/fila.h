#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef struct s {
	int valor;
	struct s *prox;
} NoFila;

typedef struct {
	NoFila *inicio;
	NoFila *fim;
} Fila;

void inicializarFila(Fila *fila);
void entrarFila(Fila *fila, int valor);
int sairFila(Fila *fila);
bool filaVazia(Fila *fila);
void limparFila(Fila *fila);

#endif // FILA_H

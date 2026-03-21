#ifndef LISTAADJACENCIA_H
#define LISTAADJACENCIA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s{
    int adj;
    struct s* prox;
} No;

typedef struct {
    No *inicio;
} Vertices;

typedef struct {
    int tamanho;
    Vertices * lista;
} Grafo;

Grafo * inicializarLista(quantVertices);




#endif // LISTAADJACENCIA_H
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

Grafo * inicializarLista(int quantVertices);
void imprimirLista(Grafo *g);
void liberarLista(Grafo *g);
bool arestaExisteLista(Grafo *g, int v1, int v2);
bool inserirArestaLista(Grafo *g, int v1, int v2);
bool excluirArestaLista(Grafo *g, int v1, int v2);

#endif // LISTAADJACENCIA_H
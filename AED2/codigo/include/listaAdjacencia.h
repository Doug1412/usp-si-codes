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
    int flag; // 0 = Não visitado, 1 = visitando, 2 = finalizado
} Vertice;

typedef struct {
    int quantVertices;
    Vertice * vertices;
} GrafoL;

// Funções bases
GrafoL * inicializarLista(int quantVertices);
void imprimirLista(GrafoL *g);
void liberarLista(GrafoL *g);
bool arestaExisteLista(GrafoL *g, int v1, int v2);
bool inserirArestaLista(GrafoL *g, int v1, int v2);
bool excluirArestaLista(GrafoL *g, int v1, int v2);

void zerarFlagsLista(GrafoL *g);

// Funções extras
bool subgrafoLista(GrafoL *g1, GrafoL *g2);
GrafoL * transpostoLista(GrafoL *g);

//Buscas
void buscaProfLista(GrafoL *g, int i); 

#endif // LISTAADJACENCIA_H
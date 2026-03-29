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
} Vertices;

typedef struct {
    int tamanho;
    Vertices * lista;
} Grafo;

// Funções bases
Grafo * inicializarLista(int quantVertices);
void imprimirLista(Grafo *g);
void liberarLista(Grafo *g);
bool arestaExisteLista(Grafo *g, int v1, int v2);
bool inserirArestaLista(Grafo *g, int v1, int v2);
bool excluirArestaLista(Grafo *g, int v1, int v2);

void zerarFlagsLista(Grafo *g);

// Funções extras
bool subgrafoLista(Grafo *g1, Grafo *g2);
Grafo * transpostoLista(Grafo *g);

//Buscas
void buscaProfLista(Grafo *g, int i); 

#endif // LISTAADJACENCIA_H
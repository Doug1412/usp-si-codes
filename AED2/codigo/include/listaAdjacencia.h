#ifndef LISTAADJACENCIA_H
#define LISTAADJACENCIA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrizAdjacencia.h"

typedef struct s{
    int adj;
    int tipo; // aula do dia 11-03-2026
    struct s* prox;
} No;

typedef struct {
    No *inicio;
    int flag; // 0 = Não visitado, 1 = visitando, 2 = finalizado
    int tipo; // aula do dia 06-03-2026
    int dist; // distancia: aula do dia 13-03-2026
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

// Função que converte Matriz em Lista de Adjacência, aula do dia 06-03-2026
GrafoL * matrizParaLista(GrafoM *gM);

#endif // LISTAADJACENCIA_H
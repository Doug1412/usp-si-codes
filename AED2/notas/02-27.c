#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1;
#define false 0;
#define V = 5;

// AULA 27-02-2026

void inicializar(int m[V][V]) {
    int i,j;
    for (i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            m[i][j] = 0;
}

bool arestaExiste(int m[V][V], int v1, int v2) {
    if (m[v1][v2] == 1) {
        return true;
    } else
        return false;
}

void inserirAresta(int m[V][V], int v1, int v2) {
    // Grafo dirigido
    m[v1][v2] = 1;

    // Grafo não dirigido
    /*
    m[v1][v2] = 1;
    m[v2][v1] = 1;
    */
}

bool excluirAresta(int m[V][V], int v1, int v2) {
    // Grafo dirigido
    if(m[v1][v2] == 0){
        return false;
    }
    m[v1][v2] = 0;

    // Grafo dirigido
    /*
    if(m[v1][v2] == 0){
        return false;
    }
    m[v1][v2] = 0;
    m[v2][v1] = 0;
    */

    return true;
} 

int grauSaida(int m[V][V], int v1) {
    int j, g1;
    
    for (j = 0; j < V; j++) {
        g1 = g1 + m[v1][j];
    }

    return g1;
}

int grauEntrada(int m[V][V], int v2) {
    int i, g1;
    
    for (i = 0; i < V; i++) {
        g1 = g1 + m[i][v2];
    }

    return g1;
}

// LISTAS DE ADJCENCIA

typedef struct s{
    int adj;
    struct s* prox;
} No;

typedef struct {
    No *inicio;
} Vertice;

Vertice *g = (Vertice *) malloc(sizeof(Vertice));

void inicializar(Vertice *g) {
    int i;
    for (i = 0; i < V; i++) {
        g[i].inicio = NULL;
    }
}

bool arestaExiste(Vertice *g, int v1, int v2) {
    No * p = g[v1].inicio;
    while(p) {
        if(p->adj == v2) {
            return true;
        }
        p = p->prox;
    }
    return false;
}

bool insereAresta(Vertice *g, int v1, int v2) {
    if(arestaExiste(g, v1, v2)) {
        return false;
    }
    No *novo = (No*) malloc(sizeof(No));
    novo->adj = v2;
    novo->prox = g[v1].inicio;
    g[v1].inicio = novo;

    return true;
}

bool excluirAresta(Vertice *g, int v1, int v2) {
    No *ant = NULL;
    No *p = g[v1].inicio;

    while (p) {
        if (p->adj == v2)
            break;
        *ant = p;
        p = p->prox;
    }

    if (!p)
        return false;
    
    if (ant) {
        ant->prox = p->prox;
    } else {
        g[v1].inicio = p->prox;
    }

    free(p);
    return true;
}
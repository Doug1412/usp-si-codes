#include <stdio.h>
#include <stdlib.h>
#include "../include/listaAdjacencia.h"

Grafo * inicializarLista(int quantVertices) {
    Grafo *grafo;
    grafo = (Grafo *) malloc(sizeof(Grafo));

    grafo->tamanho = quantVertices;

    grafo->lista = (Vertices *) malloc(quantVertices * sizeof(Vertices));

    for(int i = 0; i < quantVertices; i++) {
        grafo->lista[i].inicio = NULL; // inicia cada lista de adjacencia como vazia
    }

    return grafo;
} 

void imprimirLista(Grafo *g) {
    for(int i = 0; i <= g->tamanho; i++) {
        printf("%d", i);
        No *p = g->lista[i].inicio;
        while(p) {
            printf("  %d", p->adj);
            p = p->prox;
        }
        printf("\n");
    }
}

void liberarLista(Grafo *g) {
    if (g) {
        // Liberando as arestas dos vertices
        for(int i = 0; i < g->tamanho; i++){
            No * atual = g->lista[i].inicio;
            No * prox;
            while(atual) {
                prox = atual->prox;
                free(atual);
                atual = prox;
            }
        }
    }
    // Libera o vetor de Vertices
    free(g->lista);
    // Libera a estrutura do Grafo
    free(g);
}

bool arestaExisteLista(Grafo *g, int v1, int v2) {
    No *p = g->lista[v1].inicio;
    while(p) {
        if (p->adj == v2) {
            return true;
        }
        p = p->prox;
    }
    return false;
}

bool inserirArestaLista(Grafo *g, int v1, int v2) {
    if (v1 < 0 || v1 > g->tamanho || v2 < 0 || v2 > g->tamanho) {
        return false; // Vértices inválidos
    }
    
    if (arestaExisteLista(g, v1, v2)) {
        return false;
    }

    No *novo = (No*) malloc(sizeof(No));
    novo->adj = v2;
    novo->prox = g->lista[v1].inicio;
    g->lista[v1].inicio = novo;

    return true;
}

bool excluirArestaLista(Grafo *g, int v1, int v2) {
    No *ant = NULL;
    No *p = g->lista[v1].inicio;

    while(p) {
        if (p->adj == v2) {
            break;
        }
        ant = p;
        p = p->prox;
    }

    if (!p) {
        return false;
    }

    if(ant) {
        ant->prox = p->prox;
    } else {
        g->lista[v1].inicio = p->prox;
    }

    free(p);
    return true;
}
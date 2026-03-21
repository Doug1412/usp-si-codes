#include <stdio.h>
#include <stdlib.h>
#include "../include/listaAdjacencia.h"

Grafo * inicializarLista(int quantVertices) {
    Grafo *grafo;
    grafo = (Grafo *) malloc(sizeof(Grafo));

    grafo->tamanho = quantVertices;

    grafo->lista = (Vertices *) malloc(quantVertices * sizeof(Vertices));

    for(int i = 0; i < quantVertices;) {
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
    No * g->lista->inicio;
}

bool arestaExisteLista(Grafo *g, int v1, int v2) {
    No *p = g->lista[v1].inicio;
    while(p) {
        if (p->adj == v2) {
            return true;
        }
        p = p->adj;
    }
    return false;
}

bool inserirArestaLista(Grafo *g, int v1, int v2) {
    if (arestaExisteLista) {
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
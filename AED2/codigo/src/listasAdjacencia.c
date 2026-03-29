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
    for(int i = 0; i < g->tamanho; i++) {
        printf("%d:", i);
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

void zerarFlagsLista(Grafo *g) {
    for(int i = 0; i < g->tamanho; i++) {
        g->lista[i].flag = 0;
    }
}

// Verificar se g1 é subgrafo de g2
bool subgrafoLista(Grafo *g1, Grafo *g2) {
    // Um subgrafo não pode ter mais vértices que o grafo original
    if (g1->tamanho > g2->tamanho) {
        printf("O grafo g1 é maior que o g2");
        return false;
    }

    // Verifica se todas as arestas de g1 estão presentes em g2
    for(int i = 0; i < g1->tamanho; i++) {
        No *p = g1->lista[i].inicio;
        while(p) {
            // Se achar uma aresta de g1 que não está em g2 não é subgrafo
            if(!arestaExisteLista(g2, i, p->adj)) {
                printf("O grafo g2 não apresenta a aresta %d -> %d", i, p->adj);
                return false;
            }
            p = p->prox;
        }
    }
    return true;
}

// Criar grafo transposto
Grafo * transpostoLista(Grafo *g){
    Grafo *gT = inicializarLista(g->tamanho);

    for(int i = 0; i < g->tamanho; i++) {
        No *p = g->lista[i].inicio;
        while(p) {
            No *novo = (No *) malloc(sizeof(No));
            novo->adj = i;
            novo->prox = gT->lista[p->adj].inicio;
            gT->lista[p->adj].inicio = novo;

            p = p->prox;
        }
    }
    return gT;
}


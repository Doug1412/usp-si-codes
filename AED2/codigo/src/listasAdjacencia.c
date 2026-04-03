#include <stdio.h>
#include <stdlib.h>
#include "../include/listaAdjacencia.h"

GrafoL * inicializarLista(int quantVertices) {
    GrafoL *g;
    g = (GrafoL *) malloc(sizeof(GrafoL));

    g->quantVertices = quantVertices;

    g->vertices = (Vertice *) malloc(quantVertices * sizeof(Vertice));

    for(int i = 0; i < quantVertices; i++) {
        g->vertices[i].inicio = NULL; // inicia cada lista de adjacencia como vazia
    }

    return g;
} 

void imprimirLista(GrafoL *g) {
    for(int i = 0; i < g->quantVertices; i++) {
        printf("%d:", i);
        No *p = g->vertices[i].inicio;
        while(p) {
            printf("  %d", p->adj);
            p = p->prox;
        }
        printf("\n");
    }
}

void liberarLista(GrafoL *g) {
    if (!g) {
        return;
    }

    // Liberando as arestas dos vertices
    for(int i = 0; i < g->quantVertices; i++){
        No *atual = g->vertices[i].inicio;
        No *prox;
        while(atual) {
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }
    // Libera o vetor de Vertices
    free(g->vertices);
    // Libera a estrutura do Grafo
    free(g);
}

bool arestaExisteLista(GrafoL *g, int v1, int v2) {
    No *p = g->vertices[v1].inicio;
    while(p) {
        if (p->adj == v2) {
            return true;
        }
        p = p->prox;
    }
    return false;
}

bool inserirArestaLista(GrafoL *g, int v1, int v2) {
    if (v1 < 0 || v1 >= g->quantVertices || v2 < 0 || v2 >= g->quantVertices) {
        return false; // Vértices inválidos
    }
    
    if (arestaExisteLista(g, v1, v2)) {
        return false;
    }

    No *novo = (No*) malloc(sizeof(No));
    novo->adj = v2;
    novo->prox = g->vertices[v1].inicio;
    g->vertices[v1].inicio = novo;

    return true;
}

bool excluirArestaLista(GrafoL *g, int v1, int v2) {
    No *ant = NULL;
    No *p = g->vertices[v1].inicio;

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
        g->vertices[v1].inicio = p->prox;
    }

    free(p);
    return true;
}

void zerarFlagsLista(GrafoL *g) {
    for(int i = 0; i < g->quantVertices; i++) {
        g->vertices[i].flag = 0;
    }
}

// Verificar se g1 é subgrafo de g2
bool subgrafoLista(GrafoL *g1, GrafoL *g2) {
    // Um subgrafo não pode ter mais vértices que o grafo original
    if (g1->quantVertices > g2->quantVertices) {
        printf("O grafo g1 é maior que o g2");
        return false;
    }

    // Verifica se todas as arestas de g1 estão presentes em g2
    for(int i = 0; i < g1->quantVertices; i++) {
        No *p = g1->vertices[i].inicio;
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
GrafoL * transpostoLista(GrafoL *g){
    GrafoL *gT = inicializarLista(g->quantVertices);

    for(int i = 0; i < g->quantVertices; i++) {
        No *p = g->vertices[i].inicio;
        while(p) {
            No *novo = (No *) malloc(sizeof(No));
            novo->adj = i;
            novo->prox = gT->vertices[p->adj].inicio;
            gT->vertices[p->adj].inicio = novo;

            p = p->prox;
        }
    }
    return gT;
}

// Função que converte Matriz em Lista de Adjacência
GrafoL * matrizParaLista(GrafoM *gM) {
    GrafoL * gL = inicializarLista(gM->totalVertices);
    
    for(int i = 0; i < gM->totalVertices;  i++) {
        for(int j = 0; j < gM->totalVertices;  j++){
            if (gM->matriz[i][j] == 1) {
                No *novo = (No *) malloc(sizeof(No));
                novo->adj = j;
                novo->prox = gL->vertices[i].inicio;
                gL->vertices[i].inicio = novo;
            }
        }
    }
    return gL;
}
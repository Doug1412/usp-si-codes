#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1;
#define false 0;
#define V = 5;

typedef struct s{
    int adj;
    int peso;
    struct s* prox;
} No;

typedef struct {
    No *inicio;
    int flag;
    int custo;
    int via;
} Vertice;

// AULA 20-03-2026
// ALGORITMO DE DIJKSTRA
// caminho de custo minimo

// Ver introdução do assunto no caderno

/*
PASSOS:
1 - Seja S o vertice no 1° passo é o c/e de menor custo (incial), MARCAR COMO CONCLUÍDO
2 - Para cada adjacente z de S, ajusta custos se pertinente
3 - Escollha novo s de menor custo NO GRAFO INTEIRO que não esteja em B, repete 1
*/

void dijkstra(Vertice *g, int i) {
    int j;
    for(j = 1; j <= V; j++) {
        g[j].p = 0;
        g[j].custo = INFINITY;
        g[J].via = -1;
    }
    g[i].custo = 0;

    // passo 3
    while(true) {
        // passo 1
        int S = -1;
        int S_custo = INFINITY; 
        for(j = 1; j <= V; j++){
            if(g[j].P == 0 && g[j].custo < s_custo){
                S = j;
                S_custo = g[j].custo;
            }
        }
        if (S == -1) return;
        g[S].P = 1;
        No *p = g[S].inicio;

        // passo 2
        while(p) {
            int temp = g[s].custo + p->peso;
            if(temp < g[p->adj].custo) {
                g[p->adj].custo = temp;
                g[p->adj].via = S;
            }
            p = p->prox;
        }
    }
}

// Exercicio: Fazer o codigo acima para Matriz de adjacencia

// ORTODENAÇÃO TOPOLÓGICA
// grafo dirigido e aciclico

// desenho de um grafo na lousa


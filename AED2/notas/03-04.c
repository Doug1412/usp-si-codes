#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1;
#define false 0;
#define V = 5;

typedef struct s{
    int adj;
    struct s* prox;
} No;

typedef struct {
    No *inicio;
} Vertice;

// AULA 04-03-2026
// Problema 1: exibir a estrutura de dados

void exibir(Vertice *g) {
    for (int i = 0; i < V; i++) {
        printf("%d", i);
        No *p = g[i].inicio;
        while (p) {
            printf("  %d", p->adj);
            p = p->prox;
        }
        printf("\n");
    }
}

// Problema 2: verificar se g1 é subgrafo de g2, considerando apenas as arestas

bool subgrafo(Vertice *g1, Vertice *g2) {
    int i;
    for (i = 0; i < V; i++) {
        while (p) {
            if (arestaExiste(g2, i, p->adj)) {
                return false;
            }
            p = p->prox;
        }
    }
    return true;
}

// Exercicio: Usar matriz para g1 em g2

// Probelma 3: Copiar grafo transposto

Vertice * transposto(Vertice *g) {
    Vertice * gt = (Vertice *) malloc(sizeof(Vertice));
    inicialiar(gt);

    int i;
    for (i = 0; i < V; i++) {
        No *p = g[i].inicio;
        while (p) {
            No *novo = (No *) malloc(sizeof(No));
            novo->adj = i;
            novo->prox = gt[p->adj].inicio;
            gt[p->adj].inicio = novo;
            p = p->prox;
        }
    }
    return gt;
}

// Exercicio: Fazer uma copia simples

/* BUSCA EM PROFUNDIDADE 
Criar um vetor de flags para saber quais já foram enconradas e visitadas

0 = branco (não conhecido)
1 = cinza conhecido
2 = preto

No struct da lista de adjcencia adicionar um campo extra para salvar a flag
*/

// zerar flags antes de rodar
void prof(Vertice *g, int i) {
    g[i].flag = 1; // descoberto
    No *p = g[i].inicio;
    while(p) {
        if(g[p->adj].flag == 0) {
            prof(g, p->adj);
        }
        p = p->prox;
    }
    g[i].flag = 2; //
}
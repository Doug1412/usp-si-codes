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
    int flag;
} Vertice;

// AULA 06-03-2026
// BUSCA EM PROFUNDIDADE


// Em matriz
void prof(int m[V][V], int flag[V], int i) {
    // zerar flags
    flag[i] = 1;
    int j;
    for (j = 0; j < V; j++) {
        if(m[i][j] == 1 && flag[j] == 0) {
            prof(m, flag, j);   
        }
    }
    flag[i] = 2;
}

// Verificar se existe um caminho de i até j
void prof(Vertice *g, int i, int j, bool *achou) { // achou inicializa como falso
    //zerar flags
    if (i == j) {
        *achou = true;
        return;
    }

    g[i].flag = 1;
    No *p = g[i].inicio;
    while(p) {
        if (g[p->adj].flag == 0) {
            prof(g, p->adj, j, achou);
        }
        if (*achou) {
            return;
        }
    }
    g[i].flag = 2;
} 

// Verificar se existe ciclo
void prof(Vertice *g, int i) {
    g[i].flag = 1;
    No *p = g[i].inicio
    while(p) {
        if(g[p->adj].flag == 1) {
            printf("Ciclo %d %d", i, p->adj);
        }

        if(g[p->adj].flag == 0){
            prof(g, p->adj):
        }

        p = p->prox
    }
    g[i].flag = 2;
}

// Problema:
// 1. Contar salas do tipo N (ITA)*
// 2. Contar salas do tipo N alcançaveis a partir de i
// * Instituição TRIVIAL de algoritmos

typedef struct {
    No *primeiro;
    int flag;
    int tipo;
} Vertice;

void prof(Vertice *g, int i, int n, int *cont){
    g[i].flag = 1;
    if(g[i].tipo == n) {
        *cont = *cont +1;
    }

    No *p = g[i].inicio;
    while(p) {
        if(g[p->adj].flag == 0){
            prof(g, p->adj, n, cont)
        }
        p = p->prox;
    }
    g[i].flag == 2;
}

// converter matriz em lista de adjacência
Vertice * matrizParaLista(int m[V][V]){
    Vertice* resp = (Vertice *) malloc((V+1) sizeof(Vertice));
    inicializar(resp);
    int i, j;
    for(i = 1; i < V; i++){
        for(j = 1; j < V; j++){
            if(m[i][i] == 1) {
                No * novo = (No *) malloc(sizeof(No));
                novo->adj = j;
                novo->prox = g[i].inicio;
                g[i].inicio = novo;
            }
        }
    }
    return resp;
}

// Variação copiar somente arestas alcançaveis a partir de um incio i
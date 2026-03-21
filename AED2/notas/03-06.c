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
    No *p = g[i].inicio;
    while(p) {
        if(g[p->adj].flag == 1) {
            printf("Ciclo %d %d", i, p->adj);
            if(g[p->adj].flag == 0){
                prof(g, p->adj):
            }
        }
    }
}
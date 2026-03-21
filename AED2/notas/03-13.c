#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// AULA 13-03-2026
// BUSCA EM LARGURA

/* (caminho mais curto)
1. criar fila vazia F
2. entrar i na fila e fazer flag[i] = 1
Enquanto F
    sair i fa fila
    para cada adjacente j
        flag[j] = 1
        entrar j na fila
    flag[i] = 2
*/

// LISTA
void largura(Vertice *g, int i) {
    zerarFlags(g);
    
    FILA F;
    inicializar(&F);

    enviarFila(&F, i);
    g[i].flag = 1;

    while (F->inicio) {
        i = sairFila(&F);
        No *p = g[i].inicio;
        while(p) {
            if(g[p->adj].flag == 0) {
                g[p->adj].flag =1;
                entrarFila(&F, p->adj);
            }
            p = p->prox;
        }
        g[i].flag = 2;
    }
}

// MATRIZ
void largura(int m[V][V], int i) {
    int flags[V];
    zerarFlags(flags);
    
    FILA F;
    inicializar(&F);

    entrarFila(&F, i);
    flags[i] = 1;

    while (F->incio) {
        i = sairFila(&F);
        int j;
        for (j = 1; j <= V; j++) {
            if (m[i][j] == 1 && flags[j] == 0) { // é facil esquecer de verificar o m[i][j] = 1
                flags[j] = 1;
                entrarFila(&F, j);
            }
        }
        flags[i] = 2;
    }
}

// EX1: Encontraro posto de gasolina mais próximo

int tipoXMaisProximo(matriz m[V][V], int i, int tipoX, int tipos[V]) { // tipo = 1
    int flags[V];
    zerarFlags(flags);
    
    FILA F;
    inicializar(&F);

    entrarFila(&F, i);
    flags[i] = 1;

    while (F->inicio) {
        int i = sairFila(&F);

        if (tipos[i] == tipoX) {
            while(F->fim) {
                sairFila(&F);
            }
            return i;
        }

        int j;
        for (j = 1; j <= V; j++) {
            if (m[i][j] == 1 && flags[j] == 0) {
                flags[j] = 1;
                entrarFila(&F, j);
            }
        }
        flags[i] = 2;
    }
    return -1;
}

// EX2: Qual o comprimento do caminho mais curto de v1 a v2?

typedef struct {
    No *inicio;
    int flag; // Depende de i
    int dist; // Depende de i
} Vertice;

int comprimento(Vertice *g, int v1, int v2) {
    zerarFlags(g);
    int j;
    for (j = 1; j <= V; j++) {
        if(j == v1) {
            g[j].dist = 0;
        } else {
            g[j].dist = INFINITY
        }
    }

    FILA F;
    entrarFILA(&F, v1);

    g[v1].flag = 1;

    while(F->inicio) {
        int i = sairFila(&F);
        if (i == v2) {
            while(F->inicio) {
                sairFila(&F);
            }
            return g[i].dist; // saida normal
        }
        No *p = g[i].inicio;
        while(p) {
            if(g[p->adj].flag == 0) {
                g[p->adj].flag = 1;
                g[p->adj].dist = g[i].dist + 1;
                entrarFila(&F, p->adj);
            }
            p = p->prox;
        }
        g[i].flag = 2;
    }
    return INFINITY; // não achou o v2
}
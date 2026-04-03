#include <stdio.h>
#include <stdlib.h>
#include "../include/buscasLista.h"

// Busca em profundidade começando em i
void dfsLista(GrafoL *g, int i) {
    // rodar zerarFlagsLista(g) antes
    g->vertices[i].flag = 1; // Marca como "descobrindo" (1)
    
    No *p = g->vertices[i].inicio;
    while(p) {
        // Se o vizinho ainda não foi visitado (0)
        if (g->vertices[p->adj].flag == 0) {
            dfsLista(g, p->adj); // Visita recursivamente
        }
        p = p->prox;
    }
    
    g->vertices[i].flag = 2; // Marca como "finalizado" (2)
}

// Verificar se existe um caminho de i até j
/* ---------------------------- VERSÃO DO PROFESSOR ----------------------------
void dfsCaminhoLista(GrafoL *g, int i, int j, bool *achou) {
    // rodar zerarFlagsLista(g) antes
    if(i == j) {
        *achou = true;
        return;
    }

    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            dfsCaminhoLista(g, p->adj, j, achou);
        }
        if(*achou) {
            return;
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
}
------------------------------------------------------------------------------- */
bool dfsCaminhoLista(GrafoL *g, int i, int j) {
    // rodar zerarFlagsLista(g) antes
    if (i == j) return true;

    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            if (dfsCaminhoLista(g, p->adj, j)) {
                return true;
            }
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
    return false;
}

// Verificar se existe ciclo
void dfsCicloLista(GrafoL *g, int i) {
    // rodar zerarFlagsLista(g) antes
    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 1) {
            printf("Ciclo detectado de %d para %d\n", i, p->adj);
        }

        if (g->vertices[p->adj].flag == 0) {
            dfsCicloLista(g, p->adj);
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
}

// Contar quantas salas do tipo N alcançaveis a partir de i
void contarSalasTipoLista(GrafoL *g, int i, int N, int *cont) {
    // rodar zerarFlagsLista(g) antes
    if (g->vertices[i].tipo == N) {
        *cont = *cont + 1;
    }

    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            contarSalarTipoLista(g, p->adj, N, cont);
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
}
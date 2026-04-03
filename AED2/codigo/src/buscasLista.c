#include <stdio.h>
#include <stdlib.h>
#include "../include/buscasLista.h"

// Busca em profundidade começando em i
void buscaProfLista(GrafoL *g, int i) {
    g->vertices[i].flag = 1; // Marca como "descobrindo" (1)
    
    No *p = g->vertices[i].inicio;
    while(p) {
        // Se o vizinho ainda não foi visitado (0)
        if (g->vertices[p->adj].flag == 0) {
            buscaProfLista(g, p->adj); // Visita recursivamente
        }
        p = p->prox;
    }
    
    g->vertices[i].flag = 2; // Marca como "finalizado" (2)
}
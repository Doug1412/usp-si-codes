#include <stdio.h>
#include <stdlib.h>
#include "../include/buscasLista.h"

// Busca em profundidade começando em i
void buscaProfLista(Grafo *g, int i) {
    g->lista[i].flag = 1; // Marca como "descobrindo" (1)
    
    No *p = g->lista[i].inicio;
    while(p) {
        // Se o vizinho ainda não foi visitado (0)
        if (g->lista[p->adj].flag == 0) {
            buscaProfLista(g, p->adj); // Visita recursivamente
        }
        p = p->prox;
    }
    
    g->lista[i].flag = 2; // Marca como "finalizado" (2)
}
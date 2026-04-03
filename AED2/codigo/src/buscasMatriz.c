#include <stdio.h>
#include <stdlib.h>
#include "../include/buscasMatriz.h"

// Busca em profundidade começando em i
void buscaProfMatriz(GrafoM *m, int i) {
    m->flags[i] = 1;
    
    for(int j = 0; j < m->totalVertices; j++) {
        if(m->matriz[i][j] == 1 && m->flags[j] == 0) {
            buscaProfMatriz(m, j);
        }
    }
    
    m->flags[i] = 2;
}
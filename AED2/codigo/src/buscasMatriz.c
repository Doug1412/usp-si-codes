#include <stdio.h>
#include <stdlib.h>
#include "../include/buscaMatriz.h"

// Busca em profundidade começando em i
void buscaProfMatriz(Matriz *m, int i) {
    m->flags[i] = 1;
    
    for(int j = 0; j < m->tamanho; j++) {
        if(m->valores[i][j] == 1 && m->flags[j] == 0) {
            buscaProfMatriz(m, j);
        }
    }
    
    m->flags[i] = 2;
}
#include <stdio.h>
#include <stdlib.h>
#include "../include/matrizAdjacencia.h"

Matriz * inicializarMatriz(int quantidadeVertices) {
    Matriz *m;
    m = (Matriz *) malloc(sizeof(Matriz));

    m->tamanho = quantidadeVertices;
    
    m->flags = (int *) malloc(m->tamanho * sizeof(int));
    for (int i = 0; i < m->tamanho; i++) {
        m->flags[i] = 0;
    }

    m->valores = (int **) malloc(m->tamanho * sizeof(int *));
    for (int i = 0; i < m->tamanho; i++) {
        m->valores[i] = (int *) malloc(m->tamanho * sizeof(int));

        for (int j = 0; j < m->tamanho; j++) {
            m->valores[i][j] = 0;
        }
    }
    return m;
}  

void imprimirMatriz(Matriz *m) {
    for (int i = 0; i < m->tamanho; i++) { 
        for(int j = 0; j < m->tamanho; j++) {
            printf("%d ", m->valores[i][j]);
        }
        printf("\n");
    }
}

void liberarMatriz(Matriz *m) {
    // 1. Libera as linhas da matriz
    for (int i = 0; i < m->tamanho; i++) {
        free(m->valores[i]); 
    }
    // 2. Libera o array de ponteiros das linhas
    free(m->valores);
    
    // 3. Libera o array de flags
    free(m->flags);
    
    // 4. Libera a struct principal
    free(m);
}

bool arestaExisteMatriz(Matriz *m, int v1, int v2) {
    if (m->valores[v1][v2] == 1) {
        return true;
    } else {
        return false;
    }
}

void inserirArestaMatriz(Matriz *m, int v1, int v2) {
    m->valores[v1][v2] = 1;
    //m->valores[v2][v1] = 1; // GRAFO DIRIGIDO
}

bool excluirArestaMatriz(Matriz *m, int v1, int v2) {
    if (m->valores[v1][v2] == 0) {
        return false;
    } else {
        m->valores[v1][v2] = 0;
        //m->valores[v2][v1] = 0; // GRAFO DIRIGIDO
        return true;
    }
}

int grauEntradaMatriz(Matriz *m, int v2) {
    int grau = 0;
    for (int i = 0; i < m->tamanho; i++) {
        grau += m->valores[i][v2];
    }
    return grau;
}

int grauSaidaMatriz(Matriz *m, int v1) {
    int grau = 0;
    for (int j = 0; j < m->tamanho; j++) {
        grau += m->valores[v1][j];
    }
    return grau;
}

void zerarFlagsMatriz(Matriz *m) {
    for (int i = 0; i < m->tamanho; i++) {
        m->flags[i] = 0;
    }
}


// Verificar se m1 é subgrafo de m2
// Se achar uma aresta de m1 que não está em m2 não é subgrafo
bool subgrafoMatriz(Matriz *m1, Matriz *m2) {
    // Um subgrafo não pode ter mais vértices que o grafo original
    if(m1->tamanho > m2->tamanho){
        return false;
    }

    // Verifica se todas as arestas de m1 estão presentes em m2
    for(int i = 0; i < m1->tamanho; i++) {
        for(int j = 0; j < m1->tamanho; j++) {
            if(arestaExisteMatriz(m1, i, j)) {
                // Se achar uma aresta de m1 que não está em m2 não é subgrafo
                if(!arestaExisteMatriz(m2, i, j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

// Criar grafo transposto
Matriz *transpostoMatriz(Matriz *m) {
    Matriz *mT = inicializarMatriz(m->tamanho);

    for(int i = 0; i < m->tamanho; i++){
        for(int j = 0; j < m->tamanho; j++){
            /*
            if(m->valores[i][j] == 1) {
                mT->valores[j][i] = m->valores[i][j];
            }
            */ 
            mT->valores[j][i] = m->valores[i][j]; // mais eficiente que o codigo acima
        }
    }

    return mT;
}
#include <stdio.h>
#include <stdlib.h>
#include "../include/matrizAdjacencia.h"

GrafoM * inicializarMatriz(int quantidadeVertices) {
    GrafoM *m;
    m = (GrafoM *) malloc(sizeof(GrafoM));

    m->totalVertices = quantidadeVertices;
    
    m->flags = (int *) malloc(m->totalVertices * sizeof(int));
    for (int i = 0; i < m->totalVertices; i++) {
        m->flags[i] = 0;
    }

    m->matriz = (int **) malloc(m->totalVertices * sizeof(int *));
    for (int i = 0; i < m->totalVertices; i++) {
        m->matriz[i] = (int *) malloc(m->totalVertices * sizeof(int));

        for (int j = 0; j < m->totalVertices; j++) {
            m->matriz[i][j] = 0;
        }
    }
    return m;
}  

void imprimirMatriz(GrafoM *m) {
    for (int i = 0; i < m->totalVertices; i++) { 
        for(int j = 0; j < m->totalVertices; j++) {
            printf("%d ", m->matriz[i][j]);
        }
        printf("\n");
    }
}

void liberarMatriz(GrafoM *m) {
    // 1. Libera as linhas da matriz
    for (int i = 0; i < m->totalVertices; i++) {
        free(m->matriz[i]); 
    }
    // 2. Libera o array de ponteiros das linhas
    free(m->matriz);
    
    // 3. Libera o array de flags
    free(m->flags);
    
    // 4. Libera a struct principal
    free(m);
}

bool arestaExisteMatriz(GrafoM *m, int v1, int v2) {
    if (m->matriz[v1][v2] == 1) {
        return true;
    } else {
        return false;
    }
}

void inserirArestaMatriz(GrafoM *m, int v1, int v2) {
    m->matriz[v1][v2] = 1;
    //m->matriz[v2][v1] = 1; // GRAFO DIRIGIDO
}

bool excluirArestaMatriz(GrafoM *m, int v1, int v2) {
    if (m->matriz[v1][v2] == 0) {
        return false;
    } else {
        m->matriz[v1][v2] = 0;
        //m->matriz[v2][v1] = 0; // GRAFO DIRIGIDO
        return true;
    }
}

int grauEntradaMatriz(GrafoM *m, int v2) {
    int grau = 0;
    for (int i = 0; i < m->totalVertices; i++) {
        grau += m->matriz[i][v2];
    }
    return grau;
}

int grauSaidaMatriz(GrafoM *m, int v1) {
    int grau = 0;
    for (int j = 0; j < m->totalVertices; j++) {
        grau += m->matriz[v1][j];
    }
    return grau;
}

void zerarFlagsMatriz(GrafoM *m) {
    for (int i = 0; i < m->totalVertices; i++) {
        m->flags[i] = 0;
    }
}


// Verificar se m1 é subgrafo de m2
// Se achar uma aresta de m1 que não está em m2 não é subgrafo
bool subgrafoMatriz(GrafoM *m1, GrafoM *m2) {
    // Um subgrafo não pode ter mais vértices que o grafo original
    if(m1->totalVertices > m2->totalVertices){
        return false;
    }

    // Verifica se todas as arestas de m1 estão presentes em m2
    for(int i = 0; i < m1->totalVertices; i++) {
        for(int j = 0; j < m1->totalVertices; j++) {
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
GrafoM *transpostoMatriz(GrafoM *m) {
    GrafoM *mT = inicializarMatriz(m->totalVertices);

    for(int i = 0; i < m->totalVertices; i++){
        for(int j = 0; j < m->totalVertices; j++){
            /*
            if(m->matriz[i][j] == 1) {
                mT->matriz[j][i] = m->matriz[i][j];
            }
            */ 
            mT->matriz[j][i] = m->matriz[i][j]; // mais eficiente que o codigo acima
        }
    }

    return mT;
}
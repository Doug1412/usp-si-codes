#include <stdio.h>
#include <stdlib.h>
#include "../include/matrizAdjacencia.h"

Matriz * inicializarMatriz(int quantidadeVertices) {
    Matriz *m;
    m = (Matriz *) malloc(sizeof(Matriz));

    m->tamanho = quantidadeVertices;
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
    for (int i = 0; i < m->tamanho; i++) {
        free(m->valores[i]); 
    }
    free(m->valores);
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

int grauEntradaMatriz(Matriz *m, int v1) {
    int grau = 0;
    for (int j = 0; j < m->tamanho; j++) {
        grau += m->valores[v1][j];
    }
    return grau;
}
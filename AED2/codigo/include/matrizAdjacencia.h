#ifndef MATRIZADJACENCIA_H
#define MATRIZADJACENCIA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int **matriz;
    int *flags;
    int totalVertices;
} GrafoM;

GrafoM * inicializarMatriz(int quantidadeVertices);

// Funções bases
void imprimirMatriz(GrafoM *m);
void liberarMatriz(GrafoM *m);
bool arestaExisteMatriz(GrafoM *m, int v1, int v2);
void inserirArestaMatriz(GrafoM *m, int v1, int v2);
bool excluirArestaMatriz(GrafoM *m, int v1, int v2);
int grauEntradaMatriz(GrafoM *m, int v2);
int grauSaidaMatriz(GrafoM *m, int v1);

void zerarFlagsMatriz(GrafoM *m);

// Funções Extras
bool subgrafoMatriz(GrafoM *m1, GrafoM *m2);
GrafoM *transpostoMatriz(GrafoM *m);

#endif // MATRIZADJACENCIA_H
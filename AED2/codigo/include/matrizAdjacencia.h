#ifndef MATRIZADJACENCIA_H
#define MATRIZADJACENCIA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listaAdjacencia.h"

typedef struct {
    int **matriz;
    int *flags;
    int *tipos; // Aula 13-03-2026
    int *dist; // Aula 13-03-2026
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

// Função que converte Matriz em Lista de Adjacência, aula do dia 06-03-2026
GrafoM * listaParaMatriz(GrafoL *gL);

#endif // MATRIZADJACENCIA_H
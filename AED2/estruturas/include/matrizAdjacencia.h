#ifndef MATRIZADJACENCIA_H
#define MATRIZADJACENCIA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int **valores;
    int tamanho;
} Matriz;

Matriz * inicializarMatriz(int quantidadeVertices);

void imprimirMatriz(Matriz *m);
void liberarMatriz(Matriz *m);
bool arestaExisteMatriz(Matriz *m, int v1, int v2);
void inserirArestaMatriz(Matriz *m, int v1, int v2);
bool excluirArestaMatriz(Matriz *m, int v1, int v2);
int grauEntradaMatriz(Matriz *m, int v2);
int grauSaidaMatriz(Matriz *m, int v1);

#endif // MATRIZADJACENCIA_H
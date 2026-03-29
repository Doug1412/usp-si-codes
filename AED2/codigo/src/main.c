#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrizAdjacencia.h"
#include "listaAdjacencia.h"

#include "buscaMatriz.h"
#include "buscaLista.h"

void testeMatriz();
void testeLista();

int main(){
    testeMatriz();

    //testeLista();

    return 0;
}

void testeMatriz() {
    int V = 5;

    Matriz *m;
    m = inicializarMatriz(V);

    inserirArestaMatriz(m, 0, 1);
    inserirArestaMatriz(m, 1, 4);
    inserirArestaMatriz(m, 1, 3);
    inserirArestaMatriz(m, 3, 2);
    inserirArestaMatriz(m, 2, 0);

    imprimirMatriz(m);

    int gE = grauEntradaMatriz(m, 1);
    int gS = grauSaidaMatriz(m, 1);
    printf("Vertice 1 \n -Grau de entrada: %d \n -Grau de Saida: %d \n", gE, gS);

    //excluirArestaMatriz(m, 1, 4);

    //imprimirMatriz(m);

    Matriz *mT = transpostoMatriz(m);
    imprimirMatriz(mT);
    liberarMatriz(mT);

    liberarMatriz(m);
}

void testeLista(){
    int V = 5;

    Grafo *g;
    g = inicializarLista(V);

    inserirArestaLista(g, 0, 1);
    inserirArestaLista(g, 1, 4);
    inserirArestaLista(g, 1, 3);
    inserirArestaLista(g, 3, 2);
    inserirArestaLista(g, 2, 0);

    imprimirLista(g);

    //excluirArestaLista(g, 1, 4);

    //imprimirLista(g);

    Grafo *gT = transpostoLista(g);

    imprimirLista(gT);
    liberarLista(gT);

    liberarLista(g);
}
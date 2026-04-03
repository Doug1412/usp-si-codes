#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrizAdjacencia.h"
#include "listaAdjacencia.h"

#include "buscaMatriz.h"
#include "buscaLista.h"

void testeMatriz();
void testeLista();
void testeBuscaMatriz();
void testeBuscaLista();
void testeOperacoesMatriz();
void testeOperacoesLista();

int main(){
    testeMatriz();
    testeLista();
    testeBuscaMatriz();
    testeBuscaLista();
    testeOperacoesMatriz();
    testeOperacoesLista();

    return 0;
}

void testeMatriz() {
    int V = 5;

    GrafoM *m;
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

    GrafoM *mT = transpostoMatriz(m);
    imprimirMatriz(mT);
    liberarMatriz(mT);

    liberarMatriz(m);
}

void testeLista(){
    int V = 5;

    GrafoL *g;
    g = inicializarLista(V);

    inserirArestaLista(g, 0, 1);
    inserirArestaLista(g, 1, 4);
    inserirArestaLista(g, 1, 3);
    inserirArestaLista(g, 3, 2);
    inserirArestaLista(g, 2, 0);

    imprimirLista(g);

    //excluirArestaLista(g, 1, 4);

    //imprimirLista(g);

    GrafoL *gT = transpostoLista(g);

    imprimirLista(gT);
    liberarLista(gT);

    liberarLista(g);
}

void testeBuscaMatriz() {
    int V = 5;
    GrafoM *m = inicializarMatriz(V);

    inserirArestaMatriz(m, 0, 1);
    inserirArestaMatriz(m, 1, 2);
    inserirArestaMatriz(m, 2, 3);
    inserirArestaMatriz(m, 3, 4);

    zerarFlagsMatriz(m);
    buscaProfMatriz(m, 0);

    printf("Busca em profundidade na matriz concluida\n");
    for (int i = 0; i < V; i++) {
        printf("flag[%d] = %d\n", i, m->flags[i]);
    }

    liberarMatriz(m);
}

void testeBuscaLista() {
    int V = 5;
    GrafoL *g = inicializarLista(V);

    inserirArestaLista(g, 0, 1);
    inserirArestaLista(g, 1, 2);
    inserirArestaLista(g, 2, 3);
    inserirArestaLista(g, 3, 4);

    zerarFlagsLista(g);
    buscaProfLista(g, 0);

    printf("Busca em profundidade na lista concluida\n");
    for (int i = 0; i < V; i++) {
        printf("flag[%d] = %d\n", i, g->vertices[i].flag);
    }

    liberarLista(g);
}

void testeOperacoesMatriz() {
    int V = 4;
    GrafoM *m1 = inicializarMatriz(V);
    GrafoM *m2 = inicializarMatriz(V);

    inserirArestaMatriz(m1, 0, 1);
    inserirArestaMatriz(m1, 1, 2);
    inserirArestaMatriz(m1, 2, 3);

    inserirArestaMatriz(m2, 0, 1);
    inserirArestaMatriz(m2, 1, 2);
    inserirArestaMatriz(m2, 2, 3);
    inserirArestaMatriz(m2, 3, 0);

    printf("Aresta 1 -> 2 existe em m1? %s\n", arestaExisteMatriz(m1, 1, 2) ? "sim" : "nao");
    printf("Aresta 3 -> 0 existe em m1? %s\n", arestaExisteMatriz(m1, 3, 0) ? "sim" : "nao");

    printf("Excluir aresta 1 -> 2 em m1: %s\n", excluirArestaMatriz(m1, 1, 2) ? "sucesso" : "falha");
    printf("Aresta 1 -> 2 existe em m1 apos exclusao? %s\n", arestaExisteMatriz(m1, 1, 2) ? "sim" : "nao");

    printf("Grau de entrada do vertice 2 em m2: %d\n", grauEntradaMatriz(m2, 2));
    printf("Grau de saida do vertice 1 em m2: %d\n", grauSaidaMatriz(m2, 1));

    printf("m1 eh subgrafo de m2? %s\n", subgrafoMatriz(m1, m2) ? "sim" : "nao");

    printf("Matriz m2 original:\n");
    imprimirMatriz(m2);

    GrafoM *mT = transpostoMatriz(m2);
    printf("Matriz m2 transposta:\n");
    imprimirMatriz(mT);

    liberarMatriz(mT);
    liberarMatriz(m1);
    liberarMatriz(m2);
}

void testeOperacoesLista() {
    int V = 4;
    GrafoL *g1 = inicializarLista(V);
    GrafoL *g2 = inicializarLista(V);

    inserirArestaLista(g1, 0, 1);
    inserirArestaLista(g1, 1, 2);
    inserirArestaLista(g1, 2, 3);

    inserirArestaLista(g2, 0, 1);
    inserirArestaLista(g2, 1, 2);
    inserirArestaLista(g2, 2, 3);
    inserirArestaLista(g2, 3, 0);

    printf("Aresta 1 -> 2 existe em g1? %s\n", arestaExisteLista(g1, 1, 2) ? "sim" : "nao");
    printf("Aresta 3 -> 0 existe em g1? %s\n", arestaExisteLista(g1, 3, 0) ? "sim" : "nao");

    printf("Excluir aresta 1 -> 2 em g1: %s\n", excluirArestaLista(g1, 1, 2) ? "sucesso" : "falha");
    printf("Aresta 1 -> 2 existe em g1 apos exclusao? %s\n", arestaExisteLista(g1, 1, 2) ? "sim" : "nao");

    printf("g1 eh subgrafo de g2? %s\n", subgrafoLista(g1, g2) ? "sim" : "nao");

    printf("Lista g2 original:\n");
    imprimirLista(g2);

    GrafoL *gT = transpostoLista(g2);
    printf("Lista g2 transposta:\n");
    imprimirLista(gT);

    liberarLista(gT);
    liberarLista(g1);
    liberarLista(g2);
}
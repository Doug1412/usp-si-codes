#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1;
#define false 0;
#define V = 5;

typedef struct s{
    int adj;
    struct s* prox;
} No;

typedef struct {
    No *inicio;
    int cor;
} Vertice;

// AULA 25-03-2026
// COLORAÇÃO DE GRAFOS

/* 
O objetivo da colocaração é associar um ercurso (1,2,3,4) a cada 
vertice sem conflito.

exemplo: coloração de mapas da forma mais ecõnomica possível

Considerando o seguinte grafo
A -> B - C
B -> A - C - D
C -> B - D - E
D -> B - C - E - F
E -> C - D - F 
F -> A - D - E

Método 1: profundidade no vertice de maior grau
    número cromático: k = 4

Método 2: largura começando no vertice de maior grau
    número cromático: k = 3
*/

// função do metodo 1:
void prof(Vertice *g, int i, int *k) { // i = maior grau, k = maior cor
    g[i].cor = acharCor(g, i); // função auxiliar que verifica qual cor pode colocar
    if(g[i].cor > *k) {
        *k = *k + 1;
    }
    No *p = g[i].inicio;
    while(p) {
        if(g[p->v].cor == 0) {
            prof(g, p->v, k);
        }
        p = p->prox;
    }
}

int acharCor(Vertice *g, int i){
    bool temCor[5];
    int j;
    for (j = 0; j <= 4; j++){
        temCor[j] = false;
    }
    No* p = g[i].inicio;
    while(p) {
        temCor[g[p->v].cor] = true;
        p = p->prox;
    }
    for (j = 1; j <= 4; j++){
        if(!temCor[4]) {
            return j;
        }
    }
}

// ÚLTIMOS PROBLEMAS

// EX 1: Exibir todos os vértices a partir de N arestas de distância do vértice i; 
/*  -- busca em largura calculando a distãncia de cada vértice
    -- quando chega em N, começa a exibir 
*/

// EX 2: (Questão 11 da lista)
/*  -- Qual vertice fez mais chamadas para outro país?
    --* não é um problema de busca
*/

// EX 3: Verifiar se existe algum ciclo a partir de i, e retornar seu comprimento.
/*  -- basicamente uma busca em profundidade
*/

/* EX 4: Em um grafo de visibilidade, verificar se existe um caminho i->j que não seja visivel a partir
de um vertice x 
    -- Passos:
    - Busca normal, porém limitando todos vértices adjacentes de X
*/

// EX 5: Verifique se um grafo se comporta como não dirigido, retornando true/false
/*  -- não usar busca
*/





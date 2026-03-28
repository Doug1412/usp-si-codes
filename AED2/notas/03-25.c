#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1;
#define false 0;
#define V = 5;

typedef struct s{
    int adj;
    int peso;
    struct s* prox;
} No;

typedef struct {
    No *inicio;
    int flag;
    int custo;
    int via;
} Vertice;

// AULA 25-03-2026
// COMPONENTES FORTEMENTE CONECTADOS (em grafo dirigidos)
// Conjuntos disjuntos de vertices mutualmente alcançaveis ("Comunidades")

/* Explicação
desenho de um grafo G com a seguinte configuração

0 -> 1
0 -> 3
1 -> 2
2 -> 3
2 -> 0

PASSO 1: Criar grafo transposto gT

1 -> 0
3 -> 0
2 -> 1
3 -> 2
0 -> 2

PASSO 2: Computar ordem de conclusão em profundidade em g(grafo original)

prof(g) = 3, 2, 1, 0

PASSO 3: Fazer busca em gT começando pelo ultimo vertice contido no passo 2. Tudo que for alcançavel
e não é parte do outro outro grupo forma um complemento

fazer busca em gT começando em 0

grupo A: 0, 1, 2
grupo B: 3

PASSO 4: 

*/

/*
grafo g

1 -> 2
1 -> 3
2 -> 5
2 -> 4
3 -> 4
4 -> 1
4 -> 7
5 -> 6
5 -> 7
6 -> 7
6 -> 9
6 -> 8
6 -> 10
7 -> 5
8 -> 10
9 -> 10
10 -> 9

(passo 1) criar gT 

2 -> 1
3 -> 1
5 -> 2
4 -> 2
4 -> 3
1 -> 4
7 -> 4
6 -> 5
7 -> 5
7 -> 6
9 -> 6
8 -> 6
10 -> 6
5 -> 7
10 -> 8
10 -> 9
9 -> 10

(passo 2) criar ordem de conclusão em profundidade, começando em qualquer lugar 
prof(g) = 3 9 10 8 7 6 5 4 3 2 1

(passo 3) criar os grupos começando pelo ultimo elemento da busca em profundidade

grupo A: 1, 2, 3, 4
grupo B: 5, 6 ,7
grupo C: 8
grupo D: 9, 10

*/

// IMPORTANTE: o grao ser ponderado NÂO IMPORTA para ser componente fortemente conectado

// ------------------- mudando de assunto --------------------------------------------


// ARVORE GERADORA MÍNIMA
// aplicado para grafos não dirigidos e ponderados
/*

desenho de um grafo

1-) Algoritmo de Kruskal

passo 1: começa com una flores de árvores trivias (desenhas só os vértices)
    0 1 2 3 4 5
passo 2: selecione a aresta de menor peso que não provoca ciclos
    aresta 1 - 2 com peso 1

passo 3: repetir até não haver mais arestas
    aresta 0 - 2 com peso 2
    aresta 0 - 1 com peso 3 não coloca porque é redundante, vai provocar ciclos
    aresta 3 - 5 com peso 4
    aresta 2 - 7 com peso 7
    aresta 2 - 4 com peso 5

Resultado final: custo minimo 19

2-) Algoritmo de Prim

passo 1: Escolhe um inicio qualquer e marca como seguro
passo 2: Examinar toda adjacência da zona segura inteira e incorpora aresta de menor custo em 
direção a um vertice não seguro
passo 3: repetir até cobrir todos os vértices 

3-) Caminho de custo mínimo entre todos os pares (Floyd D)

desenho de um grafo
desenho de uma matriz

*/

int i, j, k;
for(i = 1; i <= 3; i++) {
    for(j = 1; j <= 3; j++) {
        if (i == j) {
            a[i][j] = 0;
        }
        else {
            a[i][j] = m[i][j].peso;
        }
    }
}

for(k = 1; k <= 3; k++) {
    for(i = 1; i <= 3; i++) {
        for(j = 1; j <= 3; j++) {
            if(a[i][j] > a[i][k] + a[k][j]) {
                a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
}

// n tankei o fim da aula
// ele mostrou como funciona passo a passo com um grafo de vertices
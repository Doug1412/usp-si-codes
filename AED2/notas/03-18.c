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
    int flag;
    int dist;
} Vertice;

// AULA 18-03-2026
// BUSCA EM LARGURA - CONCLUSÃO -

// fez um desenho de grafo ponderado

// EX 1: Ordem de conclusão começando em i=1? (com base no grafico desenhado)
// (a) profundidade: 7 3 5 2 6 4 1
// (b) largura: 1 2 4 3 5 6 7

//EX 2: Criar uma lista com todos os elemntos em um radio N a partir de i
No * verticesRaio(Vertice *g, int N) {
    No *resp = NULL;
    // inicializar dist[ ] com infinito e dist[i] = 0
    zerarFlags(g);
    Fila F; inicializar(&F);
    enviarFila(F, i);
    g[i].flag = 1;

    while(F->inicio) {
        i = sairFila(&p);
        No *p = g[i].inicio;
        while(p) {
            if(g[p->adj].flag == 0) {
                g[p->adj].dist = g[i].dist + 1;
                if(g[p->adj].dist > N) {
                    while(F->incio) {
                        sairFila(&F);
                    }
                    return resp;
                }
                g[p->adj].flag = 1;
                entrarFila(&F, p->adj);
            }
            p = p->prox;
        }
        g[i].flag = 2;
        No * novo = (No *) malloc(sizeof(No));
        novo->adj = i;
        novo->prox = resp;
        resp = novo;
    }
    return resp;
}

// EX 3: Idem, porém:
// a) considerando apenas arestas de peso < 10
// b) evitando passar por vertices do tipo X


// Os vertices de por onde andamos se chama "Via", já que chamar de anterior confundiria com o anterior da lista ligada
// Uma nova coluna via no desenho da lista de adjacencia
/*
| n°| dist | via | vertices  | 
| 1 |   0  | -1  | 2 - 4 - 3 | // via -1 pq ele é o começo
| 2 |   1  |  1  | 3 - 5     | 
| 3 |   1  |  1  | 7         | 
| 4 |   1  |  1  | 5 - 6     | 
| 5 |   2  |  3  | /         | 
| 6 |   2  |  4  | 7         | 
| 7 |   2  |  3  | /         | 

a tabela acima responde perguntas de "qual é o caminho mais curto?", se eu quiser saber o caminho mais curto 
para o 7 é so olhar a via dele: a via do 7 é o 3 e a via do 3 é o 1 e o 1 n tem via pois é o começo, resposta final: 7 3 1

| n°| custo | vertices  | 
| 1 |   0   | 2 - 4 - 3 |
| 2 |   0   | 3 - 5     | 
| 3 |   0   | 7         | 
| 4 |   0   | 5 - 6     | 
| 5 |   0   | /         | 
| 6 |   0   | 7         | 
| 7 |   0   | /         | 

matriz com os pesos das arestas
   | 1 |  2  |  3  |  4  |  5 | 6 |  7  |
 1 |   | 10  | 30  | 10  |    |   |     |
 2 |   |     | 20  |     | 5  |   |     |
 3 |   |     |     |     |    |   | 15  |
 4 |   |     |     |     | 10 | 5 |     |
 5 |   |     |     |     |    |   |     |
 6 |   |     |     |     |    |   | 10  |
 7 |   |     |     |     |    |   |     |

essa responde "quanto custa essa viagem?"
*/

void custo(int m[V][V], int i, int custos[V]) {
    // custo[i] = 0 e definir = infinito // IMPORTANTE
    int flags[V];
    zerarFlags[flags];
    
    Fila F; inicializar(&F);
    enviarFila(F, i);

    while(F->inicio) {
        i = sairFila(&F);
        int c;
        for(c = 1; c <= V; c++) {
            if(m[i][c] > 0 && flags[c] == 0) {
                flags[c] = 1;
                entrarFila(&F, c);
                custos[c] = custo[i] + m[i][c]; // IMPORTANTE
            }
        }
        flags[i] = 2
    }
} // ex extra: converter para lista de adjacencia

// parte mais critica dessa função são as linhas 108 e 122
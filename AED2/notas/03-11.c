#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1;
#define false 0;
#define V = 5;

// AULA 11-03-2026
// BUSCA EM PROFUNDIDADE: ultimos exemplos

// Encontrar maior grupo de verticies em um grafo dividido.
int maiorInicio(Vertice *g) {
    int maiorI = -1;
    int maiorQuant = 0;
    zerarFlags(g);
    int i;

    for (i = 1; i <= V; i++) {
        int cont = 0;
        if(g[i].flag == 0) 
            prof(g, i &cont);
        if (cont > maiorQuant) {
            maiorQuant = cont;
            maiorI = i;
        }
    }
}

// EX2: grafo de viagens de avião separado por companhia, Verificar se há rota de de I até F usando apenas a companhia x;

typedef struct  s 
{
    int adj;
    struct s* prox;
    int cia; // campo int de codigo da companhia áerea
} No;

void existeRota (Vertice *g, int I, int F, int x, bool *achou) {
    if (*achou) return;
    
    if (I == F) {
        *achou = true;
        return;
    }

    g[i].flag = 1;
    No *p = g[i].inicio;

    while (p) {
        if (g[p->adj].flag == 0 && p->cia == x) {
            prof(g, p->adj, F, x, achou);
            if (*achou) return;
        }
        p = p->prox;
    }
}

// EX3: grafo de viagens de avião separado por companhia, Verificar se há um caminho de I até F passando por M
/* 
passo 1: testar caminho de I até M
passo 2: se não existe, erro e fim
passo 3: se exister, testar caminho de m até F

pseudo-codigo abaixo:
*/ 

bool achou = false;
zerarFlags(g);
prof(g, I, M, &achou);
if (!achou) {
    printf("Não existe I->M");
    return;
}

zerarFlags(g);
achou = false;
prof(g, M, F, &achou);
if (!achou) {
    printf("Não existe M->F");
    return;
}

printf("sucesso");

// EX4: Encontrar todos os vertices não alcançaveis a patir de I e liga-los a I com uma nova aresta
// sabe-se que usa busca por causa de "alcançaveis" e "partir de I"

void ligarNaoAlcancaveis(int m[V][V], int i) {
    int flags[V];
    zerarFlags(flags[V]);
    prof(m, i, flags[V]);
    for (int j = 1; j <= V; j++) {
        if (flags[j] == 0) {
            m[i][j] = 1;
        }
    }
}

// inserir aresta i,j em lista de adjacencia

No *novo = (No*) malloc(sizeof(No));
novo->adj = j;
novo->prox = g[i].inicio;
g[i].inicio = novo;


// EX5: grafo de salas de aula, Exibir até N salas do tipo X alcanãveis a partir de I

// antes de chamar, reiniciar flags
void exibiN(Vertice *g, int i, int *N, int tipoX) {
    if(*N == 0) return;
    g[i].flag = 1;
    if (g[i].tipo = tipoX) {
        *N = *N -1;
        if(*N == 0) return;
    }
    No* = g[i].inicio;
    while (p) {
        if(g[p->adj].flag == 0)
            exibirN(g, g->adj, N, tipoX);
        if(*N == 0) return;
        p = p->prox;
    }
}
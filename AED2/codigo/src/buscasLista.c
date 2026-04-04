#include <stdio.h>
#include <stdlib.h>
#include "../include/buscasLista.h"

// Busca em profundidade começando em i
void dfsLista(GrafoL *g, int i) {
    // rodar zerarFlagsLista(g) antes
    g->vertices[i].flag = 1; // Marca como "descobrindo" (1)
    
    No *p = g->vertices[i].inicio;
    while(p) {
        // Se o vizinho ainda não foi visitado (0)
        if (g->vertices[p->adj].flag == 0) {
            dfsLista(g, p->adj); // Visita recursivamente
        }
        p = p->prox;
    }
    
    g->vertices[i].flag = 2; // Marca como "finalizado" (2)
}

// Verificar se existe um caminho de i até j
/* ---------------------------- VERSÃO DO PROFESSOR ----------------------------
void dfsCaminhoLista(GrafoL *g, int i, int j, bool *achou) {
    // rodar zerarFlagsLista(g) antes
    if(i == j) {
        *achou = true;
        return;
    }

    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            dfsCaminhoLista(g, p->adj, j, achou);
        }
        if(*achou) {
            return;
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
}
------------------------------------------------------------------------------- */
bool dfsCaminhoLista(GrafoL *g, int i, int j) {
    // rodar zerarFlagsLista(g) antes
    if (i == j) return true;

    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            if (dfsCaminhoLista(g, p->adj, j)) {
                return true;
            }
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
    return false;
}

// Verificar se existe ciclo
void dfsCicloLista(GrafoL *g, int i) {
    // rodar zerarFlagsLista(g) antes
    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 1) {
            printf("Ciclo detectado de %d para %d\n", i, p->adj);
        }

        if (g->vertices[p->adj].flag == 0) {
            dfsCicloLista(g, p->adj);
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
}

// Contar quantas salas do tipo N alcançaveis a partir de i
void contarSalasTipoLista(GrafoL *g, int i, int N, int *cont) {
    // rodar zerarFlagsLista(g) antes
    if (g->vertices[i].tipo == N) {
        *cont = *cont + 1;
    }

    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            contarSalasTipoLista(g, p->adj, N, cont);
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
}

// Encontrar maior grupo de vertices em um grafo dividido.
int maiorInicioLista(GrafoL *g) {
    zerarFlagsLista(g);
    int maiorI = -1;
    int maiorQuant = 0;

    for(int i = 0; i < g->quantVertices; i++) {
        int cont = 0;
        if (g->vertices[i].flag == 0) {
            dfsContLista(g, i, &cont); 
            // função acima não implementada, mas ela é identica a dfsLista(), com a difença de que roda `*cont = *cont + 1;` após marcar uma flag = 1;
        }
        if (cont > maiorQuant) {
            maiorQuant = cont;
            maiorI = i;
        }
    }
    return maiorI;
}

// Grafo de viagens de avião sepado por companhia. Verificar se há rota de I até F usando apenas a companhia X
// Assumir que `g->vertices[i].inicio->tipo` guarda qual é a companhia
bool dfsViagemAviaoCompanhiaLista(GrafoL * g, int i, int F, int X) {
    // rodar zerarFlagsLista(g) antes
    if (i == F) {
        return true;
    }

    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;
    while(p) {
        // Verifica se não foi visitado E se a aresta pertence à companhia X
        if (g->vertices[p->adj].flag == 0 && p->tipo == X) {
            if (dfsViagemAviaoCompanhiaLista(g, p->adj, F, X)) {
                return true;
            }
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
    return false;
}

// Grafo de viagens de aviaão separado por companhia, Verificar se há um caminho de I até F passadno por M
bool viagemAviaoCompanhiaIaMaFLista(GrafoL *g, int I, int M, int F, int X) {
    zerarFlagsLista(g);

    if(dfsViagemAviaoCompanhia(g, I, M, X)) {
        zerarFlagsLista(g);
        if(dfsViagemAviaoCompanhia(g, M, F, X)) {
            return true;
        } else {
            printf("Não existe M->F");
            return false;
        }
    } else {
        printf("Não existe I->M");
        return false;
    }
}

// Encontrar todos os vetices não alcançaveis a partir de I e liga-los a I com uma nova aresta
void ligarNaoAlcancaveisLista(GrafoL *g, int i) {
    zerarFlagsLista(g);

    dfsLista(g, i);
    for (int j = 0; j < g->quantVertices; j++) {
        if(g->vertices[j].flag == 0) {
            No *novo = (No *) malloc(sizeof(No));
            novo->adj = j;
            novo->prox = g->vertices[i].inicio;
            g->vertices[i].inicio = novo;
        }
    }
}

// Grafo de salas de aual, Exibir até N salas do tipo X alcançaveis a partir de I;
void dfsExibirNLista(GrafoL * g, int i, int *N, int tipoX) {
    if(*N == 0) return;


    g->vertices[i].flag = 1;
    if (g->vertices[i].tipo == tipoX) {
        printf("Sala encontrada: Vértice %d\n", i);
        *N = *N - 1;
        if(*N == 0) return;
    }

    
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            dfsExibirNLista(g, p->adj, N, tipoX);
        }
        if(*N == 0) return;
        p = p->prox;
    }

    g->vertices[i].flag = 2;
}
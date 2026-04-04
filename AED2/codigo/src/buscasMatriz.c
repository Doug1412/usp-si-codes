#include <stdio.h>
#include <stdlib.h>
#include "../include/buscasMatriz.h"

// Busca em profundidade começando em i
void dfsMatriz(GrafoM *g, int i) {
    g->flags[i] = 1;
    
    for(int j = 0; j < g->totalVertices; j++) {
        if(g->matriz[i][j] == 1 && g->flags[j] == 0) {
            dfsMatriz(g, j);
        }
    }
    
    g->flags[i] = 2;
}

// Verificar se existe um caminho de i até j
bool dfsCaminhoMatriz(GrafoM *g, int i, int j) {
    // rodar zerarFlagsMatriz(g) antes
    if (i == j) {
        return true;
    }

    g->flags[i] = 1;
    for (int k = 0; k < g->totalVertices; k++) {
        if (g->matriz[i][k] == 1 && g->flags[k] == 0) {
            if (dfsCaminhoMatriz(g, k, j)) {
                return true;
            }
        }
    }
    g->flags[i] = 2;

    return false;
}

// Verificar se existe ciclo
void dfsCicloMatriz(GrafoM *g, int i) {
    // rodar zerarFlagsMatriz(g) antes
    g->flags[i] = 1;
    for (int j = 0; j < g->totalVertices; j++) {
        if (g->matriz[i][j] == 1 && g->flags[j] == 1) {
            printf("Ciclo detectado de %d para %d\n", i, j);
        }
 
        if (g->matriz[i][j] == 1 && g->flags[j] == 0) {
            dfsCicloMatriz(g, j);
        }
    }
    g->flags[i] = 2;
}

// INCOMPLETA: Contar quantas salas do tipo N alcançaveis a partir de i
void contarSalasTipoMatriz(GrafoM *g, int i, int N, int *cont) {
    // rodar zerarFlagsMatriz(g) antes
    
    // TODO: implementar essa função, não fiz porque teria que alterar a estrutura da matriz
}

// Verificar se há rota de I até F usando apenas a companhia X. 
bool dfsViagemAviaoCompanhiaMatriz(GrafoM * g, int i, int F, int X) {
    // TODO: implementar essa função, não fiz porque teria que alterar a estrutura da matriz
}

// Verificar se há um caminho de I até F passando por M.
// Variação de dfsViagemAviaoCompanhia()
bool viagemAviaoCompanhiaIaMaFMatriz(GrafoM *g, int I, int M, int F, int X){ 
    // TODO: implementar essa função, não fiz porque depende da função anterior
}

// Encontrar vetices não alcançaveis a partir de I e liga-los a I. Aula do dia 11-03-2026
void ligarNaoAlcancaveisMatriz(GrafoM *g, int i){
    zerarFlagsMatriz(g);

    dfsMatriz(g, i);

    for(int j = 0; j < g->totalVertices; j++) {
        if(g->flags[j] == 0) {
            g->matriz[i][j] = 1;
        }
    }
}

// Exibir até N salas do tipo X alcançaveis a partir de I.
void dfsExibirNMatriz(GrafoM * g, int i, int *N, int tipoX){
    // TODO: implementar essa função, não fiz porque teria que alterar a estrutura da matriz
}
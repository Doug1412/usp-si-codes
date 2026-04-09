#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrizAdjacencia.h"
#include "listaAdjacencia.h"

#include "buscasMatriz.h"
#include "buscasLista.h"


// 6. Uma árvore é dita enraizada se for um grafo acíclico, conexo e dirigido, com um único vértice fonte. Escreva um algoritmo que, dado um grafo g, verifique se é uma árvore enraizada ou não, retornando true/false conforme o caso.

bool exercicio06(GrafoL *g) {
    zerarFlagsLista(g);

    // Inicialixzar tipo de todos igual em zero, tipo = 0 -> é fonte; tipo = 1 -> não é fonte
    for (int i = 0; i < g->quantVertices; i++) {
        g->vertices[i].tipo = 0;
    }

    for (int i = 0; i < g->quantVertices; i++) {
        No *p = g->vertices[i].inicio;
        while(p) {
            g->vertices[p->adj].tipo = 1;
            p = p->prox;
        }
    }

    // Verificar se existe uma unica fonte
    int quantFontes = 0;
    int fonte = -1;
    for (int i = 0; i < g->quantVertices; i++) {
        if (g->vertices[i].tipo == 0) {
            quantFontes++;
            fonte = i;
        }
    }

    if (quantFontes != 1) {
        return false;
    }

    if (dfsCicloArvore(g, fonte) == false) {
        return false;
    }

    // Verificar se é conexo
    for (int i = 0; i < g->quantVertices; i++) {
        // Verificar se é conexo
        if (g->vertices[i].flag == 0) {
            return false;
        }
    }

    return true;
}

bool dfsCicloArvore(GrafoL *g, int i) {
    g->vertices[i].flag = 1;
    No *p = g->vertices[i].inicio;

    while(p) {
        // Verificar se é dirigido
        if (p->adj == i) {
            return false;
        } else {
            No *w = g->vertices[p->adj].inicio;
            while(w) {
                if (w->adj == i) {
                    return false;
                }
                w = w->prox;
            }
        }

        // Verificar se existe ciclo
        if (g->vertices[p->adj].flag != 0) { 
            return false;
        }

        if (dfsCicloArvore(g, p->adj) == false) {
            return false;
        }
        p = p->prox;
    }
    g->vertices[i].flag = 2;
    return true;
}

// Versão otimizada do codigo acima
bool exercicio07melhorado(GrafoL *g) {
    zerarFlagsLista(g);
    // considerar tipo = grau de entrada
    for (int i = 0; i < g->quantVertices; i++) {
        g->vertices[i].tipo = 0;
    }

    for (int i = 0; i < g->quantVertices; i++) {
        No *p = g->vertices[i].inicio;
        while(p) {
            g->vertices[p->adj].tipo = g->vertices[p->adj].tipo + 1;
            p = p->prox;
        }
    }

    int raiz = -1;
    int quantFonte = 0;
    for (int i = 0; i < g->quantVertices; i++) {
        if (g->vertices[i].tipo == 0) {
            quantFonte++;
            raiz = i;
        }

        if (g->vertices[i].tipo > 1) {
            return false;
        }
    }

    if (quantFonte != 1) {
        return false;
    }

    dfsLista(g, raiz);

    for (int i = 0; i < g->quantVertices; i++) {
        if (g->vertices[i].flag == 0) {
            return false;
        }
    }
    return true;
}

// 7. Seja um grafo g não-dirigido ponderado (com um peso inteiro associado a cada aresta). Escreva um algoritmo que, dado g e um custo mínimo int c, retorne uma cópia de g contendo apenas as arestas de custo maior do que c.

GrafoL * exercicio07(GrafoL *g, int c){
    GrafoL *g2 = inicializarLista(g2);

    for (int i = 0; i < g->quantVertices; i++) {
        No *p = g->vertices[i].inicio;
        while(p) {
            if (p->peso > c) {
                No *novo = (No *) malloc(sizeof(No));
                novo->adj = p->adj;
                novo->peso = p->peso;

                novo->prox = g2->vertices[i].inicio;
                g2->vertices[i].inicio = novo;
            }
            p = p->prox;
        }
    }

    return g2;
}

// 8. Sejam dois grafos g1 e g2 contendo exatamente os mesmos vértices. Verifique se g2 é um subgrafo de g1, retornando true/false conforme o caso. Para tornar o problema mais interessante, considere que um grafo é representado em listas e outro em matriz.

bool exercicio08(GrafoM * g1, GrafoL *g2) {
    //verificar se todas as arestas de g2 estão presentes em g1;
    for (int i = 0; i < g2->quantVertices; i++) {
        No *p = g2->vertices[i].inicio;
        while (p) {
            if (g1->matriz[i][p->adj] == 0) {
                return false;
            }
            p = p->prox;
        }
    }
    
    return true;
}

bool exercicio08v2(GrafoL * g1, GrafoM *g2) {
    //verificar se todas as arestas de g2 estão presentes em g1;
    for (int i = 0; i < g2->totalVertices; i++) {
        for (int j = 0; j < g2->totalVertices; j++) {
            if (g2->matriz[i][j] == 1) {
                bool existe = false;
                No *p = g1->vertices[i].inicio;
                while (p) {
                    if (p->adj == j) {
                        existe = true;
                        break;
                    }
                    p = p->prox;
                }
                if (!existe) return false;
            }
        }    
    }
    
    return true;
}

// 9. Dados dois grafos g1 e g2, escreva um algoritmo que retorne um grafo g3 cujas arestas estejam presentes em g1 mas não em g2.

GrafoL * exercicio09(GrafoL *g1, GrafoL *g2) {
    GrafoL *g3 = inicializarLista(g1->quantVertices);

    for (int i = 0; i < g1->quantVertices; i++) {
        No *p = g1->vertices[i].inicio;
        while (p) {
            // ver se não está presente em g2
            if (!arestaExiste09(g2, i, p->adj)) {
                // adicionar a g3
                No *novo = (No *) malloc(sizeof(No));
                novo->adj = p->adj;
                novo->prox = g3->vertices[i].inicio;
                g3->vertices[i].inicio = novo;
            }
            p = p->prox;
        }
    }
    return g3;
}

bool arestaExiste09(GrafoL *g, int i, int j) {
    No *p = g->vertices[i].inicio;
    while (p) {
        if (p->adj == j) {
            return true;
        }
        p = p->prox;
    }
    return false;
}

// 10. Considere um grafo dirigido em lista de adjacências representando uma rede de troca de emails, onde cada vértice representa um usuário, e cada aresta representa um email enviado. Cada aresta possui um campo int id que representa o conteúdo da mensagem (ou seja, o campo id faz parte da definição do nó das listas de adjacências). Problema: circula pela rede uma mensagem x do tipo spam. Escreva um algoritmo para exibir os usuários suspeitos de iniciar a propagação de x. Um usuário é considerado suspeito se ele próprio não recebeu a mensagem x nenhuma vez.

void exercio10(GrafoL *g, int x) {
    for (int i = 0; i < g->quantVertices; i++) {
        g->vertices[i].dist = 0; // dist = Recebeu o spam
        g->vertices[i].flag = 0; // flag = Enviou o spam
    }
    
    for(int i = 0; i < g->quantVertices; i++) {
        No *p = g->vertices[i].inicio;
        while(p) {
            if (p->tipo == x) { // considerar tipo = id
                g->vertices[p->adj].dist++; // destino recebeu spam
                g->vertices[i].flag = 1; // origem enviou spam (i)
            }
            p = p->prox;
        }
    }

    for (int i = 0; i < g->quantVertices; i++) {
        if (g->vertices[i].dist == 0 && g->vertices[i].flag == 1) {
            printf("O usuario %d é suspeito", i);
        }
    } 
}

// 11. Considere um grafo dirigido em lista de adjacências representando uma rede de chamadas telefônicas entre diversas unidades de uma empresa, onde cada vértice representa uma unidade, e cada aresta representa uma chamada efetuada. As unidades podem estar em diferentes países, identificados por um campo int país definido no respectivo vértice. Problema: a conta de telefone global da empresa está muito alta. Escreva um algoritmo que identifique a unidade que efetua chamadas para o maior número de países. Havendo empate, retorne qualquer resposta possível.

int exercicio11(GrafoL *g) {
    for (int i = 0; i < g->quantVertices; i++) {
        g->vertices[i].dist = 0; // dist = quantidade de paises diferentes
    }

    int resp = -1;
    for (int i = 0; i < g->quantVertices; i++) {
        No *p = g->vertices[i].inicio;
        while(p) {
            if (g->vertices[i].tipo != g->vertices[p->adj].tipo) { // tipo = pais
                g->vertices[i].dist++;
                if (g->vertices[i].dist > resp) {
                    resp = i;
                }
            }
            p = p->prox;
        }
    }

    return resp;
}
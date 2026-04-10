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

bool exercicio08(GrafoM *g1, GrafoL *g2) {
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

    int maiorChamadas;

    for (int i = 0; i < g->quantVertices; i++) {
        No *p = g->vertices[i].inicio;
        while(p) {
            int paisDestino = g->vertices[i].tipo; // tipo = id do pais
            
            bool jaVisto = false;

            No *aux = g->vertices[i].inicio;
            while (aux != p) {
                if (g->vertices[aux->adj].tipo != paisDestino) {
                    jaVisto = true;
                    break;
                }
                aux = aux->prox;
            }

            if (!jaVisto) {
                g->vertices[i].dist++; // Considerar dist = quantidade de paises diferentes
            }
            p = p->prox;
        }
        if (g->vertices[i].dist > g->vertices[maiorChamadas].dist) {
            maiorChamadas = i;
        }
    }
    return maiorChamadas;
}

// 12. Seja um grafo g não-dirigido. Escreva uma função para detectar se há algum ciclo em g, retornando true/false.
bool exercicio12(GrafoL *g){
    zerarFlagsLista(g);

    for (int i = 0; i < g->quantVertices; i++) {
        if (g->vertices[i].flag == 0) {
            if (!dfsE12(g, i, -1)) {
                return true;
            }
        }
    }

    return false;
}

bool dfsE12(GrafoL *g, int i, int pai) {
    g->vertices[i].flag = 1;

    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 1 && p->adj != pai) {
            return true;
        }

        if (g->vertices[p->adj].flag == 0) {
            if (dfsE12(g, p->adj, i)) {
                return true;
            }
        }
        p = p->prox;
    }
    
    g->vertices[i].flag = 2;

    return false;
}

// 13. Variação 1: remover a aresta que provoca um ciclo (ou aresta para trás, que fecha o ciclo).
void exercicio13(GrafoL *g){
    zerarFlagsLista(g);

    for (int i = 0; i < g->quantVertices; i++) {
        if (g->vertices[i].flag == 0) {
            dfsE13(g, i, -1);
        }
    }

    return;
}

void dfsE13(GrafoL *g, int i, int pai) {
    g->vertices[i].flag = 1;

    No *ant = NULL;
    No *p = g->vertices[i].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 1 && p->adj != pai) {
            No *remover = p;

            int vizinho = p->adj;

            if (ant == NULL) {
                g->vertices[i].inicio = p->prox;
            } else {
                ant->prox = p->prox;
            }
            
            p = p->prox;
            free(remover);

            ex13removerVolta(g, vizinho, i);

            continue;
        }

        if (g->vertices[p->adj].flag == 0) {
            dfsE12(g, p->adj, i);
        }
        ant = p;
        p = p->prox;
    }
    
    g->vertices[i].flag = 2;

    return;
}

void ex13removerVolta(GrafoL *g, int origem, int destino) {
    No *ant = NULL;
    No *p = g->vertices[origem].inicio;
    while (p) {
        if (p->adj == destino) {
            if (ant == NULL) {
                g->vertices[origem].inicio = p->prox;
            } else {
                ant->prox = p->prox;
            }
            free(p);
            return;
        }

        ant = p;
        p = p->prox;
    }
}

// 14. Seja um grafo g não-conexo e não-dirigido. Escreva uma função para contar a quantidade de grupos disjuntos de vértices mutuamente alcançáveis em g.

// 16. Seja um grafo g e dois vértices a e b. Verifique se há um caminho qualquer entre a e b retornando true/false conforme o caso.
// zerarFlagsLista(g);
bool exercicio16(GrafoL *g, int a, int b) {
    if (a == b) {
        return true;
    }

    g->vertices[a].flag = 1;
    No *p = g->vertices[a].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            if (exercicio16(g, p->adj, b)) {
                return true;
            }
        }
        p = p->prox;
    }
    g->vertices[a].flag = 2;
    return false;
}

// 17. Variação 1: contar quantos vértices há no caminho de a até b.
int exercicio17(GrafoL *g, int a, int b) {
    zerarFlagsLista(g);
    for(int i = 0; i < g->quantVertices; i++){
        g->vertices[i].dist = 999999;
    }
    g->vertices[a].dist = 0;

    if (ex17dfs(g, a, b)) {
        return g->vertices[b].dist + 1;
    }

    return 0;
}

bool ex17dfs(GrafoL *g, int a, int b) {
    if (a == b) {
        return true;
    }

    g->vertices[a].flag = 1;
    No *p = g->vertices[a].inicio;    
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            g->vertices[p->adj].dist = g->vertices[a].dist + 1;
            if (ex17dfs(g, p->adj, b)) {
                return true;
            }
        }
        p = p->prox;
    }
    g->vertices[a].flag = 2;
    return false;
}

// 18. Variação 2: retornar a lista dos vértices que compõe o caminho de a até b.
int * exercicio18(GrafoL *g, int a, int b) {
    zerarFlagsLista(g);
    
    for(int i = 0; i < g->quantVertices; i++){
        g->vertices[i].tipo = -1;
    }
    g->vertices[a].tipo = -1;

    int * resp = NULL;

    if(ex18dfs(g, a, b)) {
        int rastreador = b;
        int tamanho = 1;
        while (rastreador != a) {
            rastreador = g->vertices[rastreador].tipo;
            tamanho++;
        }

        resp = (int *) malloc(tamanho * sizeof(int));
        rastreador = b;
        for (int i = (tamanho-1); i >= 0; i--) {
            resp[i] = rastreador;
            rastreador = g->vertices[rastreador].tipo;
        }
    }
    return resp;
}

bool ex18dfs(GrafoL *g, int a, int b) {
    if (a == b) {
        return true;
    }

    g->vertices[a].flag = 1;
    No *p = g->vertices[a].inicio;
    while(p) {
        if (g->vertices[p->adj].flag == 0) {
            g->vertices[p->adj].tipo = a; // considerar tipo = via
            if (ex18dfs(g, p->adj, b)) {
                return true;
            }
        }
        p = p->prox;
    }
    g->vertices[a].flag = 2;
    return false;
}

// 19. Um grafo não dirigido é completo se todos seus vértices são adjacentes, ou seja, existe uma aresta conectando cada par de vértices de um grafo. Escreva um algoritmo que, dado um grafo simples g, verifique se g é completo, retornando true/false conforme o caso.
bool exercicio19(GrafoL *g) {
    int *caderninho;
    caderninho = (int *) malloc(g->quantVertices * sizeof(int));
    
    for (int i = 0; i < g->quantVertices; i++) {
        for (int k = 0; k < g->quantVertices; k++) {
            caderninho[k] = 0;
        }

        No *p = g->vertices[i].inicio;

        while(p) {
            caderninho[p->adj] = 1;
            p = p->prox;
        }

        for (int k = 0; k < g->quantVertices; k++) {
            if (caderninho[k] == 0 && k != i) {
                free(caderninho);
                return false;
            }
        }
    }
    free(caderninho);
    return true;
}

bool exercicio19v2(GrafoL *g) {
    for (int i = 0; i < g->quantVertices; i++) {
        int grau = 0;

        No *p = g->vertices[i].inicio;

        while(p) {
            grau++;
            p = p->prox;
        }

        if (grau != (g->quantVertices - 1)) {
            return false;
        }
    }
    return true;
}

// 20. Seja G = (V;A) um grafo simples e Ḡ= (V; V2-A) seu complemento, onde V2 é o conjunto de todos os pares de vértices em V . Escreva um método que, dado um grafo simples G, retorne seu complemento Ḡ.
GrafoL * exercicio20(GrafoL * g) {
    // Vertice *gC = (Vertice *) malloc(V * siozeof(Vertice));
    GrafoL *gC = inicializarLista(g->quantVertices);
    int *caderninho = (int *) malloc(g->quantVertices * sizeof(int));

    for (int i = 0; i < g->quantVertices; i++) {
        caderninho[i] = -1;
    }

    for (int i = 0; i < g->quantVertices; i++) {
        No *p = g->vertices[i].inicio;
        while(p) {
            caderninho[p->adj] = i;
            p = p->prox;
        }

         for (int k = 0; k < g->quantVertices; k++) {
            if (caderninho[k] != i && i != k) {
                No *novo = (No *) malloc(sizeof(No));
                novo->adj = k;
                novo->prox = gC->vertices[i].inicio;
                gC->vertices[i].inicio = novo;
            }
         }
    }
    free(caderninho);
    return gC;
}

// 21. Seja um grafo g representando salas de aula (vértices) e suas ligações (arestas). Cada sala possui uma ocupação representada por um inteiro. Escreva um algoritmo que, a partir da sala atual i, encontre a sala vazia mais próxima, retornando o número do vértice correspondente. Havendo mais de uma sala que atenda estas condições, retorne a primeira que encontrar.
int exercicio21(GrafoL *g, int i, int tipoSala) {
    zerarFlagsLista(g);
    
    Fila F;
    inicializarFila(&F);

    entrarFila(&F, i);
    g->vertices[i].flag = 1;
    while(F.inicio) {
        int v = sairFila(&F);

        No * p = g->vertices[v].inicio;
        while (p) {
            if (g->vertices[p->adj].flag == 0) {
                // sair cedo, se já encontrou finaliza logo o programa
                if (g->vertices[p->adj].tipo == tipoSala) { // considerar .tipo = .ocupacao
                    while(F.fim) {
                        sairFila(&F);
                    }
                    return p->adj;
                }

                g->vertices[p->adj].flag = 1;
                entrarFila(&F, p->adj);
            }
            p = p->prox;
        }
        g->vertices[v].flag = 2;
    }
    return -1;
}

// 22. Variação: havendo empate, retorne uma lista ligada contendo todas as salas vazias mais próximas.
No * exercicio22(GrafoL *g, int i, int tipoSala) {
    zerarFlagsLista(g);

    Fila f;
    inicializarFila(&f);

    entrarFila(&f, i);
    g->vertices[i].flag = 1;

    No *resultado = NULL;

    while(f.inicio) {
        int tamanhoNivel = tamanhoFila(&f);

        for (int n = 0; n < tamanhoNivel; n++) {
            int v = sairFila(&f);
            No *p =g->vertices[v].inicio;
            while(p) {
                if (g->vertices[p->adj].flag == 0) {
                    g->vertices[p->adj].flag = 1;

                    if (g->vertices[p->adj].tipo == tipoSala) {
                        No * novo = (No *) malloc(sizeof(No));
                        novo->adj = p->adj;
                        novo->prox = resultado;
                        resultado = novo;
                    } else {
                        entrarFila(&f, p->adj);
                    }
                } 
                p = p->prox;
            }
            g->vertices[v].flag = 2;
        }
        
        if (resultado) {
            return resultado;
        }
    }

    return NULL;
}
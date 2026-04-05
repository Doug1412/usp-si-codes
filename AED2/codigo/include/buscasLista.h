#ifndef BUSCASLISTA_H
#define BUSCASLISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listaAdjacencia.h"
#include "fila.h"

// ---------------------------- BUSCAS EM PROFUNDIDADE ----------------------------

// Busca em profundidade simples começando em i, aula do dia 04-03-2026
void dfsLista(GrafoL *g, int i); 

// Verificar se existe um caminho de i até j, aula do dia 06-03-2026
bool dfsCaminhoLista(GrafoL *g, int i, int j); 

// Verificar se exist ciclo, aula do dia 06-03-2026
void dfsCicloLista(GrafoL *g, int i);

// Contar quantas salas do tipo N alcançaveis a partir de i, aula do dia 06-03-2026
void contarSalasTipoLista(GrafoL *g, int i, int N, int *cont);

// Encontrar maior grupo de vertices em um grafo dividido. Aula do dia 11-03-2026
int maiorInicioLista(GrafoL *g);

// Verificar se há rota de I até F usando apenas a companhia X. Aula do dia 11-03-2026 
// Assumir que `g->vertices[i].inicio->tipo` guarda qual é a companhia
bool dfsViagemAviaoCompanhiaLista(GrafoL * g, int i, int F, int X);

// Verificar se há um caminho de I até F passando por M. Aula do dia 11-03-2026
// Variação de dfsViagemAviaoCompanhia()
bool viagemAviaoCompanhiaIaMaFLista(GrafoL *g, int I, int M, int F, int X);

// Encontrar vetices não alcançaveis a partir de I e liga-los a I. Aula do dia 11-03-2026
void ligarNaoAlcancaveisLista(GrafoL *g, int i);

// Exibir até N salas do tipo X alcançaveis a partir de I. Aula do dia 11-03-2026
void dfsExibirNLista(GrafoL * g, int i, int *N, int tipoX);

// ---------------------------- BUSCAS EM LARGURA ---------------------------------

// Busca em largura simples começando em i. Aula do dia 13-03-2026
void bfsLista(GrafoL *g, int i);

// Encontrar o posto de gasolina mais próximo, tipo = 1.
int tipoXmaisPertoLista(GrafoL *g, int i, int tipoX);

// Qual o comprimento do caminho mais curto de v1 a v2? Aula do dia 13-03-2026
int comprimentoLista(GrafoL *g, int v1, int v2);

// Criar uma lista de todos os elementos em um raio N a partir de i. Aula do dia 18-03-2026
No * verticesRaioLista(GrafoL * g, int i, int N); 
// Variação considerando apenas arestas de peso < 10 e evitando passar por vertices do tipo X
No * verticesRaioLista2(GrafoL * g, int i, int N, int tipoX); 

#endif // BUSCASLISTA_H
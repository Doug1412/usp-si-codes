#ifndef BUSCASLISTA_H
#define BUSCASLISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listaAdjacencia.h"

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


#endif // BUSCASLISTA_H
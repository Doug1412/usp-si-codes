#ifndef MATRIZLISTA_H
#define MATRIZLISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrizAdjacencia.h"
#include "fila.h"

// ---------------------------- BUSCAS EM PROFUNDIDADE ----------------------------


// Busca em profundidade simples começando em i, aula do dia 06-03-2026
void dfsMatriz(GrafoM *m, int i);

// Verificar se existe um caminho de i até j, aula do dia 06-03-2026
bool dfsCaminhoMatriz(GrafoM *g, int i, int j);

// Verificar se existe ciclo, aula do dia 06-03-2026
void dfsCicloMatriz(GrafoM *g, int i);

// INCOMPLETA: Contar quantas salas do tipo N alcançaveis a partir de i, aula do dia 06-03-2026
void contarSalasTipoMatriz(GrafoM *g, int i, int N, int *cont);

// Verificar se há rota de I até F usando apenas a companhia X. 
bool dfsViagemAviaoCompanhiaMatriz(GrafoM * g, int i, int F, int X);

// Verificar se há um caminho de I até F passando por M.
// Variação de dfsViagemAviaoCompanhia()
bool viagemAviaoCompanhiaIaMaFMatriz(GrafoM *g, int I, int M, int F, int X);

// Encontrar vetices não alcançaveis a partir de I e liga-los a I. Aula do dia 11-03-2026
void ligarNaoAlcancaveisMatriz(GrafoM *g, int i);

// Exibir até N salas do tipo X alcançaveis a partir de I.
void dfsExibirNMatriz(GrafoM * g, int i, int *N, int tipoX);

// ---------------------------- BUSCAS EM LARGURA ---------------------------------

// Busca em largura simples começando em i. Aula do dia 13-03-2026
void bfsMatriz(GrafoM *g, int i);

// Encontrar o posto de gasolina mais próximo, tipo = 1. Aula do dia 13-03-2026
int tipoXmaisPertoMatriz(GrafoM *g, int i, int tipoX);

// Qual o comprimento do caminho mais curto de v1 a v2?
int comprimentoMatriz(GrafoM *g, int v1, int v2);

#endif // MATRIZLISTA_H
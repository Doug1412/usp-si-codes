#ifndef MATRIZLISTA_H
#define MATRIZLISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrizAdjacencia.h"

// Busca em profundidade simples começando em i, aula do dia 06-03-2026
void dfsMatriz(GrafoM *m, int i);

// Verificar se existe um caminho de i até j, aula do dia 06-03-2026
bool dfsCaminhoMatriz(GrafoM *g, int i, int j);

// Verificar se existe ciclo, aula do dia 06-03-2026
void dfsCicloMatriz(GrafoM *g, int i);

// INCOMPLETA: Contar quantas salas do tipo N alcançaveis a partir de i, aula do dia 06-03-2026
void contarSalarTipoMtriz(GrafoM *g, int i, int N, int *cont);

#endif // MATRIZLISTA_H
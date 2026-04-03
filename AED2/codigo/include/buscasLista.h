#ifndef BUSCASLISTA_H
#define BUSCASLISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listaAdjacencia.h"

// Busca em profundidade simples começando em i, aula do dia 04-03-2026
void dfsLista(GrafoL *g, int i); 

// Verificar se existe um caminho de i até j, aula do dia 06-03-2026
bool dfsCaminhoLista(GrafoL *g, int i, int j); 

// Verificar se exist ciclo, aula do dia 06-03-2026
void dfsCicloLista(GrafoL *g, int i);

// Contar quantas salas do tipo N alcançaveis a partir de i, aula do dia 06-03-2026
void contarSalarTipoLista(GrafoL *g, int i, int N, int *cont);

#endif // BUSCASLISTA_H
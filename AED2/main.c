#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **dados;
    int size;
} MatrizAdjacencia;


MatrizAdjacencia * inicializarMatriz(size) {
    MatrizAdjacencia *m;
    m = (MatrizAdjacencia *) malloc(sizeof(MatrizAdjacencia));

    m->size = size;

    m->dados = (int **) malloc(m->size * sizeof(int *));

    for (int i = 0; i < m->size; i++) {
        m->dados[i] = (int *) malloc(m->size * sizeof(int));
        for (int j = 0; j < m->size; j++) {
            m->dados[i][j] = 0;
        }
    }

    return m;
}  

void imprimirMatriz(MatrizAdjacencia *m) {
    for (int i = 0; i < m->size; i++) { 
        for(int j = 0; j < m->size; j++) {
            printf("%d", m->dados[i][j]);
        }
        printf("\n");
    }
}

void liberarMatriz(MatrizAdjacencia *m) {
    for (int i = 0; i < m->size; i++) {
        free(m->dados[i]); // Libera as colunas
    }
    free(m->dados); // Libera o vetor de ponteiros
    free(m); // Libera a struct
}

int main(){
    int size = 100;
    MatrizAdjacencia *matriz = inicializarMatriz(size);

    imprimirMatriz(matriz);
    
    liberarMatriz(matriz);

    return 0;
}
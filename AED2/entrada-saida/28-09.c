#include <stdio.h>
#include <stdbool.h>

struct tipo_registro {
    char nrousp[7];
    char nome[20];
    int idade;
};

int tam = sizeof(tipo_registro);

void aniversario (FILE *arq, int nrousp) {
    int end = buscaSeq(arq, nrousp);
    if (end == -1) {
        return;
    }
    tipo_registro R;
    fread(&R, tam, 1, arq);
    R.idade++;
    fseek(arq, - tam, SEEK_CUR);
    fwrite(&R, tam, 1, arq);
}


// mudança no struct para melhorar desempenho na hora de apagar dados
struct tipo_registro {
    char nrousp[7];
    char nome[20];
    int idade;
    bool valido; // campo novo, true = dado existe, false = dado "apagado"
};

// funcao que faz uma exclusao logica em um registro
void exclusaoLogica (FILE *arq, int nrousp) {
    int end = buscaSeq(arq, nrousp); // busca deve garantir que é valido
    if (end == -1) {
        return;
    }
    tipo_registro R;
    fread(&R, tam, 1, arq);
    R.valido = false;
    fseek(arq, - tam, SEEK_CUR);
    fwrite(&R, tam, 1, arq);
}

// funcao para compactar os dados (usada quando se tem um arquivo cheio de registros invalidos ai limpar ele)
void copiarValidos(char *nome1, char *nome2) {
    FILE *arq1 = fopen(nome1, "rb");
    FILE *arq2 = fopen(nome2, "wb");
    tipo_registro R;
    while (1 == fread(&R, tam, 1, arq1)) {
        if (!R.valido) continue;
        fwrite(&R, tam, 1, arq2);
    }
    fclose(arq1);
    fclose(arq2);
}

bool inserir (tipo_registro *R, FILE *arq) {
    int end = buscaSeq(arq, R->nrousp); // CUSTO ALTO
    if (end != -1) 
        return false; // ja existe
    fseek(arq, 0, SEEK_END);
    fwrite(R, tam, 1, arq);
    return true;
}

// trocar posicao fisica dos 2 registros
void swap (int n1, int n2, FILE *arq) {
    int end1 = buscaSeq(n1, arq);
    if (end1 == -1) 
        return; 
    
    int end2 = buscaSeq(n2, arq);
    if (end2 == -1) 
        return; 

    tipo_registro R1, R2;

    // le registro 1
    fseek(arq, end1 * tam, SEEK_SET);
    fread(&R1, tam, 1, arq);

    // le registro 2
    fseek(arq, end2 * tam, SEEK_SET);
    fread(&R2, tam, 1, arq);

    // escreve 1
    fseek(arq, end2 * tam, SEEK_SET);
    fwrite(&R1, tam, 1, arq);
    
    // escreve 2
    fseek(arq, end1 * tam, SEEK_SET);
    fwrite(&R2, tam, 1, arq);
}

// anexar arq2 ao final de arq1

// passos, 1 - abrir arq1 e posicionar ao final, 2 - ler arq2 sequencialmente e escrever em arq1
void anexarArquvo(FILE *arq1, FILE *arq2) {
    fseek(arq1, 0, SEEK_END);
    fseek(arq2, 0, SEEK_SET);
    tipo_registro r;
    while (1 == fread(&r, tam, 1, arq2)) {
        fwrite(&r, tam, 1, arq1);
    }
}

// -------- AULA 02 ------------
// - comparação entre arquvios
// - a necessidade de ordenação

// Ex1: comparar 2 arquivos, ordenados considerando que há registros excluidos
bool compararOrdenados(FILE *arq1, FILE *arq2) {
    fseek(arq1, 0, SEEK_SET);
    fseek(arq2, 0, SEEK_SET);
    tipo_registro R1, R2;
    while (true) {
        R1 = proximoValido(arq1);
        R2 = proximoValido(arq2);
        // incompleto
    }
}

// outra versao
bool compararOrdenados(FILE *arq1, FILE *arq2) {
    fseek(arq1, 0, SEEK_SET);
    tipo_registro r1;
    while (1 == fread(&r1, tam, 1, arq1)) {
        int end = buscaSeq(r1.nrousp, arq2); // custo proibitivo
        if (end == -1) return false;
    }
    return true; 
}

tipo_registro proximoValido(FILE *arq) {
    tipo_registro r;
    r.nrousp = 0;
    while (true) {
        int lidos = fread(&r, tam, 1, arg);
        if (lidos == 0)
            return r; // vazio
        if (r.valido)
            return r; // achou
    }
}


// 1 Ler arquivo e Montar tabela em memoria contendo <chave, end>
typedef struct {
    int chave;
    int end;
} item_tab;

// key sort

item_tab tab[MAX];
int prox = 0;
item_tab r;
while (1 == fread(&r, tam, 1, arq)) {
    tab[prox] = r;
    prox++;
}

// 2 Ordenar (tab); por chave
// 3 reescrever o arquivo na ordem da tabela

for (i = 0; i <= prox; i++) {
    int end = tab[i].end;
    // le 1
    fseek(arq, end * tam, SEEK_SET);
    fread(&r, tam, 1, arg);
    
    // le 2
    fseek(arq, i * tam, SEEK_SET);
    fread(&r2, tam, 1, arg);

    fseek(arq, i * tam, SEEK_SET);
    fwrite(&r, tam, 1, arg);

    fseek(arq, emd * tam, SEEK_SET);
    fwrite(&r2, tam, 1, arg);
}
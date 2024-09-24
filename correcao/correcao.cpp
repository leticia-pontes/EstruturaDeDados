#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int paginas;
} Documento;

typedef struct {
    int primeiro, ultimo, tamanho, capacidade_total;
    Documento* documento;
} Fila;

Fila* criarfila(int capacidade_total) {
    Fila* f = (Fila*)calloc(1, sizeof(Fila));
    f->capacidade_total = capacidade_total;
    f->primeiro = 0;
    f->ultimo = capacidade_total - 1;
    f->tamanho = 0;
    f->documento = (Documento*)calloc(capacidade_total, sizeof(Documento));
    return f;
}

void inserirDocumento(Fila* f, Documento arquivo) {
    if (f->tamanho == f->capacidade_total) {
        printf("\nEstá Cheia!\n");
    }
    else {
        f->ultimo = (f->ultimo + 1) % f->capacidade_total;
        f->documento[f->ultimo] = arquivo;
        f->tamanho++;
    }
}

Documento* removerDocumento(Fila* f) {
    if (f->tamanho == 0) {
        printf("\nFila esta Vazia!\n");
    }
    else {
        Documento* arquivo_removido = f->documento + f->primeiro;
        f->primeiro = (f->primeiro + 1) % f->capacidade_total;
        f->tamanho--;
        return arquivo_removido;
    }
}

void apresentarDocumento(Fila* f) {
    int primeiro = f->primeiro;
    for (int i = 0; i < f->tamanho; i++) {
        printf("\nNome: %s\n", f->documento[primeiro].nome);
        printf("\nPáginas: %d\n", f->documento[primeiro].paginas);
        primeiro = (primeiro + 1) % f->capacidade_total;
    }
}

int main() {
    int tamanho;
    printf("Digite quantos arquivos deseja imprimir: ");
    scanf_s(" %d", &tamanho);
    Fila* f = criarfila(tamanho);
    Documento arquivo;

    for (int i = 0; i < f->capacidade_total; i++) {
        printf("\nInsira o nome do arquivo: ");
        scanf_s(" %s", arquivo.nome, 40);
        printf("\nQuantas páginas tem esse arquivo: ");
        scanf_s(" %d", &arquivo.paginas);
        inserirDocumento(f, arquivo);
    }
    printf("\n");
    apresentarDocumento(f);

    Documento* arquivo_removido = removerDocumento(f);

    printf("\nO documento removido foi %s - %d\n\n", arquivo_removido->nome, arquivo_removido->paginas);

    apresentarDocumento(f);

    return 0;
}
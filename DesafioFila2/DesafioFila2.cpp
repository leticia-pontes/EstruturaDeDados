#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[40];
    int paginas;
} Documento;

typedef struct {
    int primeiro, ultimo, tamanho, capacidade;
    Documento* arquivo;
} Fila;

Fila* CriarFila(int capacidade) {
    Fila* f = (Fila*)calloc(1, sizeof(Fila));
    f->capacidade = capacidade;
    f->tamanho = 0;
    f->primeiro = 0;
    f->ultimo = f->capacidade - 1;
    f->arquivo = (Documento*)calloc(capacidade, sizeof(Documento));
    return f;
}

void Enfileirar(Fila* f, Documento doc) {
    if (f->tamanho == f->capacidade) {
        printf("ERRO - Fila Cheia!\n");
    }
    else {
        f->ultimo = (f->ultimo + 1) % f->capacidade;
        f->arquivo[f->ultimo] = doc;
        f->tamanho++;
    }
}

Documento* Desenfileirar(Fila* f) {
    if (f->tamanho == 0) {
        printf("ERRO - Fila Vazia!\n");
        static Documento arquivoImpresso = { "null", 0 };
        return &arquivoImpresso;
    }
    else {
        Documento* arquivoImpresso = f->arquivo + f->primeiro;
        f->primeiro = (f->primeiro + 1) % f->capacidade;
        f->tamanho--;
        return arquivoImpresso;
    }
}

void ApresentarFila(Fila* f) {
    int primeiro = f->primeiro;
    for (int it = 0; it < f->tamanho; it++) {
        if (it == 0) printf("\nEm impressao:\n");
        else if (it == 1) printf("\nNa fila:\n");
        printf("\n%s - %d pagina(s)\n", f->arquivo[primeiro].nome, f->arquivo[primeiro].paginas);
        primeiro = (primeiro + 1) % f->capacidade;
    }
    printf("\n");
}

int main() {
    int tamanho;

    printf("Quantos documentos serao impressos? ");
    scanf("%d", &tamanho);

    Fila* fila = CriarFila(tamanho);

    Documento documento;

    for (int it = 0; it < fila->capacidade; it++) {
        printf("\n");
        printf("Nome do arquivo: ");
        scanf("%s", arquivo.nome);
        printf("Numero de paginas: ");
        scanf("%d", &arquivo.paginas);
        Enfileirar(fila, documento);
    }

    ApresentarFila(fila);

    Documento* arquivoImpresso = Desenfileirar(fila);

    printf("\nO documento removido foi %s - %d", arquivoImpresso->nome, arquivoImpresso->paginas);

    ApresentarFila(fila);

    return 0;
}
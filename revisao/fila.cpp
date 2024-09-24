#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct {
    int* valorInt;
    float* valorFloat;
    int tamanho, capacidade, primeiro, ultimo;
} Fila;

Fila* criarFila(int capacidade) {
    Fila* f = (Fila*)calloc(1, sizeof(Fila));
    f->tamanho = 0;
    f->capacidade = capacidade;
    f->primeiro = 0;
    f->ultimo = capacidade - 1;
    f->valorInt = (int*)calloc(capacidade, sizeof(int));
    f->valorFloat = (float*)calloc(capacidade, sizeof(float));
    return f;
}

void enfileirar(Fila* f, int valorInt, float valorFloat) {
    if (f->tamanho == f->capacidade) {
        cout << "ERRO - Fila cheia" << endl;
    }
    else {
        f->ultimo = (f->ultimo + 1) % f->capacidade;
        *(f->valorInt + f->ultimo) = valorInt;
        *(f->valorFloat + f->ultimo) = valorFloat;
        f->tamanho++;
    }
}

void mostrarFila(Fila* f) {
    int primeiro = f->primeiro;

    for (int it = 0; it < f->tamanho; it++) {
        cout << "(" << *(f->valorInt + primeiro) << ", " << f->valorFloat[primeiro] << ") -> ";
        primeiro = (primeiro + 1) % f->capacidade;
    }
    cout << "NULL" << endl;
}

int main() {

    Fila* fila;

    fila = criarFila(7);

    for (int it = 0; it < 7; it++) {
        enfileirar(fila, it, (it * .253416 + rand() - rand()) * .0005);
    }

    mostrarFila(fila);
}
#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct {
    int tamanho;
    int topo;
    float* itens;
} Pilha;


Pilha* criarPilha(int tamanho) {
    Pilha* p = (Pilha*)calloc(1, sizeof(Pilha));
    p->tamanho = tamanho;
    p->topo = -1;
    p->itens = (float*)calloc(tamanho, sizeof(float));
    return p;
}

void push(Pilha* p, float valor) {
    if(p->topo == p->tamanho - 1) {
        cout << "ERRO - Pilha cheia" << endl;
    }
    else {
        p->topo++;
        p->itens[p->topo] = valor;
    }
}

void mostrarPilha(Pilha* p) {
    if (p->topo == -1) {
        cout << "Pilha vazia" << endl;
    }
    else {
        for (int it = 0; it <= p->topo; it++) {
            cout << *(p->itens + it) << " -> ";
        }
        cout << "NULL" << endl;
    }
}

float pop(Pilha* p) {
    if (p->topo == -1) {
        cout << "ERRO - Pilha vazia" << endl;
        return 0;
    }
    else {
        float valorPop = *(p->itens + p->topo);
        p->topo--;
        return valorPop;
    }
}

int main() {
    Pilha* pilha;
    pilha = criarPilha(8);

    for (int it = 0; it < 7; it++) {
        push(pilha, 0.253 * it);
    }

    mostrarPilha(pilha);

    pop(pilha);
    pop(pilha);
    pop(pilha);

    mostrarPilha(pilha);
}
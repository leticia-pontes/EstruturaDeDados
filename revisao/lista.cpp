#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct No {
    int valorInteiro;
    float valorFloat;
    No* proximo;
} No;

typedef struct {
    No* primeiroNo;
} Lista;


Lista* criarLista() {
    Lista* l = (Lista*)calloc(1, sizeof(Lista));
    l->primeiroNo = NULL;
    return l;
}

void criarNo(Lista* l, int valorInteiro, float valorFloat) 
{
    No* novoNo = (No*)calloc(1, sizeof(No));
    
    novoNo->valorInteiro = valorInteiro;
    novoNo->valorFloat = valorFloat;
    novoNo->proximo = l->primeiroNo;

    l->primeiroNo = novoNo;
}

void mostrarLista(Lista* l) {
    No* aux = l->primeiroNo;

    while (aux != NULL) {
        cout << "(" << aux->valorInteiro << ", " << aux->valorFloat << ") -> ";
        aux = aux->proximo;
    }
    cout << "NULL";
}


int main() {

    int a = 5;
    cout << a << endl;

    int* pA = &a;
    cout << pA << " " << &pA << " " << *pA << endl;

    Lista* lista;

    lista = criarLista();

    for (int it = 0; it < 7; it++) {
        criarNo(lista, rand(), (it / 2) + 0.25);
    }

    mostrarLista(lista);
}
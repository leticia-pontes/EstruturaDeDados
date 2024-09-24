#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct No {
    int valor;
    No* anterior;
    No* proximo;
} No;


typedef struct {
    No* primeiro;
    No* ultimo;
} Lista;


Lista* criarLista() {
    Lista* l = (Lista*)calloc(1, sizeof(Lista));
    l->primeiro = NULL;
    l->ultimo = NULL;
    return l;
}

void criarNo(Lista* l, int valor) {
    No* novoNo = (No*)calloc(1, sizeof(No));
    novoNo->valor = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = l->primeiro;
    
    if (l->primeiro == NULL) {
        l->ultimo = novoNo;
    }
    else {
        novoNo->proximo->anterior = novoNo;
    }
    l->primeiro = novoNo;
}

void mostrarLista(Lista* l) {
    No* aux = l->primeiro;

    while (aux != NULL) {
        cout << aux->valor << " -> ";
        aux = aux->proximo;
    }
    cout << "NULL";
}

int main() {
    Lista* lista;

    lista = criarLista();

    for (int it = 0; it < 8; it++) {
        criarNo(lista, it);
    }

    mostrarLista(lista);
    
}
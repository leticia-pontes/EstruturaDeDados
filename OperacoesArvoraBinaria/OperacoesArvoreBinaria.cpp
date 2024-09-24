#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct No {
    int valor;
    No* esq;
    No* dir;
} No;


No* criarNo(int qtde, int it) {
    No* newNo;
    
    if (qtde == 0) {
        newNo = NULL;
    }
    else {
        newNo = (No*)calloc(1, sizeof(No));
        cout << "Digite o valor do No: ";
        cin >> newNo->valor;
        
        newNo->esq = criarNo(qtde / 2, it + 1);
        newNo->dir = criarNo(qtde - qtde / 2 - 1, it + 1);
    }
    return newNo;
}

// Encontra as folhas com pré ordem
void mostrarFolhas(No* raiz) {
    if (raiz != NULL) {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            cout << raiz->valor << endl;
        }
        mostrarFolhas(raiz->esq);
        mostrarFolhas(raiz->dir);
    }
}

int encontrarAltura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    else {
        int esq = encontrarAltura(raiz->esq);
        int dir = encontrarAltura(raiz->dir);

        if (esq <= dir)
            return dir + 1;
        else
            return esq + 1;
    }
}

void encontrarNo(No* raiz, int valor) {
    if (raiz != NULL) {
        if (raiz->valor == valor) {
            cout << "Encontrou";
        }
        else {
            cout << '.';
        }
        encontrarNo(raiz->esq, valor);
        encontrarNo(raiz->dir, valor);
    }
}

int encontrarFolha(No* raiz) {
    if (raiz != NULL) {
        if (raiz->esq != NULL && raiz->dir != NULL) {
            encontrarFolha(raiz->esq);
            encontrarFolha(raiz->dir);
        }
    }
    return raiz->valor;
}






// FINAL
No* inserirNoArvoreBinariaBusca(No* raiz, int valor) {

    if (raiz == NULL) {
        No* newNo = (No*)calloc(1, sizeof(No));
        newNo->valor = valor;
        newNo->esq = NULL;
        newNo->dir = NULL;
        return newNo;
    }

    if (valor < raiz->valor) {
        raiz->esq = inserirNoArvoreBinariaBusca(raiz->esq, valor);
    }
    
    else if (valor > raiz->valor) {
        raiz->dir = inserirNoArvoreBinariaBusca(raiz->dir, valor);
    }

    return raiz;
}

void mostrarArvoreInOrdem(No* raiz) {
    if (raiz != NULL) {
        mostrarArvoreInOrdem(raiz->esq);
        cout << raiz->valor << " ";
        mostrarArvoreInOrdem(raiz->dir);
    }
}


int main() {

    // No* raiz;

    // raiz = criarNo(10, 0);

    // cout << "\nFolhas" << endl;

    // mostrarFolhas(raiz);

    // cout << endl;

    // int altura = encontrarAltura(raiz);

    // cout << "\nAltura: " << altura << endl;

    // int valor;

    // cout << "\nDigite o valor a ser encontrado: ";
    // cin >> valor;

    // cout << endl;
    // encontrarNo(raiz, valor);

    // cout << endl << endl;



    No* arvoreBinBusca = NULL;

    for (int i = 0; i < 10; ++i) {
        int valor;
        cout << "Digite o valor do No: ";
        cin >> valor;
        arvoreBinBusca = inserirNoArvoreBinariaBusca(arvoreBinBusca, valor);
    }

    mostrarArvoreInOrdem(arvoreBinBusca);

    return 0;
}
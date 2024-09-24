#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;


typedef struct No {
    int valor;
    No* proximo;
    No* anterior;
} No;

typedef struct {
    No* primeiro;
    No* ultimo;
} Lista;


Lista* CriarLista() {
    Lista* lista = (Lista*)calloc(1, sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}



void InserirNoInicio(Lista* lista, int valor) {
    No* new_no = (No*)calloc(1, sizeof(No));
    new_no->valor = valor;

    new_no->anterior = NULL;
    new_no->proximo = lista->primeiro;

    lista->primeiro = new_no;
    lista->ultimo = new_no;
}

//void MostrarLista(Lista* lista) {
//    No* aux = lista->primeiro;
//
//    cout << "Início -> " << aux->valor << " -> " << endl;
//    aux = aux->proximo;
//
//    while (aux->anterior != NULL) {
//        cout << aux->valor << " -> " << endl;
//        aux = aux->proximo;
//    }
//}



int main()
{
    setlocale(LC_ALL, "pt_BR.utf-8");

    Lista* lista;
    lista = CriarLista();

    InserirNoInicio(lista, 5);
    //MostrarLista(lista);

    InserirNoInicio(lista, 10);
}
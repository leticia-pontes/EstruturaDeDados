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

	if (lista->ultimo == NULL) lista->ultimo = new_no;
	else new_no->proximo->anterior = new_no;

	lista->primeiro = new_no;
}


void InserirNoFinal(Lista* lista, int valor) {
	No* new_no = (No*)calloc(1, sizeof(No));
	new_no->valor = valor;

	new_no->proximo = NULL;
	new_no->anterior = lista->ultimo;

	if (lista->primeiro == NULL) lista->primeiro = new_no;
	else lista->ultimo->proximo = new_no;

	lista->ultimo = new_no;
}


void RemoverNoInicio(Lista* lista) {
	No* primeiro = lista->primeiro;

	if (primeiro == NULL) cout << "\nLista Vazia!" << endl;

	else if (lista->ultimo == primeiro) {
		lista->primeiro = NULL;
		lista->ultimo = NULL;
		free(primeiro);
	}

	else {
		lista->primeiro = primeiro->proximo;
		lista->primeiro->anterior = NULL;
		free(primeiro->anterior);
	}
}

void RemoverNoFinal(Lista* lista) {
	No* ultimo = lista->ultimo;

	if (ultimo == NULL) cout << "\nLista Vazia!" << endl;

	else if (lista->primeiro == ultimo) {
		lista->primeiro = NULL;
		lista->ultimo = NULL;
		free(ultimo);
	}

	else {
		lista->ultimo = ultimo->anterior;
		lista->ultimo->proximo = NULL;
		free(ultimo->proximo);
	}
}


void MostrarLista(Lista* lista) {

	No* auxiliar = lista->primeiro;

	cout << endl;

	while (auxiliar != NULL) {
		cout << auxiliar->valor << " -> ";
		auxiliar = auxiliar->proximo;
	}
	cout << "NULL" << endl;
}



int main() {

	setlocale(LC_ALL, "pt_BR.utf-8");

	Lista* lista1;
	lista1 = CriarLista();

	int n, valor;


	cout << "Inserindo e removendo no início" << endl;

	cout << "\nNúmero de nós: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "\nValor Nó " << i + 1 << ": ";
		cin >> valor;

		InserirNoInicio(lista1, valor);
	}

	MostrarLista(lista1);

	RemoverNoInicio(lista1);
	MostrarLista(lista1);

	RemoverNoInicio(lista1);
	MostrarLista(lista1);

	RemoverNoInicio(lista1);
	MostrarLista(lista1);


	Lista* lista2;
	lista2 = CriarLista();

	cout << "\nInserindo e removendo no final" << endl;

	cout << "\nNúmero de nós: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "\nValor Nó " << i + 1 << ": ";
		cin >> valor;

		InserirNoFinal(lista2, valor);
	}

	MostrarLista(lista2);

	RemoverNoFinal(lista2);
	MostrarLista(lista2);

	RemoverNoFinal(lista2);
	MostrarLista(lista2);

}
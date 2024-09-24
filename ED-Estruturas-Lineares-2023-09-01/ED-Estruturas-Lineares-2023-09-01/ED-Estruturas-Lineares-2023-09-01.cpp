#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;


/* Estrutura de Nó
*  O nome 'No' precisa ser declarado no começo pois é utilizado dentro da struct.
*/
typedef struct No {
	int valor;
	struct No* proximo;
} No; 
// O nome 'No' é declarado pois nas próximas linhas a palavra struct não precisa ser incluída.


// Estrutura que aponta para o primeiro nó. O primeiro nó dá acesso à lista inteira.
typedef struct {
	No* primeiro;
} Lista;


// Iniciando a lista

Lista* criacao() { // Declara a função com retorno do tipo ponteiro de Lista.

	// Está alocando memória para a lista l.
	// Está armazenando apenas UMA lista
	Lista* l = (Lista*)calloc(1, sizeof(Lista));

	l->primeiro = NULL; // Inicia a lista com valor NULL. SEMPRE é iniciado dessa forma.
	return l;
}

void inserirValorInicio(Lista* l, int valor) {
	No* novo_no = (No*)calloc(1, sizeof(No));
	novo_no->valor = valor;
	novo_no->proximo = l->primeiro;
	l->primeiro = novo_no;

	/* Insere sempre no início
	*  Lista -> no
	*  Lista -> novo_no1 -> no
	*  Lista -> novo_no2 -> novo_no1 -> no
	*/
}

void RemoverPrimeiroNo(Lista* lista) {
	No* inicial = lista->primeiro;
	
	if (inicial == NULL) {
		cout << "\nLista vazia" << endl;
	}
	else {
		lista->primeiro = inicial->proximo;
		free(inicial);
	}
}

void RemoverUltimoNo(Lista* lista) {

	if (lista->primeiro == NULL) {
		cout << "\nLista está vazia!" << endl;
	}
	else {
		No* aux = lista->primeiro;
		if (aux->proximo == NULL) {
			lista->primeiro = NULL;
			free(aux);
		}
		else {
			while (aux->proximo->proximo != NULL) {
				aux = aux->proximo;
			}
			free(aux->proximo);
			aux->proximo = NULL;
		}
	}
}

void MostrarLista(Lista* lista) {
	No* aux = lista->primeiro;

	while (aux != NULL) {
		cout << aux->valor << " -> ";
		aux = aux->proximo;
	}
	cout << "NULL" << endl;
}

int main() {
	Lista* lista;
	lista = criacao();

	for (int i = 0; i < 7; i++) {
		inserirValorInicio(lista, rand() % 30);
	}
	
	MostrarLista(lista);
	cout << endl;
	RemoverPrimeiroNo(lista);
	MostrarLista(lista);
	cout << endl;
	RemoverUltimoNo(lista);
	MostrarLista(lista);
	cout << endl;

	return 0;
}
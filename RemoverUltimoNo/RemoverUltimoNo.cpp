#include <iostream>

using namespace std;


typedef struct No {
	int valor;
	struct No* proximo;
} No;

typedef struct {
	No* primeiro;
} Lista;

Lista* CriarLista() {
	Lista* lista = (Lista*)calloc(1, sizeof(Lista));
	lista->primeiro = NULL;
	return lista;
}

void AdicionarNo(Lista* lista, int valor) {
	No* new_no = (No*)calloc(1, sizeof(No));

	new_no->valor = valor;
	new_no->proximo = lista->primeiro;

	lista->primeiro = new_no;	
}


int main() {


	return 0;
}
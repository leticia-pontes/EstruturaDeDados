#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <iostream>
#include <string>
#include <vector>
#include <variant>

using namespace std;


typedef struct No {
	int valorInt;
	float valorFloat;
	struct No* proximo;
} No;

typedef struct Lista {
	No* primeiro;
} Lista;

Lista* CriarLista() {
	Lista* lista = (Lista*)calloc(1, sizeof(Lista));
	lista->primeiro = NULL;
	return lista;
}


void InserirValorInicio(Lista* l, int valorInt, float valorFloat) {

	No* new_no = (No*)calloc(1, sizeof(No*));
	new_no->valorFloat = valorFloat;
	new_no->valorInt = valorInt;
	new_no->proximo = l->primeiro;
	l->primeiro = new_no;
}


void MostrarLista1(Lista* lista) {
	No* auxiliar = lista->primeiro;

	while (auxiliar != NULL) {
		printf("%d -> ", auxiliar->valorInt);
		auxiliar = auxiliar->proximo;
	}
	printf("NULL\n");
}

void MostrarLista2(Lista* lista) {
	No* auxiliar = lista->primeiro;

	while (auxiliar != NULL) {

		if (auxiliar->valorInt == 0) {
			cout << auxiliar->valorFloat << " -> ";
		}
		else if (auxiliar->valorFloat == 0.0) {
			cout << auxiliar->valorInt << " -> ";
		}
		else {
			printf("%d -> %.2f -> ", auxiliar->valorInt, auxiliar->valorFloat);
		}
		auxiliar = auxiliar->proximo;
	}
	printf("NULL\n");
}


void Exercicio1() {

	Lista* lista1;
	lista1 = CriarLista();

	int valor;

	for (int it = 0; it < 5; it++) {
		printf("\nValor %d: ", it + 1);
		scanf_s("%d", &valor);
		InserirValorInicio(lista1, valor, 0.);
	}

	printf("\n");
	MostrarLista1(lista1);
}

void Exercicio2() {

	Lista* lista2;
	lista2 = CriarLista();

	int valorInt;
	float valorFloat;

	printf("\nValor inteiro: ");
	scanf_s("%d", &valorInt);
	InserirValorInicio(lista2, valorInt, 0);

	printf("\nValor float: ");
	scanf_s("%f", &valorFloat);
	InserirValorInicio(lista2, 0, valorFloat);

	printf("\n");
	MostrarLista2(lista2);
}


void InserirValorFinal(Lista* l, int valor) {

	No* new_no = (No*)calloc(1, sizeof(No*));

	new_no->valorInt = valor;
	new_no->valorFloat = 0;
	new_no->proximo = NULL;

	if (l->primeiro == NULL) {
		l->primeiro = new_no;
	}
	else {
		No* atual = l->primeiro;
		while (atual->proximo != NULL) {
			atual = atual->proximo;
		}
		atual->proximo = new_no;
	}
}

void Exercicio3() {
	Lista* lista3;

	lista3 = CriarLista();
	
	InserirValorFinal(lista3, 10);
	InserirValorFinal(lista3, 20);
	InserirValorFinal(lista3, 30);
	InserirValorFinal(lista3, 40);

	MostrarLista1(lista3);
}


int main() {

	setlocale(LC_ALL, "pt_BR.utf-8");

	int executar;

	printf("\nQual exercício deseja executar?\n");
	printf("\n1. Armazenando 5 valores no início da lista");
	printf("\n2. Lista com tipos diferentes de valores");
	printf("\n3. Inserir valores no final\n\n");
	scanf_s("%d", &executar);
	printf("\n");

	switch (executar) {
		case 1:
			Exercicio1();
			break;
		case 2:
			Exercicio2();
			break;
		case 3:
			Exercicio3();
			break;
		default:
			printf("\nError");
			break;
	}

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//
//// Recursividade
//int fatorial(int n) {
//	if (n == 0) {
//		return 1;
//	}
//	else {
//		return n* fatorial(n - 1);
//	}
//}
//
//// Recursividade Fibonacci
//int fibonacci(int n) {
//	if (n <= 1) {
//		return n;
//	}
//	else {
//		return fibonacci(n - 1) + fibonacci(n - 2);
//	}
//}
//
//int somatorio(int n) {
//	if (n == 0) {
//		return 0;
//	}
//	else {
//		return n + somatorio(n - 1);
//	}
//}
//
//int potencia(int base, int expoente) {
//	if (expoente == 0) {
//		return 1;
//	}
//	else {
//		return base * potencia(base, expoente - 1);
//	}
//}
//



typedef struct No {
	int valor;
	struct No* dir;
	struct No* esq;
}No;

No* criarNo(int qtde) {
	No* novono;
	if (qtde == 0) {
		novono = NULL;
	}
	else {
		novono = (No*)calloc(1, sizeof(No));
		printf("Digite o valor de No: ");
		scanf_s("%d", &novono->valor);

		novono->esq = criarNo(qtde / 2);
		novono->dir = criarNo(qtde - qtde / 2 - 1);
	}
	return novono;
}


void apresentar(No* raiz) {
	if (raiz != NULL) {
		printf(" %d ", raiz->valor);
		apresentar(raiz->esq);
		apresentar(raiz->dir);
	}
}


// Encontrar todas as folhas
void folhas(No* raiz) {
	if (raiz != NULL) {
		if (raiz->esq == NULL and raiz->dir == NULL) {
			printf(" %d ", raiz->valor);
		}
		else {
			folhas(raiz->esq);
			folhas(raiz->dir);
		}
	}
}


void naoFolhas(No* raiz) {
	if (raiz != NULL) {
		if (raiz->esq != NULL or raiz->dir != NULL) {
			printf(" %d ", raiz->valor);
			naoFolhas(raiz->esq);
			naoFolhas(raiz->dir);
		}
	}
}


int main() {

	No* raiz;
	
	raiz = criarNo(10);

	cout << "\nArvore: ";
	apresentar(raiz);
	cout << endl;

	cout << "\nFolhas: ";
	folhas(raiz);

	cout << "\nNao Folhas: ";
	naoFolhas(raiz);

	cout << endl;
	return 0;
}
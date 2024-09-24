#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int* AlocarTamanho(int t) {
	int* ponteiro;
	ponteiro = (int*)calloc(t, sizeof(int));
	return ponteiro;
}

void InserirElementos(int* p, int t) {
	for (int n = 0; n < t; n++) {
		printf("\nValor %d: ", n);
		scanf_s("%d", (p + n));
	}
}

void MostrarElementos(int* p, int t) {
	for (int n = 0; n < t; n++) {
		printf("\n%d", *(p + n));
	}
}

int Maior(int* p, int t) {

	int maior = 0;

	for (int i = 0; i < t; i++) {
		if (*(p + i) > maior) {
			maior = *(p + i);
		}
	}

	return maior;
}

int Menor(int* p, int t) {

	int menor = *p;

	for (int i = 0; i < t; i++) {
		if (*(p + i) < menor) {
			menor = *(p + i);
		}
	}

	return menor;
}

void OrdenarVetor(int* p, int t, int maior) {

	int indice = 0;

	for (int i = 0; i <= maior; i++) {
		for (int j = 0; j < t; j++) {

			if (*(p + j) == i) {

				int aux = *(p + indice);
				*(p + indice) = *(p + j);
				*(p + j) = aux;
				indice++;
			}
		}
	}
}


void BuscaBinaria(int* p, int t, int maior) {
	
	int menor = 0, meio = maior / 2;

	OrdenarVetor(p, t, maior);

	int valor;

	printf("\nQual valor deseja encontrar?   ");
	scanf_s("%d", &valor);


	for (int i = 0; i < t; i++) {
		if (valor == *(p + i)) {
			printf("\nO valor %d foi encontrado com %d passo(s)", valor, i);
		}
	}

	int min = 0, max = maior;

	for (int j = 0; j <= meio; j++) {
		for (int k = 0; k < t; k++) {
			
			if (valor == *(p + k)) {
				printf("\nO valor %d foi encontrado com %d passo(s)", valor, j);
				goto fim;
			}

			else if (valor > *(p + k)) {
				min = meio;
			}

			else if (valor < *(p + k)) {
				max = meio;
			}

			meio = (min + max) / 2;
		}
	}
	fim:;
}


int main() {

	int* ponteiro;
	int tamanho;

	printf("\nInforme o tamanho do vetor: ");
	scanf_s("%d", &tamanho);

	ponteiro = AlocarTamanho(tamanho);

	InserirElementos(ponteiro, tamanho);

	int maior = Maior(ponteiro, tamanho);
	int menor = Menor(ponteiro, tamanho);

	BuscaBinaria(ponteiro, tamanho, maior);

	MostrarElementos(ponteiro, tamanho);
}
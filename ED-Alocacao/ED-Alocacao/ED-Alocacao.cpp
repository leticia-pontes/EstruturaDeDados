#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


int* AlocarVetor(int t) {
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

int MaiorNumero(int* p, int t) {
	int* maior;
	
	maior = p;

	for (int n = 0; n < t; n++) {
		if (*(p + n) > *maior) {
			maior = p + n;
		}
	}

	return *maior;
}

int MenorNumero(int* p, int t) {
	int* menor;

	menor = p;

	for (int n = 0; n < t; n++) {
		if (*(p + n) < *menor) {
			menor = p + n;
		}
	}

	return *menor;
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

	printf("\nVetor Ordenado\n");
	MostrarElementos(p, t);
	printf("\n");

}


int main() {

	int* ponteiro; // Cria somente o ponteiro porque o vetor será criado dinamicamente
	int tamanho, maior, menor;

	printf("\nInforme o tamanho do vetor: ");
	scanf_s("%d", &tamanho);

	ponteiro = AlocarVetor(tamanho);

	InserirElementos(ponteiro, tamanho);

	MostrarElementos(ponteiro, tamanho);

	maior = MaiorNumero(ponteiro, tamanho);
	printf("\n\nO maior valor eh %d\n", maior);

	menor = MenorNumero(ponteiro, tamanho);
	printf("\nO menor valor eh %d\n", menor);

	OrdenarVetor(ponteiro, tamanho, maior, menor);

	return 0;
}
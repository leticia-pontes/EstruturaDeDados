#include <iostream>
#include <stdlib.h>

using namespace std;


void inserirValorVetor(int* vetor, int tamanho) {
	for (int it = 0; it < tamanho; it++) {
		cout << "Digite o valor " << it + 1 << ": ";
		cin >> vetor[it];
		cout << endl;
	}
}

void mostrarVetor(int* vetor, int tamanho) {
	for (int it = 0; it < tamanho; it++) {
		cout << vetor[it] << " ";
	}
	cout << endl;
}

// Ordenação por Inserção (insertionsort): divide os elementos em duas subestruturas - ordenados e pendentes.
// * Primeiro elemento já é ordenado
// * "ordenados" vai crescendo e "pendentes" vai diminuindo
// * Elementos maiores são deslocados para a direita

void insertionSort(int* vetor, int tamanho) {
	int i, j;
	int temp;

	for (i = 1; i < tamanho; i++) {
		temp = vetor[i];
		j = i - 1;

		while (j >= 0 && vetor[j] > temp) {
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = temp;
	}
}


// Ordenação por bolhas (bubblesort): Flutua o maior elemento para a direita

void bubbleSort(int* vetor, int tamanho) {
	int i, j, temp;

	for (i = 0; i < tamanho; i++) {

		for (j = 0; j < tamanho - i - 1; j++) {

			if (vetor[j] > vetor[j + 1]) {
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
}


// Ordenação por seleção (selectionsort): Pega o menor elemento e leva ao começo, enquanto aumenta o índice inicial do vetor.

void selectionSort(int* vetor, int tamanho) {
	int i, j;

	for (i = 0; i < tamanho; i++) {

		for (j = i; j < tamanho; j++) {

			if (vetor[i] > vetor[j]) {
				int temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
}


int main() {

	int tamanho;

	int* vetorInsertion, *vetorBubble, *vetorSelection;


	// Insertion Sort

	cout << "Insertion Sort" << endl;
	cout << "Digite o tamanho do vetor: ";
	cin >> tamanho;
	cout << endl;
	vetorInsertion = (int*)calloc(tamanho, sizeof(int));

	inserirValorVetor(vetorInsertion, tamanho);
	insertionSort(vetorInsertion, tamanho);
	mostrarVetor(vetorInsertion, tamanho);


	// Bubble Sort

	cout << "\nBubble Sort" << endl;
	cout << "Digite o tamanho do vetor: ";
	cin >> tamanho;
	cout << endl;
	vetorBubble = (int*)calloc(tamanho, sizeof(int));

	inserirValorVetor(vetorBubble, tamanho);
	bubbleSort(vetorBubble, tamanho);
	mostrarVetor(vetorBubble, tamanho);


	// Selection Sort

	cout << "\nSelection Sort" << endl;
	cout << "Digite o tamanho do vetor: ";
	cin >> tamanho;
	cout << endl;
	vetorSelection = (int*)calloc(tamanho, sizeof(int));

	inserirValorVetor(vetorSelection, tamanho);
	selectionSort(vetorSelection, tamanho);
	mostrarVetor(vetorSelection, tamanho);
	
	return 0;
}
/*
* Implementação de sistema de impressão do LIA (Laboratório de IA da
* UNIMAR) e precisa garantir que os documentos sejam impressos na
* ordem em que foram enviados para a fila de impressão.
* 
* Implemente um programa em C que simule o processo de impressão.
* 
* Lembrar de criar uma struct “Documento” que contém o nome do arquivo e a quantidade de páginas.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct {
	char nomeArquivo[40];
	int nPaginas;
} Documento;

typedef struct {
	int primeiro, ultimo, tamanho, capacidade;
	Documento* documento;
} Fila;

Fila* CriarFila(int capacidade) {
	Fila* f = (Fila*)calloc(1, sizeof(Fila));
	f->capacidade = capacidade;
	f->tamanho = 0;
	f->primeiro = 0;
	f->ultimo = f->capacidade - 1;
	f->documento = (Documento*)calloc(capacidade, sizeof(Documento));
	return f;
}

void Enfileirar(Fila* f, char nomeArquivo[], int nPaginas) {
	
	if (f->tamanho == f->capacidade) {
		cout << "ERRO - Fila Cheia!" << endl;
	}
	else {
		f->ultimo = (f->ultimo + 1) % f->capacidade;
		strcpy_s(f->documento[f->tamanho].nomeArquivo, nomeArquivo);
		f->documento[f->tamanho].nPaginas = nPaginas;
		f->tamanho++;
	}
}

Documento* Desenfileirar(Fila* f) {

	if (f->tamanho == 0) {
		cout << "ERRO - Fila Vazia!" << endl;
		Documento arquivoImpresso = { "null", 0 };
		return &arquivoImpresso;
	}
	else {
		Documento* arquivoImpresso = f->documento + f->primeiro;
		f->primeiro = (f->primeiro + 1) % f->capacidade;
		f->tamanho--;
		return arquivoImpresso;	
	}
}

void ApresentarFila(Fila* f) {

	int primeiro = f->primeiro;

	for (int it = 0; it < f->tamanho; it++) {

		if (it == 0) cout << endl << "\nEm impressao:" << endl;
		else if (it == 1) cout << endl << "\nNa fila:" << endl;

		cout << endl << f->documento[primeiro].nomeArquivo << " - " << f->documento[primeiro].nPaginas << " pagina(s)";
		primeiro = (primeiro + 1) % f->capacidade;
	}
	cout << endl;
}

int main() {

	int capacidadeFila;

	cout << "Quantos documentos serao impressos?  ";
	cin >> capacidadeFila;

	Fila* fila = CriarFila(capacidadeFila);

	char nomeArquivo[40];
	int nPaginas;

	for (int it = 0; it < fila->capacidade; it++) {
		cout << endl;

		cout << "Nome do arquivo: ";
		cin >> nomeArquivo;

		cout << "Numero de paginas: ";
		cin >> nPaginas;

		Enfileirar(fila, nomeArquivo, nPaginas);
	}

	ApresentarFila(fila);

	Documento* arquivoImpresso = Desenfileirar(fila);

	cout << "\nO documento " << arquivoImpresso->nomeArquivo << " (" << arquivoImpresso->nPaginas << " pagina(s)) foi impresso" << endl;

	ApresentarFila(fila);

	return 0;
}
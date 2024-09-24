#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;


typedef struct {
	char nome[100];
	char endereco[100];
} Site;

typedef struct {
	int tamanho;
	int topo;
	Site* site;
} Navegacao;

Navegacao* CriarPilha(int tamanho) {
	Navegacao* sites = (Navegacao*)calloc(1, sizeof(Navegacao));
	sites->tamanho = tamanho;
	sites->topo = -1;
	sites->site = (Site*)calloc(tamanho, sizeof(Site));
	return sites;
}

void InserirSite(Navegacao* n, char nome[], char endereco[]) {

	if (n->topo == n->tamanho - 1) {
		cout << "\nERRO - Pilha cheia!" << endl;
	}
	else {
		n->topo++;
		strcpy_s(n->site[n->topo].nome, nome);
		strcpy_s(n->site[n->topo].endereco, endereco);
	}
}

Site* RemoverSite(Navegacao* n) {

	if (n->topo == -1) {
		cout << "\nERRO - Pilha vazia!" << endl;
		Site site_removido = { "null", "null" };
		Site* pointer_site = &site_removido;
		return pointer_site;
	}
	else {
		Site* site_removido = n->site + n->topo;
		n->topo--;
		cout << "O site foi removido" << endl;
		return site_removido;
	}
}

void MostrarNavegacao(Navegacao* n) {

	if (n->topo == -1) {
		cout << "\nPilha vazia!" << endl;
	}
	else {
		cout << "Pilha:" << endl;
		for (int it = 0; it <= n->topo; it++) {
			cout << n->site[it].nome << " - " << n->site[it].endereco << endl;
		}
		cout << endl;
	}
}


int main() {

	int tamanho;

	cout << "Tamanho da pilha: ";
	cin >> tamanho;

	Navegacao* sites = CriarPilha(tamanho);
	
	cout << endl;

	char nome[100], endereco[100];

	for (int it = 0; it < tamanho; it++) {
		cout << "\nNome " << it + 1 << ": ";
		cin >> nome;

		cout << "Endereco " << it + 1 << ": ";
		cin >> endereco;

		InserirSite(sites, nome, endereco);
	}

	cout << endl;
	MostrarNavegacao(sites);

	Site* site_removido = RemoverSite(sites);

	cout << endl << "O site removido foi: " << site_removido->nome << " - " << site_removido->endereco << endl;

	cout << endl;
	MostrarNavegacao(sites);
}
#include <stdio.h>
#include <iostream>
#include <locale.h>

using namespace std;


typedef struct {
	int codigo;
	int idade;
	char nome[50];
	char raca[50];
} Cachorro;

Cachorro CadastrarCachorro(Cachorro* c, int codigo) {

	char resetar_string;

	c->codigo = codigo;

	printf("\nDigite o nome do cão: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(c->nome, 50, stdin);

	printf("Digite a raça do cão: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(c->raca, 50, stdin);

	printf("Digite a idade do cão: ");
	scanf_s("%d", &c->idade);
	
	return *c;
}

void MostrarInformacoesCachorro(Cachorro* c) {
	printf("\nCódigo: %d", c->codigo);
	printf("\nNome: %s", (*(c)).nome);
	printf("Raça: %s", (*(c)).raca);
	printf("Idade: %d\n", c->idade);
}

void CompararRacaUpperCase(char* raca) {
	for (int i = 0; raca[i]; i++) {
		if (raca[i] >= 'a' && raca[i] <= 'z') {
			raca[i] -= 32;
		}
	}
}

void FormatarStringRaca(char* raca) {
	for (int i = 0; raca[i]; i++) {
		if (i > 0) {
			if (raca[i] >= 'A' && raca[i] <= 'Z') {
				raca[i] += 32;
			}
		}
	}
}

bool VerificarRaca(Cachorro *pcao) {

	CompararRacaUpperCase(pcao->raca);

	if (strcmp(pcao->raca, "PINSCHER") == 1) {
		FormatarStringRaca(pcao->raca);
		return true;
	}
	else { return false; }
}

void ExercicioCachorro() {

	Cachorro cachorro[10];
	Cachorro* pointer_cachorro;
	int c = 0; //iterador

	pointer_cachorro = cachorro;

	for (c = 0; c < 3; c++) {
		*(pointer_cachorro + c) = CadastrarCachorro(pointer_cachorro + c, c);
	}

	bool eh_pinscher;

	for (c = 0; c < 3; c++) {
		eh_pinscher = VerificarRaca(pointer_cachorro + c);
		if (eh_pinscher) {
			MostrarInformacoesCachorro(pointer_cachorro + c);
		}
	}
}


typedef struct {
	int numero;
	char nome[50];
	char tipo[50];
} Pokemon;

Pokemon CadastrarPokemon(Pokemon* pointer, int numero) {
	
	char resetar_string;

	pointer->numero = numero;

	printf("\nNome: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(pointer->nome, 50, stdin);

	printf("Tipo: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(pointer->tipo, 50, stdin);

	return *pointer;
}

void MostrarPokemon(Pokemon* p) {
	printf("\nNúmero: %d", p->numero);
	printf("\nNome: %s", (*(p)).nome);
	printf("Tipo: %s\n", (*(p)).tipo);
}

void ExercicioPokemon() {
	
	Pokemon pokedex[6];
	Pokemon* pointer_pokedex;

	pointer_pokedex = pokedex;

	int p = 0; //iterador

	for (p = 0; p < 6; p++) {
		*(pointer_pokedex + p) = CadastrarPokemon(pointer_pokedex + p, p);
	}

	printf("\n");
	for (p = 0; p < 6; p++) {
		MostrarPokemon(pointer_pokedex + p);
	}
}


void ExercicioBusca() {
	int valores[5];
	int* p_valores;

	p_valores = valores;

	printf("\n");
	for (int n = 0; n < 5; n++) {
		printf("Valor %d\n", n);
		scanf_s("%d", (p_valores + n));
	}

	int maior = *(p_valores);

	for (int n = 0; n < 5; n++) {
		if (*(p_valores + n) > maior) {
			maior = *(p_valores + n);
		}
	}

	printf("\nO maior valor é %d\n", maior);
}


int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");

	int opcao = 0;

	printf("\nExercícios\n");
	printf("1. Cachorro\n");
	printf("2. Pokemon\n");
	printf("3. Busca\n");
	scanf_s("%d", &opcao);

	switch (opcao) {
		case 1:
			ExercicioCachorro();
			break;
		case 2:
			ExercicioPokemon();
			break;
		case 3:
			ExercicioBusca();
	}
}
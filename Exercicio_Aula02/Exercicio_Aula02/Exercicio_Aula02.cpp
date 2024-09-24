#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;


// Calculadora
float Soma(float a, float b) {
	return a + b;
}

float Subtracao(float a, float b) {
	return a - b;
}

float Multiplicacao(float a, float b) {
	return a * b;
}

float Divisao(float a, float b) {
	return a / b;
}

void Exercicio1() {
	float n1, n2, resultado = 0;
	int operacao;

	printf("\n\nInsira dois valores (podem ser decimais)\n");
	printf("Primeiro valor: ");
	scanf_s("%f", &n1);
	printf("Segundo valor: ");
	scanf_s("%f", &n2);

	printf("\nEscolha a operação\n1. Soma\n2. Subtração\n3. Multiplicação\n4. Divisão\n");
	scanf_s("%d", &operacao);

	switch (operacao) {

	case 1:
		resultado = Soma(n1, n2);
		break;
	case 2:
		resultado = Subtracao(n1, n2);
		break;
	case 3:
		resultado = Multiplicacao(n1, n2);
		break;
	case 4:
		resultado = Divisao(n1, n2);
		break;
	default:
		printf("Operação Inválida");
	}

	printf("\nO resultado da operação é %.2f\n", resultado);
}


// Cadastro de cachorros
typedef struct {
	char nome[20];
	char raca[35];
	int idade;
} Cachorro;

void Exercicio2() {

	Cachorro cachorro;
	char resetar_string;

	printf("\n\nCadastro do cachorro");

	printf("\nNome: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(cachorro.nome, sizeof(cachorro.nome), stdin);

	printf("Raça: ");
	fgets(cachorro.raca, sizeof(cachorro.raca), stdin);

	printf("Idade: ");
	scanf_s("%d", &cachorro.idade);

	printf("\n\nDados do cachorro\nNome: %sRaça: %sIdade: %d\n", cachorro.nome, cachorro.raca, cachorro.idade);
}


// Cadastro e consulta de quadrinhos
typedef struct {
	char nome[45];
	char autor[50];
	int n_edicao;
	int ano_publicacao;
	char idioma[30];
} Quadrinho;

Quadrinho CadastroQuadrinho() {
	Quadrinho quadrinho;
	char resetar_string;

	printf("\nNome: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(quadrinho.nome, sizeof(quadrinho.nome), stdin);

	printf("Autor: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(quadrinho.autor, sizeof(quadrinho.autor), stdin);

	printf("Número da edição: ");
	scanf_s("%d", &quadrinho.n_edicao);

	printf("Ano de publicação: ");
	scanf_s("%d", &quadrinho.ano_publicacao);

	printf("Idioma: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(quadrinho.idioma, sizeof(quadrinho.idioma), stdin);

	return quadrinho;
}

void ConsultaQuadrinho(Quadrinho quadrinho, int indice_consulta_quadrinho) {

	printf("\nQuadrinho - Índice %d\n", indice_consulta_quadrinho);
	printf("\nNome: %s", quadrinho.nome);
	printf("Autor: %s", quadrinho.autor);
	printf("Número da edição: %d", quadrinho.n_edicao);
	printf("\nAno de publicação: %d", quadrinho.ano_publicacao);
	printf("\nIdioma: %s", quadrinho.idioma);
}

void Exercicio3() {

	int qtd_quadrinhos, indice_consulta_quadrinho;
	printf("\nQuantos quadrinhos serão cadastrados? ");
	scanf_s("%d", &qtd_quadrinhos);

	std::vector<Quadrinho> colecao;

	for (int i = 0; i < qtd_quadrinhos; i++) {
		colecao.push_back(CadastroQuadrinho());
	}

	printf("\nQual o índice do quadrinho deseja consultar?\n");
	scanf_s("%d", &indice_consulta_quadrinho);

	ConsultaQuadrinho(colecao[indice_consulta_quadrinho], indice_consulta_quadrinho);
}


void Exercicio4() {

	int qtd_primos = 0;

	for (int dividendo = 0; dividendo <= 50; dividendo++) {

		int qtd_divisores = 0;

		for (int divisor = 1; divisor <= dividendo; divisor++) {

			if (dividendo % divisor == 0) {
				qtd_divisores += 1;
			}
		}

		if (qtd_divisores == 2) {
			qtd_primos += 1;
		}
	}
	printf("\n\nHá %d números primos entre 0 e 50\n\n", qtd_primos);
}


int main() {

	setlocale(LC_ALL, "pt_BR.UTF-8");

	int exercicio_selecionado;

	printf("\nSelecione o exercício");
	printf("\n1. Calculadora");
	printf("\n2. Cadastro de cachorros");
	printf("\n3. Cadastro e consulta de quadrinhos em uma coleção");
	printf("\n4. Contagem de números primos entre 0 e 50\n");
	scanf_s("%d", &exercicio_selecionado);

	switch (exercicio_selecionado) {
	case 1:
		Exercicio1();
		break;
	case 2:
		Exercicio2();
		break;
	case 3:
		Exercicio3();
		break;
	case 4:
		Exercicio4();
		break;
	default:
		printf("\nEste exercício não existe");
		break;
	}

}
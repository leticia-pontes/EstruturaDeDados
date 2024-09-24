#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;


typedef struct {
	int matricula;
	char nome[50];
	int idade;
	float media;
} Aluno;

Aluno CadastroAlunos(int contador_alunos) {
	Aluno aluno;
	char resetar_char;

	printf("\nMatrícula do aluno %d: ", contador_alunos + 1);
	scanf_s("%d", &aluno.matricula);

	printf("Nome do aluno %d: ", contador_alunos + 1);
	scanf_s("%c", &resetar_char, 1);
	fgets(aluno.nome, sizeof(aluno.nome), stdin);

	printf("Idade do aluno %d: ", contador_alunos + 1);
	scanf_s("%d", &aluno.idade);

	printf("Média do aluno %d: ", contador_alunos + 1);
	scanf_s("%f", &aluno.media);

	return aluno;
}

void InformacoesAlunos(int contador_alunos, Aluno aluno) {
	printf("\n\nMatrícula do aluno %d: %d", contador_alunos + 1, aluno.matricula);
	printf("\nNome do aluno %d: %s", contador_alunos + 1, aluno.nome);
	printf("Idade do aluno %d: %d", contador_alunos + 1, aluno.idade);
	printf("\nMédia do aluno %d: %.2f", contador_alunos + 1, aluno.media);
}

void Exercicio1() {
	Aluno grupoAlunos[5];

	for (int contador_alunos = 0; contador_alunos < 5; contador_alunos++) {
		grupoAlunos[contador_alunos] = CadastroAlunos(contador_alunos);
	}

	printf("\n\nMostrando as informações dos alunos");
	for (int aluno_exibido = 0; aluno_exibido < 5; aluno_exibido++) {
		InformacoesAlunos(aluno_exibido, grupoAlunos[aluno_exibido]);
	}
	printf("\n");
}


typedef struct {
	int numero_conta;
	char nome_titular[50];
	float saldo;
	int senha;
} Conta;

float DepositarDinheiroConta(Conta conta, float valor_dinheiro) {
	return conta.saldo + valor_dinheiro;
}

bool SacarDinheiroConta(Conta conta, float valor_dinheiro) {
	if (conta.saldo > valor_dinheiro) {
		return true;
	}
	else { printf("\nVocê é pobre\n"); return false; }
}

bool ValidadorSenha(Conta conta, int senha_inserida) { return conta.senha == senha_inserida; }

void Exercicio2() {

	Conta conta = {123456, "Caio Coneglian", 367.50, 9090};
	int acao_escolhida, senha_inserida;
	bool senha_correta = false;
	float valor_dinheiro;

	while (senha_correta == false) {
		printf("\nDigite a senha para entrar no sistema: ");
		scanf_s("%d", &senha_inserida);
		senha_correta = ValidadorSenha(conta, senha_inserida);
	}
	
	if (conta.senha == senha_inserida) {

		while (true) {

			printf("\nAções\n");
			printf("\n1. Depositar dinheiro");
			printf("\n2. Consultar saldo");
			printf("\n3. Sacar dinheiro");
			printf("\nSair\n");
			scanf_s("%d", &acao_escolhida);

			if (acao_escolhida > 3 || acao_escolhida < 1) { goto sair_do_sistema; }
			else if (acao_escolhida == 2) {
				printf("\nSeu saldo: R$ %.2f\n", conta.saldo);
			}
			else {
				printf("\nInsira a quantia:\n");
				scanf_s("%f", &valor_dinheiro);

				if (acao_escolhida == 1) {
					conta.saldo = DepositarDinheiroConta(conta, valor_dinheiro);
					printf("\nVocê depositou R$ %.2f em sua conta\n", valor_dinheiro);
				} 
				else if (acao_escolhida == 3) {
					bool transacao_aceita = SacarDinheiroConta(conta, valor_dinheiro);

					if (transacao_aceita) {
						printf("\nVocê sacou R$ %.2f\n", valor_dinheiro);
						conta.saldo -= valor_dinheiro;
					}
				}
			}	
		}
		sair_do_sistema:;
	}
}


typedef struct {
	char nome[50];
	char numero_telefone[15];
	char email[50];
} Contato;

Contato CadastroContatos() {
	Contato contato;
	char resetar_string;

	printf("\nNome: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(contato.nome, sizeof(contato.nome), stdin);

	printf("Número de telefone: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(contato.numero_telefone, sizeof(contato.numero_telefone), stdin);

	printf("E-mail: ");
	scanf_s("%s", &resetar_string, 0);
	fgets(contato.email, sizeof(contato.email), stdin);

	return contato;
}

void ExibeContato(Contato contato) {
	printf("Nome: %s", contato.nome);
	printf("Telefone: %s", contato.numero_telefone);
	printf("E-mail: %s\n", contato.email);
}

bool ProcurarContato(char nome_contato[50], char pesquisa_nome_contato[50]) {

	return strstr(nome_contato, pesquisa_nome_contato);
}

void Exercicio3() {
	std::vector<Contato> listaContatos;
	int qtd_contatos = 0, acao_escolhida;
	char resetar_string, nome_procurado[50];
	bool contato_encontrado;

	while (qtd_contatos <= 0 || qtd_contatos > 11) {
		printf("\nCriar quantos contatos?  ");
		scanf_s("%d", &qtd_contatos);
	}
	
	printf("\nCadastro de contatos\n");
	for (int cadastrando_contato = 0; cadastrando_contato < qtd_contatos; cadastrando_contato++) {
		listaContatos.push_back(CadastroContatos());
	}

	while (true) {
		printf("\n\nAções\n");
		printf("\n1. Exibir todos os contatos");
		printf("\n2. Procurar contato (por nome)");
		printf("\nSair\n");
		scanf_s("%d", &acao_escolhida);

		if (acao_escolhida <= 0 || acao_escolhida > 2) {
			goto sair_do_menu;
		}
		else if (acao_escolhida == 1) {
			printf("\nLista de Contatos\n\n");
			for (int item_contato = 0; item_contato < qtd_contatos; item_contato++) {
				ExibeContato(listaContatos[item_contato]);
			}
		}
		else if (acao_escolhida == 2) {
			printf("\nBuscar por nome: ");
			scanf_s("%s", nome_procurado, 50);

			for (int c = 0; c < sizeof(nome_procurado); c++) {
				nome_procurado[c] = toupper(nome_procurado[c]);
			}

			printf("\nResultados\n\n");
			for (int item_contato = 0; item_contato < qtd_contatos; item_contato++) {

				char nome[50];
				strcpy_s(nome, listaContatos[item_contato].nome);

				for (int c = 0; c < sizeof(listaContatos[0].nome); c++) {
					nome[c] = toupper(nome[c]);
				}

				contato_encontrado = ProcurarContato(nome, nome_procurado);
				if (contato_encontrado) {
					ExibeContato(listaContatos[item_contato]);
				}
			}
		}
	}
	sair_do_menu:;
}


int main() {
	
	setlocale(LC_ALL, "pt_BR.UTF-8");

	int exercicio_selecionado;
	
	while (true) {
		printf("\n\nSelecione o exercício");
		printf("\n1. Struct de Alunos");
		printf("\n2. Struct de Contas");
		printf("\n3. Struct de Contatos");
		printf("\nSair\n");
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
			default:
				goto termina_loop_main;
		}
	}
	termina_loop_main:;

	return 0;
}
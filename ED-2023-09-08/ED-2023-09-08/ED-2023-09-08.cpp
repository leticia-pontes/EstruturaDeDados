#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <vector>


void Exercicio1() {

    printf("\nExercício 1 - Sequência de Fibonacci (20 primeiros números)\n");

    int fibonacci[20], a = 1, b = 1, c;

    for (int indice = 0; indice < 20; indice++) {
        if (indice == 0 || indice == 1) {
            fibonacci[indice] = 1;
        }
        else {
            c = a + b;
            fibonacci[indice] = c;
            a = b;
            b = c;
        }
        
        printf("%d\n", fibonacci[indice]);
    }
}


void Exercicio2() {

    printf("\nExercício 2 - Anos bissextos (ano 1 até hoje)\n");

    int ano_atual, qtd_anos_bissextos = 0;

    printf("\nInforme o ano atual: ");
    scanf_s("%d", &ano_atual);

    for (int contador_anos = 1; contador_anos <= ano_atual; contador_anos++) {
        if (contador_anos % 400 == 0 || contador_anos % 4 == 0 && contador_anos % 100 != 0) {
            qtd_anos_bissextos += 1;
        }
    }

    printf("\nHá %d anos bissextos entre os anos 1 e %d\n\n", qtd_anos_bissextos, ano_atual);
}


void Exercicio3() {

    printf("\nExercício 3 - Empresa de cosméticos (pesquisa)");

    const int amostras = 5;
    char lista_formulario_sexo[amostras], lista_formulario_aprovacao[amostras];
    char resetar_char;
    int indice_pessoa;

    for (indice_pessoa = 0; indice_pessoa < amostras; indice_pessoa++) {
        printf("\nSexo (M/F): ");
        scanf_s("%c", &resetar_char, 1);
        lista_formulario_sexo[indice_pessoa] = getchar();

        printf("\nVocê gostou do produto? (S/N) ");
        scanf_s("%c", &resetar_char, 1);
        lista_formulario_aprovacao[indice_pessoa] = getchar();
    }

    int n_homens_aprovado = 0, n_mulheres_aprovado = 0, n_homens_reprovado = 0, n_mulheres_reprovado = 0;

    for (indice_pessoa = 0; indice_pessoa < amostras; indice_pessoa++) {
        if (toupper(lista_formulario_aprovacao[indice_pessoa]) == 'S') {
            if (toupper(lista_formulario_sexo[indice_pessoa]) == 'M') {
                n_homens_aprovado += 1;
            }
            else {
                n_mulheres_aprovado += 1;
            }
        }
        else {
            if (toupper(lista_formulario_sexo[indice_pessoa]) == 'M') {
                n_homens_reprovado += 1;
            }
            else {
                n_mulheres_reprovado += 1;
            }
        }
        
    }

    printf("\n\nHomens\nGostaram: %d\nNão gostaram: %d", n_homens_aprovado, n_homens_reprovado);
    printf("\n\nMulheres\nGostaram: %d\nNão gostaram: %d", n_mulheres_aprovado, n_mulheres_reprovado);

    if (n_homens_aprovado + n_mulheres_aprovado > n_homens_reprovado + n_mulheres_reprovado) {
        printf("\n\nA empresa DEVE lançar o produto");
    }
    else {
        printf("\n\nA empresa NÃO DEVE lançar o produto");
    }
}


void Exercicio4() {

    printf("\nExercício 4 - 100 primeiros valores de uma sequência\n\n");

    int termo_atual, termo_anterior = 1;

    for (int indice = 0; indice < 100; indice++) {
        termo_atual = termo_anterior + indice;
        printf("%d ", termo_atual);

        termo_anterior = termo_atual;
    }
    printf("\n");
}


void main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int exercicio_selecionado;

    printf("\nSelecione o exercício");
    printf("\n1. Sequência de Fibonacci (20 primeiros números)");
    printf("\n2. Anos bissextos (ano 1 até hoje)");
    printf("\n3. Empresa de cosméticos (pesquisa)");
    printf("\n4. 100 primeiros valores de uma sequência\n");
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
            break;
    }
}
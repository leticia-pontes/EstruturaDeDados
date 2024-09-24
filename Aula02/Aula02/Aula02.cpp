#include <stdio.h>

/*
typedef struct { // Cria uma classe
    int numero;
    char nome[50];
    char tipo[20];
} Pokemon;
    Pokemon p;

    printf("Digite o numero do pokemon: ");
    scanf_s("%d", &p.numero);

    printf("Digite o nome do pokemon: ");
    scanf_s("%s", p.nome, sizeof(p.nome));

    printf("Digite o tipo do pokemon: ");
    scanf_s("%s", p.tipo, sizeof(p.tipo));

    printf("\nNumero: %d\nNome: %s\nTipo: %s\n", p.numero, p.nome, p.tipo);

    // Verifica se as strings sao iguais
    if (strcmp(p.nome, p.tipo) == 0) {
        printf("EH igual");
    }
    else {
        printf("EH diferente");
    }
*/

int main() {

    /*
    int a[6];

    for (int i = 0; i < 6; i++) {
        printf("Digite o valor %d: ", i);
        scanf_s("%d", &a[i]);
    }
    */

    int a[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o valor da posicao [%d] [%d]: ", i+1, j+1);
            scanf_s("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("\nValor da posicao [%d] [%d]: %d", i+1, j+1, a[i][j]);
        }
    }
}
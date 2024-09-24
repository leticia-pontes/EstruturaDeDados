#include <stdio.h>


void Ex1 () {
    float notas[5];
    float* ponteiro;

    ponteiro = notas;

    for (int n = 0; n < 5; n++) {
        printf("\nNota %d: ", n + 1);
        scanf_s("%f", (ponteiro + n));
    }
    
    float media = 0;

    for (int n = 0; n < 5; n++) {
        media += *(ponteiro + n);
    }

    media /= 5;

    printf("\nA media eh %.2f\n",  media);
}


void Ex2() {
    int vetor[5] = { 10, 20, 30, 40, 50 };
    int* ponteiro;

    ponteiro = vetor;
    
    printf("\n\nVetor normal\n\n");
    for (int n = 0; n < 5; n++) {
        printf("%d\n", *(ponteiro + n));
    }

    printf("\nVetor Invertido\n\n");
    for (int n = 0; n <= 2; n++) {
        int temp = *(ponteiro + n);
        *(ponteiro + n) = *(ponteiro + 4 - n);
        *(ponteiro + 4 - n) = temp;
    }

    for (int n = 0; n < 5; n++) {
        printf("%d\n", *(ponteiro + n));
    }


    /*
        for (int n = 5; n > 0; --n) {
            printf("%d\n", *(ponteiro + n));
        }
    */

    /*
        for (ponteiro = vetor+4; ponteiro >= vetor; ponteiro--) {
            printf("%d\n", *(ponteiro));
        }
    */
    
}


int main() {
    Ex1();
    Ex2();
}
#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;


typedef struct Pessoa {
    int id;
    Pessoa* proxima;
} Pessoa;

typedef struct {
    Pessoa* primeira;
} Fila;


Fila* IniciarFila() {
    Fila* fila = (Fila*)calloc(1, sizeof(Fila));
    fila->primeira = NULL;
    return fila;
}

void InserirIDInicio(Fila* fila, int id) {
    Pessoa* new_pessoa = (Pessoa*)calloc(1, sizeof(Pessoa));

    new_pessoa->id = id;

    new_pessoa->proxima = fila->primeira;
    fila->primeira = new_pessoa;
}

void RemoverIDInicio(Fila* fila) {
    Pessoa* auxiliar = fila->primeira;

    if (auxiliar == NULL) {
        cout << "\nFila vazia!" << endl;
    }
    else {
        fila->primeira = auxiliar->proxima;
        free(auxiliar);
    }
}

void RemoverIDFinal(Fila* fila) {
    if (fila->primeira == NULL) {
        cout << "\nFila vazia" << endl;
    }
    else {
        Pessoa* auxiliar = fila->primeira;
        
        if (auxiliar->proxima == NULL) {
            fila->primeira = NULL;
            free(auxiliar);
        }
        else {
            while (auxiliar->proxima->proxima != NULL) {
                auxiliar = auxiliar->proxima;
            }
            free(auxiliar->proxima);
            auxiliar->proxima = NULL;
        }
    }
}

void MostrarFila(Fila* fila) {
    Pessoa* auxiliar = fila->primeira;

    while (auxiliar != NULL) {
        cout << auxiliar->id << " -> ";
        auxiliar = auxiliar->proxima;
    }
    cout << "NULL" << endl;
}

// Em ambas as opções (FIFO e LIFO), os nós são inseridos no início

int main()
{
    setlocale(LC_ALL, "pt_BR.utf-8");

    Fila* fila;
    fila = IniciarFila();

    int n_pessoas, id;

    cout << "\nInsira a quantidade de pessoas na fila: ";
    cin >> n_pessoas;
    cout << endl;

    for (int i = 0; i < n_pessoas; i++) {
        cout << "\nID " << i + 1 << ": ";
        cin >> id;
        InserirIDInicio(fila, id);
    }
    
    int remover_n = n_pessoas + 1;
    int fifo_lifo;

    while (remover_n > n_pessoas) {
        cout << "\nQuantas pessoas deseja remover? ";
        cin >> remover_n;
    }

    while (remover_n != 0) {
        cout << endl;
        MostrarFila(fila);

        cout << "\nFIFO ou LIFO? (1 ou 2) ";
        cin >> fifo_lifo;

        if (fifo_lifo == 1 || fifo_lifo == 2) {
            fifo_lifo == 1 ? RemoverIDFinal(fila) : RemoverIDInicio(fila);
            remover_n -= 1;
        }
        else {
            cout << "\nOpção inválida!" << endl;
        }
    }

    cout << endl;
    MostrarFila(fila);
}
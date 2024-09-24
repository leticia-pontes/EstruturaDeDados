#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;


typedef struct Pessoa {
    int id;
    Pessoa* anterior;
    Pessoa* proxima;
} Pessoa;

typedef struct {
    Pessoa* primeira;
    Pessoa* ultima;
} Fila;


Fila* criarFila() {
    Fila* fila = (Fila*)calloc(1, sizeof(Fila));
    fila->primeira = NULL;
    fila->ultima = NULL;
    return fila;
}

void inserirPessoaInicio(Fila* fila, int id) {
    Pessoa* new_pessoa = (Pessoa*)calloc(1, sizeof(Pessoa));
    new_pessoa->id = id;

    new_pessoa->anterior = NULL;
    new_pessoa->proxima = fila->primeira;

    if (fila->ultima == NULL) fila->ultima = new_pessoa;
    else new_pessoa->proxima->anterior = new_pessoa;

    fila->primeira = new_pessoa;
}

void removerNoInicio(Fila* fila) {
    Pessoa* primeira = fila->primeira;

    if (primeira == NULL) cout << "\nLista Vazia!" << endl;

    else if (fila->ultima == primeira) {
        fila->primeira = NULL;
        fila->ultima = NULL;
        free(primeira);
    }

    else {
        fila->primeira = primeira->proxima;
        fila->primeira->anterior = NULL;
        free(primeira->anterior);
    }
}

void removerNoFinal(Fila* fila) {
    Pessoa* ultima = fila->ultima;

    if (ultima == NULL) cout << "\nLista Vazia!" << endl;

    else if (fila->primeira == ultima) {
        fila->primeira = NULL;
        fila->ultima = NULL;
        free(ultima);
    }

    else {
        fila->ultima = ultima->anterior;
        fila->ultima->proxima = NULL;
        free(ultima->proxima);
    }
}

void mostrarFila(Fila* fila) {
    Pessoa* auxiliar = fila->primeira;

    if (auxiliar == NULL) {
        cout << "Lista vazia";
    }
    else {
        while (auxiliar != NULL) {
            cout << auxiliar->id << " -> ";
            auxiliar = auxiliar->proxima;
        }
        cout << "NULL" << endl;
    }
}


int main()
{
    setlocale(LC_ALL, "pt_BR.utf8");

    Fila* fila;
    fila = criarFila();

    int n_pessoas, id;

    cout << "Insira a quantidade de pessoas na fila: ";
    cin >> n_pessoas;
    cout << endl;

    for (int i = 0; i < n_pessoas; i++) {
        cout << "Id " << i + 1 << ": ";
        cin >> id;
        inserirPessoaInicio(fila, id);
    }

    int remover_n = n_pessoas + 1;
    int fifo_lifo;

    while (remover_n > n_pessoas) {
        cout << "\nQuantas pessoas deseja remover? ";
        cin >> remover_n;
    }

    while (remover_n != 0) {
        cout << endl;
        mostrarFila(fila);

        cout << "\nFIFO ou LIFO? (1 ou 2) ";
        cin >> fifo_lifo;

        if (fifo_lifo)
        if (fifo_lifo == 1 || fifo_lifo == 2) {
            fifo_lifo == 1 ? removerNoFinal(fila) : removerNoInicio(fila);
            remover_n -= 1;
        }
        else {
            cout << "\nOpção inválida!" << endl;
        }
    }

    cout << endl;
    mostrarFila(fila);
}
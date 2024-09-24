/*
    Pilha: LIFO
        - empilhar (push)
        - desempilhar (pop)
        - pilha vazia?
        - tamanho
        - get last in

        * avaliação de expressões matemáticas (parêntese mais interno para o mais externo)
        * REACT USA PILHA -> ctrl + z

    Fila: FIFO
        - inserir
        - remover
        
        * gerenciamento de tarefas
        * impressão de documentos
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


typedef struct {
    int topo;
    int tamanho;
    int* valores;
} Pilha;

Pilha* CriarPilha(int tamanho) {
    Pilha* p = (Pilha*)calloc(1, sizeof(Pilha));
    p->tamanho = tamanho;
    p->topo = -1;
    p->valores = (int*)calloc(tamanho, sizeof(int));
    return p;
}

void PushInPilha(Pilha* p, int valor) {
    if (p->topo == p->tamanho - 1) {
        cout << "\nERRO - Pilha Cheia" << endl;
    }
    else {
        p->topo++;
        *(p->valores + p->topo) = valor;
    }
}

int PopOutPilha(Pilha* p) {
    if (p->topo == -1) {
        cout << "\nERRO - Pilha Vazia" << endl;
        return 0;
    }
    else {
        int valor_removido = *(p->valores + p->topo);
        p->topo--;
        return valor_removido;
    }
}

void MostrarPilha(Pilha* p) {
    if (p->topo == -1) {
        cout << "Pilha vazia!" << endl;
    }
    else {
        cout << "| ";
        for (int it = 0; it <= p->topo; it++) {
            cout << setw(3) << it << " | ";
        }
        cout << endl;

        cout << "| ";
        for (int it = 0; it <= p->topo; it++) {
            cout << setw(3) << *(p->valores + it) << " | ";
        }
        cout << endl;
    }
}

int EstaVazia(Pilha* p) {
    return p->topo == -1;
}

int EstaCheia(Pilha* p) {
    return p->topo == p->tamanho - 1;
}










typedef struct {
    int tamanho, capacidade, primeiro, ultimo;
    int* valores;
} Fila;

Fila* CriarFila(int capacidade) {
    Fila* f = (Fila*)calloc(1, sizeof(Fila));
    f->capacidade = capacidade;
    f->tamanho = 0;
    f->primeiro = 0;
    f->ultimo = capacidade - 1;
    f->valores = (int*)calloc(capacidade, sizeof(int));
    return f;
}

void Enfileirar(Fila* f, int valor) {
    if (f->tamanho == f->capacidade) {
        cout << "\nERRO - Fila cheia!" << endl;
    }   
    else {
        f->ultimo = (f->ultimo + 1) % f->capacidade;
        *(f->valores + f->ultimo) = valor;
        f->tamanho++;
    }
}

int Desenfileirar(Fila* f) {
    if (f->tamanho == 0) {
        cout << "ERRO - Fila vazia!" << endl;
    }
    else {
        int valor_removido = *(f->valores + f->primeiro);
        f->primeiro = (f->primeiro + 1) % f->capacidade;
        f->tamanho--;
        return valor_removido;
    }
}

void MostrarFila(Fila* f) {
    int primeiro = f->primeiro;

    for (int it = 0; it < f->tamanho; it++) {
        cout << *(f->valores + primeiro) << " -> ";
        primeiro = (primeiro + 1) % f->capacidade;
    }
    cout << "NULL" << endl;
}

int EstaCheia(Fila* f) {
    return (f->tamanho == f->capacidade);
}

int EstaVazia(Fila* f) {
    return (f->tamanho == 0);
}



int main()
{
    //int tamanho_pilha;

    //cout << "Tamanho da pilha: ";
    //cin >> tamanho_pilha;
    //Pilha* pilha = CriarPilha(tamanho_pilha);
    //cout << endl;


    //int valor_pilha;

    //for (int it = 0; it < pilha->tamanho; it++) {
    //    cout << "Valor " << it + 1 << ": ";
    //    cin >> valor_pilha;
    //    PushInPilha(pilha, valor_pilha);
    //}

    //cout << endl;
    //MostrarPilha(pilha);

    //int qtd_remover;

    //cout << "\nQuantos deseja remover?  ";
    //cin >> qtd_remover;
    //cout << endl;

    //int valorRemovido;

    //for (int it = 0; it < qtd_remover; it++) {
    //    valorRemovido = PopOutPilha(pilha);
    //    cout << valorRemovido << endl;
    //}

    //cout << endl;
    //MostrarPilha(pilha);

    //cout << endl << "A pilha esta vazia?";
    //int estaVazia = EstaVazia(pilha);
    //cout << (estaVazia == 1 ? "Sim" : "Nao");

    //cout << endl << "A pilha esta cheia?";
    //int estaCheia = EstaCheia(pilha);
    //cout << (estaCheia == 1 ? "Sim" : "Nao");

    //cout << endl;











    

    int capacidade_fila;

    cout << "\nDigite a capacidade da fila: ";
    cin >> capacidade_fila;

    Fila* fila = CriarFila(capacidade_fila);
    cout << endl;

    int valor_fila;

    for (int i = 0; i < fila->capacidade; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> valor_fila;

        Enfileirar(fila, valor_fila);
    }

    cout << endl;
    MostrarFila(fila);

    int qtd_remover_fila;

    cout << "\nQuantos deseja remover?  ";
    cin >> qtd_remover_fila;
    cout << endl;

    int valorRemovidoFila;

    for (int it = 0; it < qtd_remover_fila; it++) {
        valorRemovidoFila = Desenfileirar(fila);
        cout << valorRemovidoFila << endl;
    }

    cout << endl;
    MostrarFila(fila);

    return 0;
}
#include <iostream>

using namespace std;


class Retangulo {
public:
	float largura;
	float comprimento;
};


int main() {

	Retangulo a;
	a = { 5, 25 };

	cout << "Retangulo a" << endl;
	cout << "Largura: " << a.largura << endl;
	cout << "Comprimento: " << a.comprimento << endl;

	Retangulo b{ 10, 15 };

	cout << "\nRetangulo b" << endl;
	cout << "Largura: " << b.largura << endl;
	cout << "Comprimento: " << b.comprimento << endl;

	return 0;
}
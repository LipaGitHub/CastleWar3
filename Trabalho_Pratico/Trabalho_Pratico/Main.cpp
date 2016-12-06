#include <iostream>
#include"Planicie.h"
using namespace std;

int main() {
	int linha, coluna;
	cout << "Bem Vindo ao Castle War!!!" << endl;
	cout << "Entre com as dimenoes da planicie" << endl;
	cin >> linha >> coluna;
	planicie jogo(linha, coluna);
	cout << jogo;
	return 0;
}
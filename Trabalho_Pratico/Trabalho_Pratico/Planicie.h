#pragma once
#include "Personagem.h"
#include <sstream>
class planicie {
	//existem colonias, seres e edificios
	personagem* ** mapa; // 1º *-> ponteiro para personagem  2º *-> 1D 3º *-> 2D
	int linha, coluna;
public:
	/*planicie(int l, int c) {
		this->linha = l;
		this->coluna = c;
		mapa = new personagem **[l] ;
		for (int i = 0; i < l; i++) {
			mapa[i] = new personagem *[c];
		}
		for (int i = 0; i < l; i++)
			for (int j = 0; j < c; j++)
				mapa[i][j] = NULL;
	}
	string toString()const {
		ostringstream os;
		for (int i = 0; i < linha; i++) {
			for (int j = 0; j < coluna; j++)
				cout << "*";
			cout << "\n";
		}
		return os.str();
	}
};
ostream &operator <<(ostream &o, const planicie &p) {
	o << p.toString();
	return o;
}
*/
};
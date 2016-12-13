#pragma once
#include "Personagem.h"
#include "Perfil.h"
#include <sstream>

using namespace std;
class Planicie {
	vector<Perfil *> perfis;
	vector<Perfil *>::iterator iter;
	//existem colonias, seres e edificios
	Personagem* ** mapa; // 1º *-> ponteiro para personagem  2º *-> 1D 3º *-> 2D
	const int linha, coluna;
	int moedas;
public:
	Planicie(const int l,const int c, int m = 0);
	int getLinha();
	int getColuna();
	vector<Perfil *> retornaPerfis();
	void criaMapa();
	string toString()const;
	void criaPerfil(char letra);
	void removePerfil(char letra);
	Perfil * procuraPerfil(char letra) {
		for (iter = perfis.begin(); iter != perfis.end(); iter++) {
			if ((*iter)->getIDPerfil() == letra) {
				return *iter;
			}
		}
		return nullptr;
	}
	
	void setMoedas(int n);
};

/*ostream &operator <<(ostream &o, const Planicie &p) {
	o << p.toString();
	return o;
}*/
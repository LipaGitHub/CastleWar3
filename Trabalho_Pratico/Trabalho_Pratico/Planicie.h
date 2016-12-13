#pragma once
#include "Personagem.h"
#include "Perfil.h"
#include <sstream>
class Planicie {
	vector<Perfil *> perfis;
	vector<Perfil *>::iterator iter;
	//existem colonias, seres e edificios
	Personagem* ** mapa; // 1º *-> ponteiro para personagem  2º *-> 1D 3º *-> 2D
	const int linha, coluna;
public:
	Planicie(const int l, const int c) :linha(l), coluna(c);
	int getLinha();
	int getColuna();
	vector<Perfil *> retornaPerfis();
	void criaMapa();
	string toString()const;
	void criaPerfil(char letra);
	void removePerfil(char letra);
	Perfil * procuraPerfil(char letra);
};

/*ostream &operator <<(ostream &o, const Planicie &p) {
	o << p.toString();
	return o;
}*/
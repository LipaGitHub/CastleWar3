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
	Planicie( const int l, const int c):linha(l),coluna(c) {
		this->perfis = vector<Perfil *>();
		criaMapa();
	}

	int getLinha() {
		return linha;
	}

	int getColuna() {
		return coluna;
	}

	vector<Perfil *> retornaPerfis() {
		return perfis;
	}

	void criaMapa() {
		mapa = new Personagem **[getLinha()];
		for (int i = 0; i < getLinha(); i++) {
			mapa[i] = new Personagem *[getColuna()];
		}
		for (int i = 0; i < getLinha(); i++)
			for (int j = 0; j < getColuna(); j++)
				mapa[i][j] = NULL;

		for (int i = 0; i < getLinha(); i++) {
			for (int j = 0; j < getColuna(); j++)
				cout << '*';
			cout << "\n";
		}
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

	void criaPerfil(char letra) {
		cout << "oi";
		//Perfil p(letra);
		perfis.push_back(new Perfil(letra));
		cout << "oi2";
	}

	void removePerfil(char letra) {
		for (iter = perfis.begin(); iter != perfis.end(); iter++) {
			if ((*iter)->getIDPerfil() == letra) {
				iter = perfis.erase(iter);
				break;
			}
		}
	}
	
	Perfil * procuraPerfil(char letra) {
		for (iter = perfis.begin(); iter != perfis.end(); iter++) {
			if ((*iter)->getIDPerfil() == letra) {
				return *iter;
			}
		}
		return nullptr;
	}
};

/*ostream &operator <<(ostream &o, const Planicie &p) {
	o << p.toString();
	return o;
}*/
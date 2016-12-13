#pragma once
#include "Personagem.h"
#include "Perfil.h"
#include "Colonia.h"
#include <sstream>
class Planicie {
	vector<Perfil *> perfis;
	vector<Perfil *>::iterator iter;
	vector<Colonia *> colonias;
	//existem colonias, seres e edificios
	Personagem* ** mapa; // 1� *-> ponteiro para personagem  2� *-> 1D 3� *-> 2D
	const int linha, coluna;
	int moedas,oponentes;
public:
	Planicie( const int l, const int c, int m=0, int o=1):linha(l),coluna(c),moedas(m), oponentes(o) {
		//this->perfis = vector<Perfil *>();
		criaMapa();
	}

	int getLinha() {
		return linha;
	}

	int getColuna() {
		return coluna;
	}
	void setMoedas(int m){
		this->moedas = m;
	}
	void setOponentes(int opo) {
		this->oponentes = opo;
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
		perfis.push_back(new Perfil(letra));
	}

	void removePerfil(char letra) {
		 perfis.erase(iter);
	
	}
	void criaColonia(int op) {
		int valor = op + 1;
		for (int i = 0, char abc='a'; i < valor; i++,abc++)
			colonias.push_back(new Colonia(abc));
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
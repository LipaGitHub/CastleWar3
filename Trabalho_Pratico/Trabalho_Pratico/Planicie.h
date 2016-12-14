#pragma once
#ifndef PLANICIE_H
#define PLANICIE_H
#include "Personagem.h"
#include "Perfil.h"
#include "Colonia.h"
#include <sstream>

class Planicie {
	vector<Perfil *> perfis;
	vector<Perfil *>::iterator iter;
	vector<Colonia *> colonias;
	vector<Colonia *>::iterator iter2;
	//existem colonias, seres e edificios
	Personagem* ** mapa; // 1º *-> ponteiro para personagem  2º *-> 1D 3º *-> 2D
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
		Colonia * colonia;
		char abc = 'a';
		
		int valor = op + 1;
		for (int i = 0; i < valor; i++, abc++) {
			int l = rand() % getLinha();
			int c = rand() % getColuna();
			colonias.push_back(new Colonia(abc));
			posicionaCastle(colonias[i]->getCastelo(), l, c);
			//posicionaCastle((colonias->getCastelo()), l, c);
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
	void procuraColonia(char col, int l,int c) { //Talvez para outras utilizãções
		Colonia * colonia;
		for (iter2 = colonias.begin(); iter2 != colonias.end(); iter2++) {
			if ((*iter2)->getId_colonia() == col) {
				posicionaCastle((colonia->getCastelo()), l, c);
			}
		}
	}
	
	void posicionaCastle(Personagem* cas, int l, int c)  { //ver o que se pode generalizar
		if(mapa[l][c]==NULL)
			mapa[l][c] = cas;
	}
	void imprimeMapa() {
		//Colonia * colonia;
		for (int i = 0; i < getLinha(); i++) {
			for (int j = 0; j < getColuna(); j++) {
				if (mapa[i][j] != NULL)

					cout << mapa[i][j]->getID();
				else
					cout << "X";
			}
			cout << "\n";
		}
	}
	
};

/*ostream &operator <<(ostream &o, const Planicie &p) {
	o << p.toString();
	return o;
}*/

#endif
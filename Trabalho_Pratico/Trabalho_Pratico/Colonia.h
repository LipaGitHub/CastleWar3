#pragma once

#include <vector>
#include "Personagem.h"
#include "Edificios.h"
#include "Planicie.h"
#include "Seres.h"
#include "Perfil.h"
class Perfil;
class Colonia {
	//Contem um conjunto de seres e edificios
	//Tem uma Letra que a representa
	//Economia de moedas
	char id_colonia;
	vector <Personagem*> eq_edificios;
	vector <Personagem*> eq_seres;
	Castelo * castle;
	Personagem *ser;
	int cor;

public:
	Colonia(char id) {
		this->id_colonia = id;
		this->cor = rand() % 16; //Numero da cor entre 0 e 15, aproveita-se o Consolas.h
		criaCastelo();
	}

	void criaCastelo() {
		castle = new Castelo();
		eq_edificios.push_back(castle);
	}

	char getId_colonia() {
		return id_colonia;
	}

	Personagem* getCastelo() {
		return castle;
	}

	Personagem* getEdificio(){

	}

	Personagem* getSer() {
		ser = new Seres();
		return ser;
	}

	int getCor() {
		return cor;
	}

	void inserirSeres(int n, Perfil *p) { //p->getCaracteristcas();
		for (int i = 0; i < n;i++){	
			eq_seres.push_back(getSer());
		}
	}
};
#pragma once

#include <vector>
#include "Personagem.h"
#include "Edificios.h"
#include "Planicie.h"

class Colonia {
	//Contem um conjunto de seres e edificios
	//Tem uma Letra que a representa
	//Economia de moedas
	char id_colonia;
	vector <Personagem*> eq_edificios;
	vector <Personagem*> eq_seres;
	Castelo * castle;
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

	}

	int getCor() {
		return cor;
	}
};
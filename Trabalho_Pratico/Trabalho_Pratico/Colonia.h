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

public:
	Colonia(char id) {
		this->id_colonia = id;
		criaCastelo();
	}

	void criaCastelo() {
		castle = new Castelo();

		
	}
	char getId_colonia() {
		return id_colonia;
	}

	Personagem* getCastelo() {
		return castle;
	}
};
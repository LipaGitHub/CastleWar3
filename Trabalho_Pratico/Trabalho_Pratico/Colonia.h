#pragma once
#include <vector>
#include "Personagem.h"

class Colonia {
	//Contem um conjunto de seres e edificios
	//Tem uma Letra que a representa
	//Economia de moedas
	char id_colonia;
	vector <Personagem*> equipa;
public:
	Colonia(char id) {
		this->id_colonia = id;
		this->equipa = vector<Personagem*>();
	}

};
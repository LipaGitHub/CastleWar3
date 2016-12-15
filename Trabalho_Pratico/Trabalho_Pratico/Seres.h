#pragma once
#include "Personagem.h"
using namespace std;

class Seres: public Personagem{

	int forca, velocidade, ataque;
	//Possuem caracteristicas
	//Custo Somatorio das caracteristicas
	//Representados pela letra do perfil e cor da colonia
public:
	Seres() {
		this->forca = 0;
		this->velocidade = 0;
		this->ataque = 0;
	}

};

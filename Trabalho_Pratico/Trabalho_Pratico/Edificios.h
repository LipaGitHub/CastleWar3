#pragma once
#ifndef EDIFICIOS_H
#define EDIFICIOS_H

#include "Personagem.h"

#include <sstream>

using namespace std;

class Colonia;

class Edificio: public Personagem{
	//tem indicador
	//Representados pela letra do perfil e cor da colonia
	Colonia* id_colonia;
	string nome;
public:
	Edificio(string n, char sigla, int c, int s, int d, int x, int y);

	/*char getIdEdificio() { //Pode vir a ser necessario mas por enquanto nao
		return id_e;
	}*/

};

class Castelo: public Edificio{

public:
	Castelo(int x, int y);
};

class Quinta :public Edificio {
public:
	Quinta(int x, int y);
};

class Torre : public Edificio {
public:
	Torre(int x, int y); 
};

#endif
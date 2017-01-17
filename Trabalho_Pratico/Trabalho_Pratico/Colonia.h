#pragma once
#ifndef COLONIA_H
#define COLONIA_H

#include <vector>
#include "Personagem.h"
#include "Edificios.h"
<<<<<<< HEAD

=======
#include "Planicie.h"
#include "Seres.h"
#include "Perfil.h"
#include "Caracteristica.h"

class Perfil;

class Colonia {
	//Contem um conjunto de seres e edificios
	//Tem uma Letra que a representa
	//Economia de moedas
	char id_colonia;
	vector <Personagem*> eq_edificios;
	vector <Personagem*> eq_seres;

	vector <Caracteristica*>::iterator iter;
	Castelo * castle;
	Personagem *ser;
	int cor;

public:
	Colonia(char id);
	void criaCastelo();
	char getId_colonia();
	Personagem* getCastelo();
	Personagem* getEdificio();
	//Personagem* getSer();
	int getCor();
	void inserirSeres(int n, Perfil *p);
};
#endif
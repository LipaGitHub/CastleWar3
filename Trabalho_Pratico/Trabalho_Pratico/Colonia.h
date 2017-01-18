#pragma once
#ifndef COLONIA_H
#define COLONIA_H

#include <vector>
using namespace std;

class Perfil;
class Personagem;
class Castelo;
class Caracteristica;
class Seres;

class Colonia {
	//Contem um conjunto de seres e edificios
	//Tem uma Letra que a representa
	//Economia de moedas
	char id_colonia;
	vector <Personagem*> eq_edificios;
	vector <Seres*> eq_seres;
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
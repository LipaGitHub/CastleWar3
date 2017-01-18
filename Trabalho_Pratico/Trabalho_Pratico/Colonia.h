
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
	vector <Personagem*> eq_seres;
	Castelo * castle;
	Seres * ser;
	int cor, saldo;

public:
	Colonia(char id, int x);
	void criaCastelo();
	char getId_colonia();
	Personagem* getCastelo();
	Personagem* getEdificio();
	void setSaldo(int x);
	//Personagem* getSer();
	int getCor();
	void inserirSeres(int n, Perfil *p);
};
#endif
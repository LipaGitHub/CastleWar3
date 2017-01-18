
#ifndef SERES_H
#define SERES_H

#include "Caracteristica.h"
#include "Personagem.h"
using namespace std;


class Seres: public Personagem{

	int forca, velocidade, ataque;
	vector<Caracteristica* > s_carac;
	//Possuem caracteristicas
	//Custo Somatorio das caracteristicas
	//Representados pela letra do perfil e cor da colonia
public:
	Seres():Personagem() { }//VER ISTO TEM QUE SER ASSIM
	Seres(int f, int v, int a, vector<Caracteristica*>car);
	void adicionaCaraSeres(Caracteristica *c);
	Seres efeitoCaracteristica(Caracteristica *c);
};
#endif
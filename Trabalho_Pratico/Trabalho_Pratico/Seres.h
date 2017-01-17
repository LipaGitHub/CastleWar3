#pragma once
#include "Personagem.h"
#include "Caracteristica.h"
using namespace std;

class Seres: public Personagem{

	int forca, velocidade, ataque;
	vector<Caracteristica *> s_carac;
	//Possuem caracteristicas
	//Custo Somatorio das caracteristicas
	//Representados pela letra do perfil e cor da colonia
public:
	//Seres() :Personagem(){ VER ISTO TEM QUE SER ASSIM
	Seres();
	void adicionaCaraSeres(Caracteristica *c);

};

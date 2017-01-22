
#ifndef SERES_H
#define SERES_H

#include "Caracteristica.h"
#include "Personagem.h"
#include "Planicie.h"
using namespace std;


class Seres: public Personagem{
	int forca, velocidade, ataque;
	vector<Caracteristica* > s_carac;
	int contador_esp, contador_remedio, castelo;
	char bandeira, perfil;
	//Possuem caracteristicas
	//Custo Somatorio das caracteristicas
	//Representados pela letra do perfil e cor da colonia
public:
	Seres(int x, int y, char perfil);
	Seres(vector<Caracteristica*>car);
	void adicionaCaraSeres(Caracteristica *c);
	//bool verificaCustos(int custo_m, int custo_f, Seres *s);
	Seres efeitoCaracteristicaConfig(Planicie *plan);
	int getForca();
	void setForca(int f);
	vector<Caracteristica* > retornaCarS();
	int getContadorEsp();
	int getContadorRem();
	void resetContadorEsp(int x);
	void setContadorEsp(int x);
	void setContadorRem(int x);
	int getAtaque();
	int getVelocidade();
	void setAtaque(int x);
	void setVelocidade(int x);
	char getBandeira();
	void setBandeira(char x);
	int getDentroCastelo();
	void setDentroCastelo(int x);
	virtual string toString()const {
		ostringstream os;
		os << Personagem::toString();
		os <<  "Forca:" << forca << "\t" << "Velocidade:"<<velocidade <<"\t"<< "Ataque:"<< ataque << "\t"<<
			"Perfil "<< perfil <<endl;
		
		return os.str();
	}
};
#endif
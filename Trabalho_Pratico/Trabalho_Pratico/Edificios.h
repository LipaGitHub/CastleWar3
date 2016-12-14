#pragma once
#include "Personagem.h"
#include <sstream>

using namespace std;

class Colonia;

class Edificio: public Personagem{
	//tem indicador
	//Representados pela letra do perfil e cor da colonia
	Colonia* id_colonia;
	string nome;
	char id_e;
public:
	Edificio(string n, char id_e, int c, int s , int d) : Personagem(id_e,c,s,d){
		this->nome = n;
		this->id_e = nome[0];
	}

	/*char getIdEdificio() { //Pode vir a ser necessario mas por enquanto nao
		return id_e;
	}*/

};

class Castelo: public Edificio{

public:
	Castelo() :Edificio("Castelo",'C',0, 50, 10) {}
};

class Quinta :public Edificio {
public:
	Quinta() :Edificio("Quinta",'Q',30,20,10) {}
};

class Torre : public Edificio {
public:
	Torre() :Edificio("Torre",'T',20,20,10){}
};
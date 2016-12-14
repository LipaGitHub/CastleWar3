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
public:
	Edificio(string n, int c, int s , int d) : Personagem(c,s,d){
		this->nome = n;
		//this->id_edificio = id;
	}
	//Personagem* efeito();
	 virtual char getNome();

};

class Castelo: public Edificio{

public:
	Castelo() :Edificio("Castelo",0, 50, 10) {}
	virtual char getNome(){
		return 'c';
	}
	
};

class Quinta :public Edificio {
public:
	Quinta() :Edificio("Quinta",30,20,10) {}
};

class Torre : public Edificio {
public:
	Torre() :Edificio("Torre",20,20,10){}
};
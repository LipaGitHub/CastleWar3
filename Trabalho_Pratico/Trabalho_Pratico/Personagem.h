#pragma once
#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <iostream>
#include <sstream>

using namespace std;
class Seres;
class Personagem {
	char id_personagem;
	int identificador;
	int saude, defesa, custo;
	int x, y;
public:
	Personagem();
	Personagem(char nome, int c, int s, int d, int x, int y);
	Personagem(char nome, int x, int y);
	int getSaude();
	int getDefesa();
	int getCusto();
	void setCusto(int c);
	void setDefesa(int d);
	void setSaude(int s);
	char getID();
	int getIdentificador();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	Seres * procuraSer(int x);
	virtual string toString()const {
		ostringstream os;
		os << "Ser numero "<< identificador <<"\t"<<"Saude: " << this->saude << " Defesa: " << this->defesa << endl;
		return os.str();
	}
	
};

#endif
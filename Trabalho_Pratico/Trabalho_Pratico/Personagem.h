#pragma once
#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <iostream>

using namespace std;

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
	char getID();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	/*virtual string toString()const {

	}*/
};
#endif
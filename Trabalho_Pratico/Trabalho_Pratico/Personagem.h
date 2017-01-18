#pragma once
#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <iostream>

using namespace std;

class Personagem {
	char id_personagem;
	int identificador;
	int saude, defesa, custo;
public:
	Personagem();
	Personagem(char nome, int c, int s, int d);
	Personagem(char nome);
	int getSaude();
	int getDefesa();
	int getCusto();
	char getID();
	/*virtual string toString()const {

	}*/
};
#endif
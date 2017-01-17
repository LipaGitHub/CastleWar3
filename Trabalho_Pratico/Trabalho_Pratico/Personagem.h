#pragma once
#ifndef PERSONAGEM_H
#define PERSONAGEM_H
using namespace std;

class Personagem {
	char id_personagem;
	int saude, defesa, custo;
public:
	Personagem();
	Personagem(char id, int c, int s, int d);
	int getSaude();
	int getDefesa();
	int getCusto();
	char getID();
};
#endif
#pragma once
#ifndef PLANICIE_H
#define PLANICIE_H

#include "Perfil.h"
#include "Colonia.h"
#include "Personagem.h"
#include <sstream>

class Planicie {
	vector<Perfil *> perfis;
	vector<Perfil *>::iterator iter;
	vector<Colonia *> colonias;
	vector<Colonia *>::iterator iter2;
	//existem colonias, seres e edificios
	Personagem* ** mapa; // 1º *-> ponteiro para personagem  2º *-> 1D 3º *-> 2D
	const int linha, coluna;
	int moedas, oponentes;
public:
	Planicie(const int l, const int c, int m = 0, int o = 1);
	int getLinha();
	int getColuna();
	void setMoedas(int m);
	void setOponentes(int opo);
	vector<Perfil *> retornaPerfis();
	void criaMapa();
	string toString()const;
	void criaPerfil(char letra);
	void removePerfil(char letra);
	void criaColonia(int op);
	Perfil * procuraPerfil(char letra);
	void procuraColonia(char col, int l, int c);
	Colonia * getColonia(char id);
	void posicionaCastle(Personagem* cas, int l, int c);
	void imprimeMapa();
};

#endif
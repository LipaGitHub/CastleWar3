#pragma once
#ifndef PLANICIE_H
#define PLANICIE_H

#include <sstream>
#include "Perfil.h"
#include <iostream>
class Colonia;
class Personagem;
class Seres;
using namespace std;

class Planicie {
	vector<Perfil *> perfis;
	vector<Perfil *>::iterator iter;
	vector<Colonia *> colonias;
	vector<Colonia *>::iterator iter2;
	//existem colonias, seres e edificios
	Personagem* ** mapa; // 1º *-> ponteiro para personagem  2º *-> 1D 3º *-> 2D
	const int linha, coluna;
	int moedas=0, oponentes;
public:
	Planicie(const int l, const int c, int m = 0, int o = 1);
	bool verificaPerfil(char letra);
	int getLinha();
	int getColuna();
	void setMoedas(int m);
	int getMoedas();
	void setOponentes(int opo);
	vector<Perfil *> retornaPerfis();
	vector<Colonia *> retornaColonias();
	void criaMapa();
	string toString()const;
	void criaPerfil(char letra);
	void removePerfil(char letra);
	void criaColonia(int op, int x);
	Perfil * procuraPerfil(char letra);
	void procuraColonia(char col, int l, int c);
	Colonia * getColonia(char id);
	void posicionaPersonagem(Personagem* cas, int l, int c);
	void imprimeMapa();
	void imprimeMapaFoco(int linha, int coluna);
	bool verificaColonia();
	void moedasColonia(int x);
	void movePersonagem(Personagem* per, int l, int c);
	Personagem*** retornaMapa();
	void recolheSer(Personagem* per, Personagem *cas, Colonia *c);
	void ataca(Personagem* per);
	void imprimePerfil(char p);
	void imprimePerfil();
};

#endif
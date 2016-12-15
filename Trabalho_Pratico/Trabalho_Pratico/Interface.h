#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Planicie.h"
#include "Personagem.h"
#include "Config.h"
#include "Perfil.h"
using namespace std;
class Planicie;
class Interface {
	istream * entrada;
	vector <string> comandos;
	Config info;
	Planicie * p;

public:
	Interface();
	void le_comandos(int tipo);
	void menu();
	void perfis();
	void simulacao();
	void inicializa();
	//void inserirSeres(int n, Perfil *p);
	string leFicheiro(int tipo, string nome);
	string interpretaComando(int tipo, string linha);
	bool verificaComando(int tipo, string comando);
	void Mapa();
};


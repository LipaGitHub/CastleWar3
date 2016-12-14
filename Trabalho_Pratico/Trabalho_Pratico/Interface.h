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
	void le_comandos();
	void menu();
	void perfis();
	void inicializa();
	string leFicheiro(string nome);
	string interpretaComando(string linha);
	bool verificaComando(string comando);
	void Mapa();
};


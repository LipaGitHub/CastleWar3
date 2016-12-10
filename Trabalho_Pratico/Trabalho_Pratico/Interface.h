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

class Interface {
	istream * entrada;
	vector <string> comandos;
	Config info;
	Perfil perfil;
public:
	Interface();
	void le_comandos();
	void menu();
	void perfis();
	void inicializa();
	string leFicheiro(string nome);
	string interpretaComando(string linha);
};

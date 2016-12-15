#pragma once
//#include "Seres.h"
//#include "Edificios.h"
using namespace std;

class Personagem {
	char id_personagem;
	int saude, defesa, custo;
public:
	Personagem() {

	}
	Personagem(char id, int c, int s, int d){
		this->id_personagem = id;
		this->custo = c;
		this->defesa = d;
		this->saude = s;
	}

	int getSaude() {
		return saude;
	}

	int getDefesa() {
		return defesa;
	}

	int getCusto() {
		return custo;
	}

	char getID(){
		return id_personagem;
	}
};
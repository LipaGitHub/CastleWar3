#pragma once
//#include "Seres.h"
using namespace std;

class Personagem {
	int saude, defesa, custo;
public:
	//Efeitos das caracteristicas, ex.
	/*void efeito_2(Seres ser) {
		ser.saude++;
	}*/
	Personagem(int c, int s, int d) {
		this->custo = c;
		this->defesa = d;
		this->saude = s;
	}
};
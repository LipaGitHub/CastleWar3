#include "Seres.h"
#include "Caracteristica.h"
#include "Personagem.h"

Seres(int f=10,int v, int a ):Personagem(char id, int custo, int saude, int defesa) {
	this->forca = 10;
	this->velocidade = 0;
	this->ataque = 0;
	this->s_carac = vector<Caracteristica *>();
}

void Seres::adicionaCaraSeres(Caracteristica *c) {
	s_carac.push_back(c);
}

Seres Seres::efeitoCaracteristica(Caracteristica *c) {
	if (c->getIdCaracteristica() == 1) {
		forca = forca + 1;
	}
	else if (c->getIdCaracteristica() == 2) {
		velocidade = velocidade + 2;
	}
	return *this;
}
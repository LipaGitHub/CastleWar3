#include "Seres.h"
#include "Caracteristica.h"
#include "Personagem.h"

Seres::Seres(int f,int v, int a, vector<Caracteristica*> c ):Personagem( 'a',  1,2,3) {
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
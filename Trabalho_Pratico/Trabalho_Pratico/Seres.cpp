#include "Seres.h"
#include "Caracteristica.h"
#include "Personagem.h"

Seres::Seres() {
	this->forca = 10;
	this->velocidade = 0;
	this->ataque = 0;
}

void Seres::adicionaCaraSeres(Caracteristica *c) {
	s_carac.push_back(c);
}
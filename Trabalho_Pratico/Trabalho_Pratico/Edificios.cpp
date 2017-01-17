#include"Edificios.h"

Edificio::Edificio(string n, char id_e, int c, int s, int d) : Personagem(id_e, c, s, d) {
	this->nome = n;
	this->id_e = nome[0];
}

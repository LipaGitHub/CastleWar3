#include"Personagem.h"
Personagem::Personagem() {

}
Personagem::Personagem(char id, int c=0, int s=10, int d=0) {
	this->id_personagem = id;
	this->custo = c;
	this->defesa = d;
	this->saude = s;
}



int Personagem::getSaude() {
	return saude;
}

int Personagem::getDefesa() {
	return defesa;
}

int Personagem::getCusto() {
	return custo;
}

char Personagem::getID() {
	return id_personagem;
}
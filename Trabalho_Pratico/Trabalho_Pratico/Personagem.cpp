#include"Personagem.h"

int ID = 1;

Personagem::Personagem() {

}
Personagem::Personagem(char nome, int c=0, int s=10, int d=0) {
	this->identificador = ID++;
	this->id_personagem = nome;
	this->custo = c;
	this->defesa = d;
	this->saude = s;
}

Personagem::Personagem(char nome) {
	this->identificador = ID++;
	this->id_personagem = nome;
	this->custo = 0;
	this->defesa = 0;
	this->saude = 0;
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

void Personagem::setSaude(int s) {
	saude += s;
}

void Personagem::setDefesa(int d) {
	defesa += d;
}

void Personagem::setCusto(int c) {
	this->custo - c;
}
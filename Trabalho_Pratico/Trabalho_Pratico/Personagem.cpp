#include"Personagem.h"

int ID = 1;

Personagem::Personagem() {

}
Personagem::Personagem(char nome, int c=0, int s=10, int d=0, int x=0, int y=0) {
	this->identificador = ID++;
	this->id_personagem = nome;
	this->custo = c;
	this->defesa = d;
	this->saude = s;
	this->x = x;
	this->y = y;
}

Personagem::Personagem(char nome, int x, int y) {
	this->identificador = ID++;
	this->id_personagem = nome;
	this->custo = 0;
	this->defesa = 0;
	this->saude = 0;
	this->x = x;
	this->y = y;
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

int Personagem::getIdentificador() {
	return identificador;
}

int Personagem::getX() {
	return x;
}

int Personagem::getY() {
	return y;
}

void Personagem::setX(int x){
	this->x = x;
}

void Personagem::setY(int y) {
	this->y = y;
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
#include "Seres.h"
#include "Caracteristica.h"
#include "Personagem.h"
#include "Planicie.h"

Seres::Seres(int x, int y) :Personagem('S', x,y) {
	this->forca = 10;
	this->velocidade = 0;
	this->ataque = 0;
	this->contador_esp = 2;
	this->contador_remedio = 1;
	this->bandeira = ' ';
	this->castelo = 1;
}
Seres::Seres(vector<Caracteristica*> c ){
	
	this->s_carac = vector<Caracteristica *>();
}

void Seres::adicionaCaraSeres(Caracteristica *c) {
	s_carac.push_back(c);
}

/*bool Seres::verificaCustos(int custo_m, int custo_f, Seres *s) {
	if ((s->getCusto() - custo_m) >= 0 && (forca - custo_f) >= 0) {
		return true;
	}
	return false;
}*/

Seres Seres::efeitoCaracteristicaConfig(Planicie *plan) {
	Caracteristica *c = nullptr;
	c->efeitoCaracteristicaSim(this, plan);
	return *this;
}

/*Seres Seres::efeitoCaracteristicaSim(Caracteristica *c) { // colocar na caracteristica, ser e que invoca, virtual

	switch (c->getIdCaracteristica()){
	case 1: break;
	case 2: this->setSaude(1); break;
	case 3: this->setDefesa(1); break;
	case 4: this->setDefesa(2); break;
	case 5: ataque += 2; break;
	case 6: if (this->contador_esp >= 0) { this->contador_esp--; ataque += 3; }
			else { ataque += 2; } //QUANDO VOLTAR AO CASTELO, POR O CONTADOR_ESP A 2
	case 7: //RECEBER MAPA E VER SE INIMIGO ENCONTRA ADJACENTE
			break;
	case 8: break;
	case 9: break;
	case 10: break;
	case 11: //ATRIBUIR X E Y AO PERSONAGEM RANDOM 
			break;
	case 12: if (this->getSaude() <= 3) {
				if (this->getContadorRem() == 1) {
					this->setContadorRem(0);
					this->setSaude(2); break; //QUANDO VOLTAR AO CASTELO, POR O CONTADORREM A 1
				}
			}
	case 13: break;
	case 14: break;
	default: break;
	}
	/*if (c->getIdCaracteristica() == 1) {
		forca = forca + 1;
	}
	else if (c->getIdCaracteristica() == 2) {
		velocidade = velocidade + 2;
	}
	return *this;
}*/

int Seres::getForca(){
	return forca;
}

void Seres::setForca(int f){
	this->forca = f;
}

int Seres::getContadorRem(){
	return contador_remedio;
}

void Seres::resetContadorEsp(int x) {
	this->contador_esp = x;
}

void Seres::setContadorEsp(int x) {
	this->contador_esp -= x;
}

void Seres::setContadorRem(int x) {
	this->contador_remedio -= x;
}

int Seres::getAtaque() {
	return ataque;
}

int Seres::getVelocidade() {
	return velocidade;
}

void Seres::setAtaque(int x) {
	this->ataque += x;
}

void Seres::setVelocidade(int x) {
	this->velocidade += x;
}

char Seres::getBandeira() {
	return bandeira;
}

void Seres::setBandeira(char x) {
	this->bandeira = x;
}

int Seres::getDentroCastelo(){
	return castelo;
}

void Seres::setDentroCastelo(int x){
	this->castelo = x;
}

vector<Caracteristica*> Seres::retornaCarS() {
	return s_carac;
}

int Seres::getContadorEsp() {
	return contador_esp;
}


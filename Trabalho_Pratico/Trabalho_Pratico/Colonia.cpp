#include "Colonia.h"
#include "Personagem.h"
#include "Edificios.h"
#include "Seres.h"
#include "Perfil.h"

Colonia::Colonia(char id) {
	this->id_colonia = id;
	this->cor = rand() % 16; //Numero da cor entre 0 e 15, aproveita-se o Consolas.h
	criaCastelo();
}

void Colonia::criaCastelo() {
	castle = new Castelo();
	eq_edificios.push_back(castle);
}

char Colonia::getId_colonia() {
	return id_colonia;
}

Personagem* Colonia::getCastelo() {
	return castle;
}

/*Personagem* Colonia::getEdificio() {

}*/

/*Personagem* Colonia::getSer() {
	ser = new Seres();
	return ser;
}*/

int Colonia::getCor() {
	return cor;
}


void Colonia::inserirSeres(int n, Perfil *p) {
	vector<Caracteristica *> c;
	vector <Caracteristica*>::iterator iter;
	
	for (int i = 0; i < n; i++) {
		ser = new Seres();
		c = p->getCaracteristicas();
		for (iter = c.begin();iter != c.end();iter++) {
			ser->adicionaCaraSeres(*iter);
			ser->efeitoCaracteristica(*iter);
		}
		eq_seres.push_back(ser);
	}
}

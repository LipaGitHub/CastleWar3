#include "Colonia.h"
#include "Personagem.h"
#include "Edificios.h"
#include "Seres.h"
#include "Perfil.h"

Colonia::Colonia(char id, int x, int l, int c) {
	this->id_colonia = id;
	this->saldo = x;
	this->cor = rand() % 16; //Numero da cor entre 0 e 15, aproveita-se o Consolas.h
	criaCastelo(l,c);
}

void Colonia::criaCastelo(int x, int y) {
	castle = new Castelo(x,y);
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

int Colonia::getSaldo(){
	return saldo;
}


void Colonia::inserirSeres(int n, Perfil *p) {
	vector<Caracteristica *> c;
	vector <Caracteristica*>::iterator iter;
	int total_mon = 0, total_for = 0, saldo_disp = 0, forca_disp = 0;

	c = p->getCaracteristicas();
	for (iter = c.begin(); iter != c.end(); iter++) {
		total_mon += custoMonCaracteristicas(*iter);
		total_for += custoForCaracteristicas(*iter);
	}

	total_mon = total_mon * n;
	//total_for = total_for * n;

	if (total_mon >= this->getSaldo()) {
		cout << "Saldo inferior ao custo das caracteristicas! Diminui na criacao dos Seres ou nas caracteristicas.\n";
	}
	else {
		cout << "Saldo disponivel para efetuar operacao!\n";
		for (int i = 0; i < n; i++) {
			ser = new Seres();
			if ((ser->getForca() - total_for) >= 0) {
				cout << i+1 << ". Ser pode obter as caracterisitcas (forca)!\n";
				forca_disp = ser->getForca() - total_for;
				ser->setForca(forca_disp);
				for (iter = c.begin(); iter != c.end(); iter++) {
					ser->adicionaCaraSeres(*iter);
					ser->efeitoCaracteristica(*iter);
				}
				saldo_disp = this->getSaldo() - (total_mon/n);
				this->setSaldo(saldo_disp);
				eq_seres.push_back(this->ser); //onde guarda a forca, velocidade e ataque??
			}
			else {
				cout << "O ser nao pode obter as caracterisitcas (forca)!\n";
			}
		}
	}
}

int Colonia::custoMonCaracteristicas(Caracteristica * c){
	return c->getC_Mon();
}

int Colonia::custoForCaracteristicas(Caracteristica * c) {
	return c->getC_For();
}

void Colonia::setSaldo(int x) {
	this->saldo = x;
}

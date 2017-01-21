#include "Colonia.h"
#include "Personagem.h"
#include "Edificios.h"
#include "Seres.h"
#include "Perfil.h"
#include "Planicie.h"

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

void Colonia::criaEdificio(string nome, int x, int y) {
	Edificio * ed;
	if (nome == "quinta") {
		ed = new Quinta(x, y);
		eq_edificios.push_back(ed);
		
	}
	else if (nome == "torre") {
		ed = new Torre(x, y);
		eq_edificios.push_back(ed);
	}
	
}


char Colonia::getId_colonia() {
	return id_colonia;
}

Personagem* Colonia::getCastelo() {
	return castle;
}

vector<Personagem*> Colonia::getSeres() {
	return eq_seres;
}

Seres * Colonia::retornaSer(){
	return ser;
}

vector<Personagem*> Colonia::getEdificio() {
	return eq_edificios;
}

/*Personagem* Colonia::getSer() {
	ser = new Seres();
	return ser;
}*/

void Colonia::setCor(int x) {
	cor = x;
}

int Colonia::getCor() {
	return cor;
}

int Colonia::getSaldo(){
	return saldo;
}


void Colonia::inserirSeres(int n, Perfil *p, Planicie *plan) {
	vector<Caracteristica *> c;
	vector <Caracteristica*>::iterator iter;
	int total_mon = 0, total_for = 0, saldo_disp = 0, forca_disp = 0;

	c = p->getCaracteristicas();
	for (iter = c.begin(); iter != c.end(); iter++) {
		total_mon += custoMonCaracteristicas(*iter);
		total_for += custoForCaracteristicas(*iter);
	}

	total_mon = total_mon * n;

	if (total_mon >= this->getSaldo()) {
		cout << "Saldo inferior ao custo das caracteristicas! Diminui na criacao dos Seres ou nas caracteristicas.\n";
	}
	else {
		cout << "Saldo disponivel para efetuar operacao!\n";
		Personagem *cas;
		int x,y;
		
		cas = this->getCastelo();
		x = cas->getX();
		y = cas->getY();
		for (int i = 0; i < n; i++) {
			ser = new Seres(x,y);
			

			if ((ser->getForca() - total_for) >= 0) {
				cout << i+1 << ". Ser pode obter as caracterisitcas (forca)!\n";
				ser->setBandeira(this->getId_colonia());
				forca_disp = ser->getForca() - total_for;
				ser->setForca(forca_disp);
				for (iter = c.begin(); iter != c.end(); iter++) {
					ser->adicionaCaraSeres(*iter);
				}
				saldo_disp = this->getSaldo() - (total_mon/n);
				this->setSaldo(saldo_disp);
				//Personagem*** mapa = plan->retornaMapa();
				ser->efeitoCaracteristicaConfig(plan);
				eq_seres.push_back(this->ser); //onde guarda a forca, velocidade e ataque??
				cout << "X:" << ser->getX() << "Y:" << ser->getY() << "\n";
			}
			else {
				cout << "O ser nao pode obter as caracterisitcas (forca)!\n";
				//FALTA O DESTRUTOR DO SER CASO NAO POSSA SER CRIADO DEVIDO AO CUSTO DAS CARAC
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

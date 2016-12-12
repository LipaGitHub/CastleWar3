#pragma once
#include <vector>
#include "Interface.h"
#include "Planicie.h"
#include "Caracteristica.h"
#define MAX_PERFIS 5

class Perfil {
	char id_perfil;
	vector<Caracteristica *> perfil;
	vector<Caracteristica *>::iterator iter2;

public:
	Perfil(char id_perfil){
		this->id_perfil = id_perfil;
		this->perfil = vector<Caracteristica *>(); //Faz com que o vector esteja a zero/null
	}

	void adicionaCaracteristicaNoPerfil(int id) {
		perfil.push_back(new Caracteristica(id)); //Guarda caracteristica no respetivo Perfil
	}

	void removeCaracteristicaNoPerfil(int id) {
		for(auto c : perfil)
			if (this->getIDPerfil() == id) {
				perfil.erase(c);
			}
	}

	~Perfil() {
		for (auto c : perfil)
			delete c;
		perfil.clear();
	}

	/*int incrementaIdPerfil() {
		return id++;
	}*/

	/*int verificaNPerfis() {
		if (perfis.size() < MAX_PERFIS)
			return 0;
		else return 1;
	}*/

	char getIDPerfil() {
		return id_perfil;
	}

	/*void adicionaCaracteristica(Caracteristica c) {
		perfil.push_back(c);
	}*/

	/*void guardaPerfil(Perfil p) {
		perfis.push_back(p);
	}*/

	//INCOMPLETO
	void mostraPerfil(char letra) {
		//Mostrar as carateristicas de um certo perfil
		//Aqui teremos que usar os iteradores!!
	}

	/*void mostraPerfis() {
		//vector<Perfil>::iterator iter;
		for (iter = perfis.begin(); iter != perfis.end(); iter++)
			cout << (*iter).toString() << endl;
	}*/

	/*string toString() {
		ostringstream os;
		//vector<Caracteristica>::iterator iter;

		os << "Perfil " << id_perfil << ":\n";
		for (iter2 = perfil.begin(); iter2 != perfil.end(); iter2++){
			os << (*iter2).toString() << endl;
		}
		return os.str();
	}*/

	/*
	PERFIS
	---------
	DEFENSIVOS têm caracteristicas com o id: 1,2,4,7;
	ESPIAO têm caracteristicas com o id: 1,4,8,10;
	AGRESSOR têm caracteristicas com o id: 1,6,7,9;
	EQUILIBRADO têm caracteristicas com o id: 1,2,5,7,11;
	NEUTRO têm caracteristicas com o id: 3,4,11,12;
	MAGICO têm caracteristicas com o id: 1,6,7,12,13;
	*/
};
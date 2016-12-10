#pragma once
#include <vector>
#include "Caracteristica.h"
#define MAX_PERFIS 5
//#define ARRAY "perfil_%c_caracteristicas"
///#define vector<int> "perfil_%c_caracteristicas";

class Perfil {
	int id;
	char id_perfil;
	vector<Caracteristica> perfil;
	vector<Perfil> perfis;

public:
	Perfil(char id_perfil){
		this->id = 0;
		this->id_perfil = id_perfil;
	}

	int incrementaIdPerfil() {
		return id++;
	}

	char getIDPerfil() {
		return id_perfil;
	}

	void adicionaCaracteristica(Caracteristica c) {
		perfil.push_back(c);
	}

	void guardaPerfil(Perfil p) {
		perfis.push_back(p);
	}

	//INCOMPLETO
	void mostraPerfil(char letra) {
		//Mostrar as carateristicas de um certo perfil
		//Aqui teremos que usar os iteradores!!
	}


	//INCOMPLETO...
	string toString() {
		ostringstream os;
		os << "Perfil" << id_perfil;// << ":\n" << "\tID: " << perfil[0].getID;// << ", Custo monetario: " << c_mon << ", Custo forca : " << c_for;
		return os.str();
	}

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
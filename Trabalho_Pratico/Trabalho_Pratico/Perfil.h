#pragma once
#include <vector>
#include "Caracteristica.h"
#define MAX_PERFIS 5
//#define ARRAY "perfil_%c_caracteristicas"
///#define vector<int> "perfil_%c_caracteristicas";

class Perfil {
	int id;
	char id_perfil;
	int perfil_count;
	//vector< vector<int> > array;
	vector<char> perfil;
	vector< vector<int> > caracteristicas;

public:
	Perfil(){
		this->id = 0;
		this->id_perfil = ' ';
		this->perfil_count = 0;
	}

	int incrementaIdPerfil() {
		return id++;
	}

	/*void setPerfil(char p) {
		this->id_perfil = p;
		this->perfil_count++;
	}

	char getPerfil() {
		return id_perfil;
	}*/

	void adicionaPerfil(char letra) {
		perfil.push_back(letra);
	}

	void adicionaCaracteristica(int id, int id_caracteristica) {
		/*char buffer[25];
		sprintf(buffer, ARRAY, id_perfil);
		(sprintf(buffer, "perfil_%c_caracteristicas", id_perfil)).push_back(id_caracteristica);
		array.push_back(id_caracteristica);*/

		//NAO ESTOU A CONSEGUIR ? :(
		/*caracteristicas[id].push_back(id_caracteristica);
		caracteristicas.at(id).push_back(id_caracteristica);*/
	}

	//Contem uma identificação
	//Contem uma quantidade de caracteristicas
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
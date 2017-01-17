#pragma once
#ifndef PERFIL_H
#define PERFIL_H

#include <vector>
#include "Caracteristica.h"
#define MAX_PERFIS 5



class Perfil {
	char id_perfil;
	vector<Caracteristica *> Pcaract;
	vector<Caracteristica *>::iterator iter2;

public:
	Perfil(char id_perfil);
	void adicionaCaracteristicaNoPerfil(int id);
	void removeCaracteristicaNoPerfil(int id);
	bool procuraCarPerfil(int id);
	char getIDPerfil();
	vector<Caracteristica *> getCaracteristicas();
	Caracteristica *getCaracteristasDoPerfil(char a);
	void mostraPerfil();
	//int contaCaracteristicas();
	~Perfil();
};
#endif
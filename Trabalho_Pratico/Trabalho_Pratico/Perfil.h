#pragma once
#include <vector>
#include "Interface.h"
#include "Planicie.h"
#include "Caracteristica.h"
#define MAX_PERFIS 5

class Perfil {
	char id_perfil;
	vector<Caracteristica *> caract;
	vector<Caracteristica *>::iterator iter2;

public:
	Perfil(char id_perfil);
	void adicionaCaracteristicaNoPerfil(int id);
	void removeCaracteristicaNoPerfil(int id);
	~Perfil();
	char getIDPerfil();
	void mostraPerfil(char letra);
};
#ifndef CARACTERISTICA_H
#define CARACTERISTICA_H


#include "Interface.h"
using namespace std;

class Personagem;

class Caracteristica {
	string nome;
	int id, c_mon, c_for;
	Personagem * efeito;
	string nomes[14] = { {"Bandeira"}, { "Superior" },{ "Pele dura" },{ "Armadura" },{ "Faca" },{ "Espada" },
						{ "Agressao" },{ "Ecologico" },{ "HeatSeeker" },{ "BuildSeeker" },{ "Walker" },{ "Remedio" },
						{ "SecondChance" },{ "Aluno" } };

	int carac[14][3] = { { 1,1,0 },
						{ 2,1,1 },
						{ 3,2,2 },
						{ 4,2,3 },
						{ 5,1,1 },
						{ 6,2,2 },
						{ 7,1,1 },
						{ 8,1,1 },
						{ 9,1,1 },
						{ 10,1,1 },
						{ 11,1,1 },
						{ 12,2,1 },
						{ 13,3,0 },
						{ 14,0,0 }
						};
public:
	Caracteristica(int id);
	int getIdCaracteristica();
	string toString();
	int efeitoCaracteristica(int id);
};
#endif
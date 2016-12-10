#pragma once
#include "Personagem.h"
#include "Interface.h"
using namespace std;

class Caracteristica {
	string nome;
	int id, c_mon, c_for;
	Personagem efeito;
	//vector <Caracteristica *> perfil;
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
	Caracteristica(int id) {
		this->id = id;
		this->c_mon = carac[id-1][1];
		this->c_for = carac[id-1][2];
	}

	int getID() {
		return id;
	}

	string toString() {
		ostringstream os;
		os << " ID: " << id << ", Custo monetario: " << c_mon << ", Custo forca : " << c_for;
		return os.str();
	}
};

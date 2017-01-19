#include "Caracteristica.h"
#include "Personagem.h"

Caracteristica::Caracteristica(int id) {
	this->nome = nomes[id - 1];
	this->id = id;
	this->c_mon = carac[id - 1][1];
	this->c_for = carac[id - 1][2];
}

int Caracteristica::getIdCaracteristica() {
	return id;
}

string Caracteristica::toString() {
	ostringstream os;
	os << " ID: " << id << ", Custo monetario: " << c_mon << ", Custo forca : " << c_for;
	return os.str();
}
int Caracteristica::efeitoCaracteristica(int id) {
	int res[2];
	for (int i = 0; i < 2; i++)
		res[i] = carac[id - 1][i + 1];
	return res[2];
}

int Caracteristica::getC_Mon(){
	return c_mon;
}

int Caracteristica::getC_For(){
	return c_for;
}

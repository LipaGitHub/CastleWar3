#include "Caracteristica.h"

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
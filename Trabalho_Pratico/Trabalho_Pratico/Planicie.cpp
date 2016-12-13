#include "Planicie.h"

Planicie::Planicie(const int l, const int c, int m=0):linha(l), coluna(c), moedas(m) {
	//this->perfis = vector<Perfil *>();
	criaMapa();
}

int Planicie::getLinha() {
	return linha;
}

int Planicie::getColuna() {
	return coluna;
}

vector<Perfil *> Planicie::retornaPerfis() {
	return perfis;
}

void Planicie::criaMapa() {
	mapa = new Personagem **[getLinha()];
	for (int i = 0; i < getLinha(); i++) {
		mapa[i] = new Personagem *[getColuna()];
	}
	for (int i = 0; i < getLinha(); i++)
		for (int j = 0; j < getColuna(); j++)
			mapa[i][j] = NULL;
}

string Planicie::toString()const {
	ostringstream os;
	for (int i = 0; i < linha; i++) {
		for (int j = 0; j < coluna; j++)
			cout << "*";
		cout << "\n";
	}
	return os.str();
}

void Planicie::criaPerfil(char letra) {
	perfis.push_back(new Perfil(letra));
}

void Planicie::removePerfil(char letra) {
	for (iter = perfis.begin(); iter != perfis.end(); iter++) {
		if ((*iter)->getIDPerfil() == letra) {
			iter = perfis.erase(iter);
			break;
		}
	}
}



void Planicie::setMoedas(int n) {

}

/*ostream &operator <<(ostream &o, const Planicie &p) {
o << p.toString();
return o;
}*/
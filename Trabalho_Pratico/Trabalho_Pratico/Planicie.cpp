#include "Perfil.h"
#include "Colonia.h"
#include "Personagem.h"
#include "Planicie.h"
#include "Consola.h"
#include <time.h>

Planicie::Planicie(const int l, const int c, int m, int o):linha(l), coluna(c), moedas(m), oponentes(o) {
		criaMapa();
}

int Planicie::getLinha() {
	return linha;
}

int Planicie::getColuna() {
	return coluna;
}
void Planicie::setMoedas(int m) {
	this->moedas = m;
}
int Planicie::getMoedas() {
	return moedas;
}
void Planicie::setOponentes(int opo) {
	this->oponentes = opo;
}
vector<Perfil *> Planicie::retornaPerfis() {
	return perfis;
}

vector<Colonia *> Planicie::retornaColonias() {
	return colonias;
}

bool Planicie::verificaColonia() {
	if (retornaColonias().empty() == 0)
		return true;
	else
		return false;

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
	perfis.erase(iter);

}
void Planicie::criaColonia(int op,int x) {
	
	char abc = 'A';
	srand(time(NULL));
	int valor = op + 1;
	for (int i = 0; i < valor; i++, abc++) {
		int l = rand() % getLinha();
		int c = rand() % getColuna();
		colonias.push_back(new Colonia(abc, x, l,c));
		posicionaPersonagem(colonias[i]->getCastelo(), l, c);
		//posicionaCastle((colonias->getCastelo()), l, c);
	}

}


Perfil * Planicie::procuraPerfil(char letra) {
	for (iter = perfis.begin(); iter != perfis.end(); iter++) {
		if ((*iter)->getIDPerfil() == letra) {
			return *iter;
		}
	}
	return nullptr;
}

void Planicie::procuraColonia(char col, int l, int c) { //Talvez para outras utilizãções
	
	for (iter2 = colonias.begin(); iter2 != colonias.end(); iter2++) {
		if ((*iter2)->getId_colonia() == col) {
			posicionaPersonagem(((*iter2)->getCastelo()), l, c);
		}
	}
}


Colonia * Planicie::getColonia(char id) {
	
	for (iter2 = colonias.begin(); iter2 != colonias.end(); iter2++) {
		if ((*iter2)->getId_colonia() == id) {
			return *iter2;
		}
	}
	return nullptr;
}

void Planicie::moedasColonia(int x) {
	
	for (iter2 = colonias.begin(); iter2 != colonias.end(); iter2++) {
		(*iter2)->setSaldo(x);
	}
}

void Planicie::posicionaPersonagem(Personagem* p, int l, int c) { //ver o que se pode generalizar
	
	if (mapa[l][c] == NULL)
		mapa[l][c] = p ;
}

void Planicie::movePersonagem(Personagem* cas, int l, int c) {
	int xaux, yaux;
	xaux = cas->getX();
	yaux = cas->getY();
	for (int i = xaux; i <= xaux; i++)
		for (int j = yaux; j <= yaux; j++)
			mapa[i][j] = nullptr;


	if (mapa[l][c] == NULL) {
		mapa[l][c] = cas;
		cas->setX(l);
		cas->setY(c);
	}
}

Personagem *** Planicie::retornaMapa() {
	return mapa;
}

void Planicie::imprimeMapa() {
	
	Personagem *p;
	int n_ocorrencias = 0;
	for (int i = 0; i < getLinha(); i++) {
		for (int j = 0; j < getColuna(); j++) {
			if (mapa[i][j] != NULL) {
				p = colonias[n_ocorrencias]->getCastelo();
				Consola::setTextColor(colonias[n_ocorrencias]->getCor());
				cout << p->getID() << "\t";
				n_ocorrencias++;
			}
			else {
				Consola::setTextColor(Consola::VERDE_CLARO);
				cout << "X\t";
			}
		}
		cout << "\n";
	}
	for (auto c : colonias) {
		Consola::setTextColor(c->getCor());
		cout << "Colonia " << c->getId_colonia() << "\n";
	}
	Consola::setTextColor(Consola::VERDE_CLARO);
}

/*void inserirSeres(int n) {
Perfil *p;
p = procuraPerfil('a');
if (p.) {

}
//AGARRAR NAS CARACTERISTICAS DO PERFIL
//CRIAR n SERES COM ESSAS CARACTERISTICAS

/*for (int i = 0; i < n; i++) {
}
}*/



/*ostream &operator <<(ostream &o, const Planicie &p) {
o << p.toString();
return o;
}*/
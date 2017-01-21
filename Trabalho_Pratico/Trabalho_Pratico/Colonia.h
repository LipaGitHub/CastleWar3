
#ifndef COLONIA_H
#define COLONIA_H

#include <vector>
using namespace std;

class Perfil;
class Personagem;
class Castelo;
class Caracteristica;
class Seres;
class Planicie;

class Colonia {
	//Contem um conjunto de seres e edificios
	//Tem uma Letra que a representa
	//Economia de moedas
	char id_colonia;
	vector <Personagem*> eq_edificios;
	vector <Personagem*> eq_seres;
	Castelo * castle;
	Seres * ser;
	int cor, saldo;

public:
	Colonia(char id, int x, int l, int c);
	void criaCastelo(int x, int y);
	void criaEdificio(string nome,int x, int y);
	char getId_colonia();
	Personagem* getCastelo();
	vector <Personagem*> getEdificio();
	vector<Personagem*> getSeres();
	void setSaldo(int x);
	//Personagem* getSer();
	int getCor();
	int getSaldo();
	void inserirSeres(int n, Perfil *p, Planicie *plan);
	int custoMonCaracteristicas(Caracteristica *c);
	int custoForCaracteristicas(Caracteristica *c);
};
#endif
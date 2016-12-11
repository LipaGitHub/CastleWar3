#pragma once
#include <vector>
#include "Interface.h"
#include "Caracteristica.h"
#define MAX_PERFIS 5

vector<Perfil *> perfis;
vector<Perfil *>::iterator iter;

class Perfil {
	char id_perfil;
	vector<Caracteristica *> perfil;
	//vector<Perfil *> perfis;
	//vector<Perfil *>::iterator iter;
	vector<Caracteristica *>::iterator iter2;

public:
	Perfil(char id_perfil){
		this->id_perfil = id_perfil;
		this->perfil = vector<Caracteristica *>(); //Faz com que o vector esteja a zero/null
	}

	 void Perfil::criaPerfil(Perfil *p){
		 perfis.push_back(p);
	}

	void Perfil::adicionaCaracteristicaNoPerfil(char letra, int id) {
		for (iter = perfis.begin(); iter != perfis.end(); iter++) {
			if ((*iter)->id_perfil == letra) {
				Caracteristica c(id);
				perfil.push_back(&c); //Guarda caracteristica no respetivo Perfil
				cout << "Caracteristica adicionada!\n";
				break;
			}
		}
		cout << "Perfil nao existe para adicionar tal caracteristica!\n";
	}

	void removeCaracteristicaNoPerfil(char letra, int id) {
		for (iter = perfis.begin(); iter != perfis.end(); iter++) {
			if ((*iter)->id_perfil == letra) {
				for (iter2 = perfil.begin(); iter2 != perfil.end(); iter2++) {
					if ((*iter2)->getIdCaracteristica() == id) {
						iter2 = perfil.erase(iter2); //Remove caracteristica no respetivo Perfil
						cout << "Caracteristica removida!\n";
						break;
					}
				}
				cout << "A caracteristica nao existe no tal Perfil para ser eliminada!\n";
			}
		}
		cout << "Perfil nao existe para adicionar tal caracteristica!\n";
	}

	void removePerfil(char letra) {
		for (iter = perfis.begin(); iter != perfis.end(); iter++) {
			if ((*iter)->id_perfil == letra) {
				iter = perfis.erase(iter);
				break;
			}
		}
	}

	/*void Clube::removePessoa(int bi) {
		for (std::vector<Pessoa *>::iterator i = pessoas.begin(); i != pessoas.end();) {
			if ((*i)->getBI() == bi)
				i = pessoas.erase(i);

			else ++i;
		}
	}

	void Clube::mostraTodos()
	{
	for (auto &i : pessoas)
	std::cout << i->getAsString() << "\n";
	}*/

	/*int incrementaIdPerfil() {
		return id++;
	}*/

	/*int verificaNPerfis() {
		if (perfis.size() < MAX_PERFIS)
			return 0;
		else return 1;
	}*/

	char getIDPerfil() {
		return id_perfil;
	}

	/*void adicionaCaracteristica(Caracteristica c) {
		perfil.push_back(c);
	}*/

	/*void guardaPerfil(Perfil p) {
		perfis.push_back(p);
	}*/

	//INCOMPLETO
	void mostraPerfil(char letra) {
		//Mostrar as carateristicas de um certo perfil
		//Aqui teremos que usar os iteradores!!
	}

	/*void mostraPerfis() {
		//vector<Perfil>::iterator iter;
		for (iter = perfis.begin(); iter != perfis.end(); iter++)
			cout << (*iter).toString() << endl;
	}*/

	/*string toString() {
		ostringstream os;
		//vector<Caracteristica>::iterator iter;

		os << "Perfil " << id_perfil << ":\n";
		for (iter2 = perfil.begin(); iter2 != perfil.end(); iter2++){
			os << (*iter2).toString() << endl;
		}
		return os.str();
	}*/

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
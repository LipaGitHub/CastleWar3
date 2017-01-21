#include "Caracteristica.h"
#include "Personagem.h"
#include "Seres.h"

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

/*int Caracteristica::efeitoCaracteristica(int id) {
	int res[2];
	for (int i = 0; i < 2; i++)
		res[i] = carac[id - 1][i + 1];
	return res[2];
}*/

void Caracteristica::efeitoCaracteristicaSim(Seres *s, Planicie *plan) {
	int x, y;
	Personagem*** mat = plan->retornaMapa();
	/*for (int i = 0; i < plan->getLinha(); i++) {
		for (int j = 0; j < plan->getColuna(); j++) {
			if (mat[i][j] != NULL) {
				cout << "O\t";
			}
			else {
				cout << "X\t";
			}
		}
		cout << "\n";
	}*/

	for (auto i : s->retornaCarS()) {
		switch (i->getIdCaracteristica()) {
		case 1: /*s->setBandeira('A');*/ break;
		case 2: s->setSaude(1); break;
		case 3: s->setDefesa(1); break;
		case 4: s->setDefesa(2); break;
		case 5: s->setAtaque(2); break;
		case 6: if (s->getContadorEsp() > 0) {
			s->setContadorEsp(1);
			s->setAtaque(3);
		}
				else { s->setAtaque(2); } break;//TODO: QUANDO VOLTAR AO CASTELO, POR O CONTADOR_ESP A 2
		case 7:
			x = s->getX(); y = s->getY();
			if (mat[x - 1][y - 1] != NULL || mat[x - 1][y] != NULL || mat[x - 1][y + 1] != NULL ||
				mat[x][y - 1] != NULL || mat[x][y + 1] != NULL || mat[x + 1][y - 1] != NULL ||
				mat[x + 1][y] != NULL || mat[x + 1][y + 1] != NULL) {
				if (mat[x - 1][y - 1]->getID() == 'S' || mat[x - 1][y]->getID() == 'S' || mat[x - 1][y + 1]->getID() == 'S' ||
					mat[x][y - 1]->getID() == 'S' || mat[x][y + 1]->getID() == 'S' || mat[x + 1][y - 1]->getID() == 'S' ||
					mat[x + 1][y]->getID() == 'S' || mat[x + 1][y + 1]->getID() == 'S') {
					//TEM DE ATAQUAR
					cout << "Inimigo encontrado!\n"; break;//FALTA COMPARAR SE TRATA DA MESMA COLONIA OU NAO
				}
			}
			/*if (x == 0 && y < plan->getColuna() - 1 && y != 0) {
				if (mat[x + 1][y - 1]->getID() == 'S') { cout << "Inimigo encontrado\n"; break; }
				if (mat[x + 1][y + 1]->getID() == 'S') { cout << "Inimigo encontrado\n"; break; }
			}

			if (x == plan->getLinha() - 1 && y < plan->getColuna() - 1 && y != 0) {
				if (mat[x - 1][y - 1]->getID() == 'S') { cout << "Inimigo encontrado\n"; break; }
				if (mat[x - 1][y + 1]->getID() == 'S') { cout << "Inimigo encontrado\n"; break; }
			}

			if (x > 0 && x <= plan->getLinha() - 1 && y == 0) {
				if (mat[x - 1][y + 1]->getID() == 'S') { cout << "Inimigo encontrado\n"; break; }
				//if (mat[x + 1][y + 1]->getID() == 'S') { cout << "Inimigo encontrado\n"; break; }
			}

			if (y > 0 && y <= plan->getColuna() - 1 && x == plan->getColuna() - 1) {
				if (mat[x - 1][y - 1]->getID() == 'S') { cout << "Inimigo encontrado\n"; break; }
				if (mat[x - 1][y]->getID() == 'S') { cout << "Inimigo encontrado\n"; break; }
				if (mat[x][y - 1]->getID() == 'S') { cout << "Inimigo encontrado\n"; break; }
			}

			if (x >= 1 && x < plan->getLinha() - 1 && y >= 1 && y < plan->getColuna() - 1) {
				if (mat[x - 1][y - 1] != NULL || mat[x - 1][y] != NULL || mat[x - 1][y + 1] != NULL ||
					mat[x][y - 1] != NULL || mat[x][y + 1] != NULL || mat[x + 1][y - 1] != NULL ||
					mat[x + 1][y] != NULL || mat[x + 1][y + 1] != NULL) {
					if (mat[x - 1][y - 1]->getID() == 'S' || mat[x - 1][y]->getID() == 'S' || mat[x - 1][y + 1]->getID() == 'S' ||
						mat[x][y - 1]->getID() == 'S' || mat[x][y + 1]->getID() == 'S' || mat[x + 1][y - 1]->getID() == 'S' ||
						mat[x + 1][y]->getID() == 'S' || mat[x + 1][y + 1]->getID() == 'S') {
						//TEM DE ATAQUAR
						cout << "Inimigo encontrado!\n"; break;//FALTA COMPARAR SE TRATA DA MESMA COLONIA OU NAO
					}
				}
			}*/
			break;
		case 8:
			x = s->getX(); y = s->getY();
			if (mat[x - 1][y - 1] != NULL || mat[x - 1][y] != NULL || mat[x - 1][y + 1] != NULL ||
				mat[x][y - 1] != NULL || mat[x][y + 1] != NULL || mat[x + 1][y - 1] != NULL ||
				mat[x + 1][y] != NULL || mat[x + 1][y + 1] != NULL){
				if ((mat[x - 1][y - 1]->getID() == 'T') || (mat[x - 1][y]->getID() == 'T') || mat[x - 1][y + 1]->getID() == 'T' ||
					mat[x][y - 1]->getID() == 'T' || mat[x][y + 1]->getID() == 'T' || mat[x + 1][y - 1]->getID() == 'T' ||
					mat[x + 1][y]->getID() == 'T' || mat[x + 1][y + 1]->getID() == 'T' ||
					mat[x - 1][y - 1]->getID() == 'Q' || (mat[x - 1][y]->getID() == 'Q') || mat[x - 1][y + 1]->getID() == 'Q' ||
					mat[x][y - 1]->getID() == 'Q' || mat[x][y + 1]->getID() == 'Q' || mat[x + 1][y - 1]->getID() == 'Q' ||
					mat[x + 1][y]->getID() == 'Q' || mat[x + 1][y + 1]->getID() == 'Q' ||
					mat[x - 1][y - 1]->getID() == 'C' || (mat[x - 1][y]->getID() == 'C') || mat[x - 1][y + 1]->getID() == 'C' ||
					mat[x][y - 1]->getID() == 'C' || mat[x][y + 1]->getID() == 'C' || mat[x + 1][y - 1]->getID() == 'C' ||
					mat[x + 1][y]->getID() == 'C' || mat[x + 1][y + 1]->getID() == 'C') {
					//TEM DE ATACAR
					cout << "Edificio encontrado!\n"; //FALTA COMPARAR SE TRATA DA MESMA COLONIA OU NAO
				}
			}
			else { cout << "Nao ha edificio na vizinhanca!\n"; }
			break;
		case 9: break;
		case 10: break;
		case 11: //ATRIBUIR X E Y AO PERSONAGEM RANDOM

			break;
		case 12: if (s->getSaude() <= 3) {
			if (s->getContadorRem() == 1) {
				s->setContadorRem(0);
				s->setSaude(2); break; //QUANDO VOLTAR AO CASTELO, POR O CONTADORREM A 1
			}
		}
		case 13: break;
		case 14: break;
		default: break;
		}
	}
}

int Caracteristica::getC_Mon(){
	return c_mon;
}

int Caracteristica::getC_For(){
	return c_for;
}

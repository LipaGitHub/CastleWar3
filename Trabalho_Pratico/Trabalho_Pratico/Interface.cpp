#include "Interface.h"
#include "Planicie.h"
#include "Personagem.h"
#include "Config.h"
#include "Perfil.h"
#include "Consola.h"

#define CONFIGURACAO 0
#define SIMULACAO 0
#define TERMINA_PERFIL 15

void Interface::menu() {

	
	Consola::gotoxy(10, 11);
	cout << "-------------------------------------------------------" << endl;
	Consola::gotoxy(10, 12);
	cout << "|                                                     |" << endl;
	Consola::gotoxy(10, 13);
	cout << "|               Menu de configuracao:                 |" << endl;
	Consola::gotoxy(10, 14);
	cout << "|                                                     |" << endl;
	Consola::gotoxy(10, 15);
	cout << "-------------------------------------------------------" << endl;
	Consola::gotoxy(10, 16);
	cout << "Opcoes: \n \n" 
		<< "dim linha coluna                -Define dimensoes da planicie\n"
		<< "moedas numero                   -Define quant. moedas iniciais\n"
		<< "oponentes numero                -Define num. colonias oponentes\n"
		<< "castelo colonia lin col         -Define posi do castelo da colonia indicada\n"
		<< "mkperfil letra                  -Define perfil por letra especificada\n"
		<< "addperfil letra caracteristica  -Adiciona caracteristica indicada ao perfil da letra\n"
		<< "subperfil letra caracteristica  -Remove caracteristica no perfil especificado\n"
		<< "rmperfil letra                  -Abona o perfil especificado\n"
		<< "load ficheiro                   -Carrega comandos no ficheiro\n"
		<< "inicio                          -Fim Configuracao, passar simulacao\n"
		<< endl;

}

void Interface::perfis() {
	cout << "-------------------------------------------------------" << endl;
	cout << "|                                                     |" << endl;
	cout << "|               Criacao de perfil                     |" << endl;
	cout << "|                                                     |" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Caracteristicas: \n"
		<< " 1-\tBandeira\n"
		<< " 2-\tSuperior\n"
		<< " 3-\tPele dura\n"
		<< " 4-\tArmadura\n"
		<< " 5-\tFaca\n"
		<< " 6-\tEspada\n"
		<< " 7-\tAgressao\n"
		<< " 8-\tEcologico\n"
		<< " 9-\tHeatSeeker\n"
		<< "10-\tBuildSeeker\n"
		<< "11-\tWalker\n"
		<< "12-\tRemedio\n"
		<< "13-\tSecondChance\n"
		<< "14-\tAluno\n"
		<< "\n"
		<< "15-\tTerminar perfil?\n"
		<< "\n\n"
		<< "Escolha o ID para juntar ao perfil: ";
}

void Interface::simulacao() {
	cout << "-------------------------------------------------------" << endl;
	cout << "|                                                     |" << endl;
	cout << "|                 Comandos da simulacao               |" << endl;
	cout << "|                                                     |" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Comandos possiveis: \n"
		<< "\tfoco linha coluna               -Define o foco\n"
		<< "\tzoomout n                       -Define o efeito zoom-out\n"
		<< "\tsetmoedas colonias num          -Adiciona ou retira num moedas a colonia (debug)\n"
		<< "\tbuild edif lin col              -Constroi edificio nas coordenadas lin col respeitando os custos\n"
		<< "\tlist colonia                    -Apresenta uma lista com tudo sobre a colonia\n"
		<< "\tlistp perfil                    -Apresenta os detalhes do perfil\n"
		<< "\tlistallp                        -Apresenta os perfis para o jogador e computador\n"
		<< "\tmkbuild edif lin col colonia    -Adiciona edificio na lin col da colonia (debug)\n"
		<< "\trepair EID                      -Repara o edificio com o EID\n"
		<< "\tupgrade EID                     -Melhora o edificio com o EID\n"
		<< "\tsell EID                        -Vende o edificio com o EID\n"
		<< "\tser num perf                    -Cria num de seres com o respetivo perfil\n"
		<< "\tnext                            -Avanca um instante\n"
		<< "\tnextn num                       -Avanca n instantes\n"
		<< "\tataca                           -Actuar as suas caracteristicas\n"
		<< "\trecolhe                         -Recolher os seres ao castelo\n"
		<< "\tfim                             -Termina a simulacao\n"
		<< "\tsave nome                       -Faz copia da simulacao\n"
		<< "\trestore nome                    -Repoe em accao a copia\n"
		<< "\terase nome                      -Elimina a copia indicada\n"
		<< "\tload ficheiro                   -Carrega os comandos de simulacao do ficheiro indicado\n"
		<< "\n\n";
}

void Interface::le_comandos(int tipo) {
	string linha;
	string res;

	system("cls");

	do {
		if (tipo == 0) {
			menu();
			cout << "comando>";
			getline(*entrada, linha);
			system("cls");
			res = interpretaComando(tipo, linha);
		}
		else {
			simulacao();
			cout << "comando>";
			getline(*entrada, linha);
			system("cls");
			res = interpretaComando(tipo, linha);
		}
	} while ((res != "inicio" && tipo == 0) || (res != "fim" && tipo == 1));

}

bool Interface::verificaComando(int tipo, string comando){
	string comandosC[9] = { "dim", "moedas","oponentes","castelo","mkperfil","addperfil","subperfil","rmperfil","inicio" };
	string comandosS[20] = { "zoomout","setmoedas","build","list","listp","listallp","mkbuild","repair","upgrade","sell",
							"ser","next","nextn","ataca","recolhe","fim","save","restore","erase","load" };
	if (tipo == 0) {
		for (auto c : comandosC) {
			if (c == comando)
				return true;
		}
	}
	else {
		for (auto c : comandosS) {
			if (c == comando)
				return true;
		}
	}
	return false;
}

string Interface::interpretaComando(int tipo, string linha) {
	string comando;
	stringstream iss(linha);
	iss >> comando;
	if (tipo == 0) {
		if (verificaComando(tipo, comando) == true) {
			if (comando == "dim") {

				if (p == nullptr) {
					int linha, coluna;
					iss >> linha;
					iss >> coluna;
					p = new Planicie(linha, coluna);

					//info.setDim(linha, coluna);
					//cout << "Linha:" << linha << endl;
					//cout << "Coluna:" << coluna << endl;
				}
				else {
					cout << "Planicie ja criada!\n";
					system("pause");
					le_comandos(CONFIGURACAO);
				}

			}
			if (comando == "moedas") {
				if (p != nullptr) {
					int n;
					iss >> n;
					p->setMoedas(n);
					//cout << "Moedas:" << n;
				}
				else { cout << "Tem que criar primeiro a planicie! \n Comando DIM!\n"; }
			}
			if (comando == "oponentes") {
				if (p != nullptr) {
					int n;
					iss >> n;
					p->criaColonia(n);
					p->setOponentes(n);
					//cout << "Oponentes:" << n;
				}
				else { cout << "Tem que criar primeiro a planicie! \n Comando DIM!\n"; }
			}
			if (comando == "castelo") {
				if (p != nullptr) {
					char colonia;
					int l, c;
					iss >> colonia;
					iss >> l >> c;
					p->procuraColonia(colonia, l, c);
					cout << "Castelo da colonia:" << colonia << "para:" << l << ";" << c;
				}
				else { cout << "Tem que criar primeiro a planicie! \n Comando DIM!\n"; }
			}

			if (comando == "mkperfil") {
				if (p != nullptr) {
					char letra;
					iss >> letra;

					if (info.getNPerfil() >= MAX_PERFIS) {
						cout << "Ja foram criados os 5 Perfis!\n";
					}
					else {
						info.adicionaNPerfil();
						p->criaPerfil(letra); //Põe o Perfil no vetor Perfis
						cout << "Perfil " << letra << " criado c/ sucesso!\n";
						/*do {
						perfis();
						cin >> id;
						if (id != 15) {
						//Criação de uma caracteristica
						Caracteristica car(id);
						//Adiciona a caracteristica criada no vetor do perfil
						p.adicionaCaracteristica(car);
						}
						} while (id != TERMINA_PERFIL); //TERMINA_PERFIL corresponde à "terminação" da criação do perfil
						//Guarda o perfil criado num vector Perfis
						p.guardaPerfil(p);
						//Mostra perfis
						p.mostraPerfis();*/
					}
				}
				else { cout << "Tem que criar primeiro a planicie! \n Comando DIM!\n"; }
			}
			if (comando == "addperfil") {
				if (p != nullptr) {
					char l;
					int c;
					iss >> l;
					iss >> c;
					Perfil *aux;
					aux = p->procuraPerfil(l);

					if (aux != nullptr) {
						aux->adicionaCaracteristicaNoPerfil(c);
						cout << "Adicionar a " << l << "caracteristica" << c << "\n";
					}
					else { cout << "Perfil inserido nao existe!\n"; }
				}
				else { cout << "Tem que criar primeiro a planicie! \n Comando DIM!\n"; }
			}
			if (comando == "subperfil") {
				bool res;
				if (p != nullptr) {
					char l;
					int c;
					iss >> l;
					iss >> c;

					Perfil *aux;
					aux = p->procuraPerfil(l);
					aux->mostraPerfil();
					if (aux != nullptr) {
						if ((res = aux->procuraCarPerfil(c)) == true) {
							aux->removeCaracteristicaNoPerfil(c);
							cout << "Remove a " << l << " a caracteristica" << c << "\n";
						}
						else { cout << "Nao existe a Caracteristica no perfil encontrado.\n"; }
					}
					else { cout << "Insira um Perfil valido!\n"; }
					cout << "\n";
					aux->mostraPerfil();
				}
				else { cout << "Tem que criar primeiro a planicie! \n Comando DIM!\n"; }

			}
			if (comando == "rmperfil") {
				if (p != nullptr) {
					char l;
					iss >> l;
					cout << "Abandonar perfil:" << l;
					Perfil *aux;
					aux = p->procuraPerfil(l);
					if (aux != nullptr) {
						aux->~Perfil();
						p->removePerfil(l);
						cout << "Removido Perfil com Sucesso!\n";
					}
					else { cout << "Não é possivel Sair de um Perfil que não existe!\n"; }
				}
				else { cout << "Tem que criar primeiro a planicie! \n Comando DIM!\n"; }
			}
			if (comando == "load") {
				string nome;
				iss >> nome;
				comando = leFicheiro(tipo, nome);

			}
		}
	}
	else if(tipo == 1) {
			if (verificaComando(tipo, comando) == true) {
				//COMANDOS DA SIMULACAO
				/* (...) */

				if (comando == "ser") {
					char perfil;
					int n;
					iss >> n;
					iss >> perfil;
					cout << "Numero de seres para ser criados: " << n << " com o perfil " << p << "\n";
					//FALTA FAZER:
					//VERIFICAR SE O n E' MENOR QUE 1 (se for 0 nem vale a pena fazer o comando)
					if (n >=1 && (p->procuraPerfil(perfil) !=nullptr) ) {
						
					}else {
						cout << "Valor invalido insira de novo!\n";
						return 0;
					}
						
					//(FUNCAO JA NO PLANICIE.H)
					//VERIFICAR SE O p PERFIL EXISTE NO VETOR DE PERFIS
					//(FUNCAO NO COLONIA.H)
					//SE FOR POSSIVEL, INSERIR n SERES AO VETOR EQ_SERES
				}
			}
		}else{ 
			cout << "Comando nao existe !\n";
		}
	return comando;
	
}

string Interface::leFicheiro(int tipo, string nome) {
	string linha, res;

	ifstream ifi(nome);
	if (ifi.is_open() == false)
		cout << "Erro ao introduzir o nome do ficheiro!\n";

	while (getline(ifi, linha)) {
		res = interpretaComando(tipo, linha);
	}

	ifi.close();
	return res;
}

Interface::Interface() {
	inicializa();
	p = nullptr;

}

void Interface::inicializa() {
	entrada = &cin;
	
}

void Interface::Mapa() {
	p->imprimeMapa();
}

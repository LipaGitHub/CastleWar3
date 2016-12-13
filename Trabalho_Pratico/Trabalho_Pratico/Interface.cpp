#include "Interface.h"
#include "Planicie.h"
#include "Config.h"
#include "Perfil.h"
#define TERMINA_PERFIL 15

void Interface::menu() {

	cout << endl;
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
	cout << "---------------Bem Vindo Ao Castle War-----------------" << endl;
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
	cout << endl;

	cout << "-------------------------------------------------------" << endl;
	cout << "|                                                     |" << endl;
	cout << "|               Menu de configuacao:                  |" << endl;
	cout << "|                                                     |" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Opcoes: \n"
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

void Interface::le_comandos() {
	string linha;
	string res, args;
	bool nao_existe;
	nao_existe = true;

	system("cls");

	do {
		menu();
		cout << "comando>";
		getline(*entrada, linha);
		res = interpretaComando(linha);
	} while (res != "inicio");

}

string Interface::interpretaComando(string linha) {
	string comando;
	stringstream iss(linha);
	iss >> comando;
	
	if (comando == "dim") {
		
		if (p==nullptr) {
			int linha, coluna;
			iss >> linha;
			iss >> coluna;
			p = new Planicie(linha,coluna);
			
			//info.setDim(linha, coluna);
			//cout << "Linha:" << linha << endl;
			//cout << "Coluna:" << coluna << endl;
		}
		else { cout << "Planicie ja criada!\n"; 
		system("pause");
		le_comandos();
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
			info.setOponentes(n);
			//cout << "Oponentes:" << n;
		}
		else { cout << "Tem que criar primeiro a planicie! \n Comando DIM!\n"; }
	}
	if (comando == "castelo") {
		if (p != nullptr) {
			string colonia;
			int l, c;
			iss >> colonia;
			iss >> l >> c;
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
				cout << "Adicionar a " << l << "caracteristica" << c;
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
			
			if (aux != nullptr ) {
				if ((res = aux->procuraCarPerfil(c)) == true) {
					aux->removeCaracteristicaNoPerfil(c);
					cout << "Remove a " << l << " a caracteristica" << c;
				}
				else { cout << "Nao existe a Caracteristica no perfil encontrado.\n"; }
			}
			else { cout << "Insira um Perfil valido!\n"; }
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
			}
			else { cout << "Não é possivel Sair de um Perfil que não existe!\n"; }
		}
		else { cout << "Tem que criar primeiro a planicie! \n Comando DIM!\n"; }
	}
	if (comando == "load") {
		string nome;
		iss >> nome;
		comando = leFicheiro(nome);

	}
	return comando;
}

string Interface::leFicheiro(string nome) {
	string linha, res;

	ifstream ifi(nome);
	if (ifi.is_open() == false)
		cout << "Erro ao introduzir o nome do ficheiro!\n";

	while (getline(ifi, linha)) {
		res = interpretaComando(linha);
	}

	ifi.close();
	return res;
}

Interface::Interface() {
	comandos = { "dim", "moedas","oponentes","castelo","mkperfil","addperfil","subperfil","rmperfil","inicio" };
	inicializa();
	p = nullptr;

}

void Interface::inicializa() {
	entrada = &cin;
	
}

string toString() {
	ostringstream os;
//	Config info;
//	os << info.getDimLinhas << " " << info.getDimColunas;
	return os.str();
}
#include "Interface.h"
#include "Planicie.h"
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
		<< "dim linha coluna                -Definde dimensoes da planicie\n"
		<< "moedas numero                   -Define quant moedas iniciais\n"
		<< "oponentes numero                -Define num colonias oponentes\n"
		<< "castelo colonia lin col         -Define posi do castelo da colonia indicada\n"
		<< "mkperfil letra                  -Define perfil por letra especificada\n"
		<< "addperfil letra caracteristica  -Add caracteristica indicada ao perfil da letra\n"
		<< "subperfil letra caracteristica  -Remove caracteristica no perfil especificado\n"
		<< "rmperfil letra                  -Abona o perfil especificado\n"
		<< "load ficheiro                   -Carrega comandos no ficheiro\n"
		<< "inicio                          -Fim Configuracao, passar simulacao\n"
		<< endl;


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
		res = intrepetaComando(linha);

	} while (res != "inicio");

}
string Interface::intrepetaComando(string linha) {
	string comando;

	stringstream iss(linha);
	iss >> comando;
	if (comando == "dim") {
		int linha, coluna;
		iss >> linha;
		iss >> coluna;
		cout << "Linha:" << linha << endl;
		cout << "Coluna:" << coluna << endl;
	}
	if (comando == "moedas") {
		int n;
		iss >> n;
		cout << "Moedas:" << n;
	}
	if (comando == "oponentes") {
		int n;
		iss >> n;
		cout << "Oponentes:" << n;
	}
	if (comando == "castelo") {
		string colonia;
		int l, c;
		iss >> colonia;
		iss >> l >> c;
		cout << "Castelo da colonia:" << colonia << "para:" << l << ";" << c;
	}

	if (comando == "mkperfil") {
		string letra;
		iss >> letra;
		cout << "Perfil com letra:" << letra;
	}
	if (comando == "addperfil") {
		string l;
		int c;
		iss >> l;
		iss >> c;
		cout << "Adicionar a " << l << "caracteristica" << c;
	}
	if (comando == "subperfil") {
		string l;
		int c;
		iss >> l;
		iss >> c;
		cout << "Remove a " << l << " a caracteristica" << c;
	}
	if (comando == "rmperfil") {
		string l;
		iss >> l;
		cout << "Abandonar perfil:" << l;
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
		ifi.close();

	while (getline(ifi, linha)) {

		res = intrepetaComando(linha);


	}

	ifi.close();
	return res;

}

Interface::Interface() {
	comandos = { "dim", "moedas","oponentes","castelo","mkperfil","addperfil","subperfil","rmperfil","inicio" };
	inicializa();

}

void Interface::inicializa() {
	entrada = &cin;

}
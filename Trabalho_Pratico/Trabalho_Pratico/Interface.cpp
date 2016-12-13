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
			//info.setDim(linha, coluna);
			Planicie p(linha, coluna);
			//cout << "Linha:" << linha << endl;
			//cout << "Coluna:" << coluna << endl;
		}
		else { cout << "Planicie ja criada!\n"; le_comandos(); }
	}
	if (comando == "moedas") {
		int n;
		iss >> n;
		info.setMoedas(n);
		//cout << "Moedas:" << n;
	}
	if (comando == "oponentes") {
		int n;
		iss >> n;
		info.setOponentes(n);
		//cout << "Oponentes:" << n;
	}
	if (comando == "castelo") {
		string colonia;
		int l, c;
		iss >> colonia;
		iss >> l >> c;
		cout << "Castelo da colonia:" << colonia << "para:" << l << ";" << c;
	}

	if (comando == "mkperfil") {
		char letra;
		iss >> letra;
		
		if (info.getNPerfil() >= MAX_PERFIS) {
			cout << "Ja foram criados os 5 Perfis!\n";
		}
		else {
			info.adicionaNPerfil();
			p->criaPerfil(letra); //Põe o Perfil no vetor Perfis
			cout << "Perfil " << letra << " criado c/ sucesso!\n";
		}
	}
	if (comando == "addperfil") {
		char l;
		int c;
		iss >> l;
		iss >> c;
		Perfil *aux;

		aux = p->procuraPerfil(l);
		aux->adicionaCaracteristicaNoPerfil(c);
		cout << "Adicionar a " << l << "caracteristica" << c;
	}
	if (comando == "subperfil") {
		char l;
		int c;
		iss >> l;
		iss >> c;
		Perfil *aux;

		aux = p->procuraPerfil(l);
		aux->removeCaracteristicaNoPerfil(c);
		cout << "Remove a " << l << " a caracteristica" << c;
	}
	if (comando == "rmperfil") {
		char l;
		iss >> l;
		cout << "Abandonar perfil:" << l;
		Perfil *aux;

		aux = p->procuraPerfil(l);
		aux->~Perfil();
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
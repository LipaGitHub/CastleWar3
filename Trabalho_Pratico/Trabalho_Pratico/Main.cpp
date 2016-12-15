#include <iostream>
#include "Planicie.h"
#include "Interface.h"
#include"Consola.h"
#define CONFIGURACAO 0
#define SIMULACAO 1
using namespace std;


int main() {
	
	Consola::setTextColor(Consola::VERDE_CLARO);
	Consola::setTextSize(14, 14);
	Consola::setScreenSize(30, 80);
	Consola::gotoxy(10,2);
	cout << " _         _"
		 <<	"| | _____ | | ____________"
		<<	"| | _____ | | _____________\\"
		<<	"| | _____ | | _____________/"
		<<	"|_|       |_|";

	Consola::gotoxy(10, 10);
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
	Consola::gotoxy(10, 11);
	cout << "---------------Bem Vindo Ao Castle War-----------------" << endl;
	Consola::gotoxy(10, 13);
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
	Consola::gotoxy(10, 15);
	cout << endl;
	Consola::gotoxy(10, 17);
	cout << "Carrega numa tecla para continuar...";
	Consola::getch();
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::setTextColor(Consola::VERDE_CLARO);
	Consola::setScreenSize(50,100);
	Consola::clrscr();
	
	


	
	Interface f;
	
	//Fase da Configuração
	f.le_comandos(CONFIGURACAO);

	//Impressão Mapa
	Consola::gotoxy(0, 0);
	cout << "Configuracao terminada!\n\n\n";
	cout << "Mapa:\n";
	f.Mapa();
	Consola::gotoxy(50, 99);
	cout << "Carrega numa tecla para continuar...";
	Consola::getch();

	//Fase da Simulação
	f.le_comandos(SIMULACAO);

	return 0;
}
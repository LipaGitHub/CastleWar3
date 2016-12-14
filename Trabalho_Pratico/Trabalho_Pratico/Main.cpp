#include <iostream>
#include "Planicie.h"
#include "Interface.h"
#include"Consola.h"
using namespace std;

int main() {
	
	Consola::setTextColor(Consola::VERDE_CLARO);
	Consola::setTextSize(14, 14);
	Consola::setScreenSize(30, 80);
	Consola::gotoxy(10, 10);
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
	Consola::gotoxy(10, 11);
	cout << "---------------Bem Vindo Ao Castle War-----------------" << endl;
	Consola::gotoxy(10, 13);
	cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
	Consola::gotoxy(10, 15);
	cout << endl;
	Consola::gotoxy(10, 17);
	cout << "Carrega numa tecla para continuar";
	Consola::getch();
	Consola::setBackgroundColor(Consola::CINZENTO);  // favor consultar o .h para ver as constantes
	Consola::setTextColor(Consola::PRETO);
	Consola::setScreenSize(50,100);
	Consola::clrscr();
	
	


	
	Interface f;
	
	//Fase da Configuração
	f.le_comandos();

	//Impressão Mapa
	f.Mapa();
	//Fase da Simulação
	cout << "Fase da Simulacao...";

	return 0;
}
#ifndef CONFIG_H
#define CONFIG_H
#include "Colonia.h"
class Config {
	int linhas, colunas, moedas, oponentes, n_perfis;
public:
	Config();
	void setDim(int l, int c);
	int getDimLinhas();
	int getDimColunas();
	void setMoedas(int moedas);
	int getOponentes();
	int adicionaNPerfil();
	int getNPerfil();
	void criaColonias();
};

#endif
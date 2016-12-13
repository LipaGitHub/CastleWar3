#pragma once
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
	void setOponentes(int oponentes);
	int adicionaNPerfil();
	int getNPerfil();
	void criaColonias();
};
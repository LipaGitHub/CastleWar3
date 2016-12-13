#pragma once
#include "Colonia.h"
class Config {
	int linhas, colunas, moedas, oponentes, n_perfis;
public:
	Config() {
		this->linhas = 0;
		this->colunas = 0;
		this->moedas = 0;
		this->oponentes = 1;
		this->n_perfis = 0;
	}
	void setDim(int l, int c) {
		this->linhas = l;
		this->colunas = c;
	}
	int getDimLinhas() {
		return linhas;
	}
	int getDimColunas() {
		return colunas;
	}
	void setMoedas(int moedas) {
		this->moedas = moedas;
	}
	int getOponentes() {
		return oponentes;
	}
	
	int adicionaNPerfil() {
		return ++n_perfis;
	}
	int getNPerfil() {
		return n_perfis;
	}
	void criaColonias() {
		//Falta implementar
	}
};
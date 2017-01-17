#include "Config.h"

Config::Config() {
	this->linhas = 0;
	this->colunas = 0;
	this->moedas = 0;
	this->oponentes = 1;
	this->n_perfis = 0;
}
void Config::setDim(int l, int c) {
	this->linhas = l;
	this->colunas = c;
}
int Config::getDimLinhas() {
	return linhas;
}
int Config::getDimColunas() {
	return colunas;
}
void Config::setMoedas(int moedas) {
	this->moedas = moedas;
}
int Config::getOponentes() {
	return oponentes;
}

int Config::adicionaNPerfil() {
	return ++n_perfis;
}
int Config::getNPerfil() {
	return n_perfis;
}
void Config::criaColonias() {
	//Falta implementar
}
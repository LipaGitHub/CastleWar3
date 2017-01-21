#include "Edificios.h"
#include "Personagem.h"

Edificio::Edificio(string n, char sigla, int c, int s, int d, int x, int y) : Personagem(sigla, c, s, d, x, y) {
	this->nome = n;
	
}
Castelo::Castelo(int x, int y):Edificio("Castelo", 'C', 0, 50, 10, x, y) {}

Quinta::Quinta(int x, int y):Edificio("Quinta", 'Q', 30, 20, 10, x,y) {}

Torre::Torre(int x, int y):Edificio("Torre", 'T', 20, 20, 10, x,y) {}

#include "Edificios.h"
#include "Personagem.h"

Edificio::Edificio(string n, char sigla, int c, int s, int d) : Personagem(sigla, c, s, d) {
	this->nome = n;
	
}
Castelo::Castelo():Edificio("Castelo", 'C', 0, 50, 10) {}

Quinta::Quinta():Edificio("Quinta", 'Q', 30, 20, 10) {}

Torre::Torre():Edificio("Torre", 'T', 20, 20, 10) {}

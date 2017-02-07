#include "Recurso.h"

int Recurso::n_fonte = 1;

Recurso::Recurso(){}
Recurso::~Recurso(){}

Recurso::Recurso(string name, int n)
{
	nome = name;
	transform(nome.begin(), nome.end(), nome.begin(), ::toupper);
	quantidade = n;

	ostringstream os;
	if (n_fonte >= 10)
		os << "R" << n_fonte++;
	else
		os << "R" << "0" << n_fonte++;
	id_fonte = os.str();
}

string Recurso::getNome(){ return nome; }
string Recurso::getIdFonte(){ return id_fonte; }
int Recurso::getQuant(){ return quantidade; }
void Recurso::decrementaQuantidade(int quant){
	this->quantidade -= quant;
}
#include "Populacao.h"

int Populacao::nJog = 0;

Populacao::Populacao(string n)
{
	Ouro = 150;
	Pedra = 200;
	Madeira = 500;

	nJog++;
	idJog = nJog;
	nome = n;
}

Populacao::~Populacao()
{
	for (unsigned int i = 0; i<u.size(); i++){
		if (u[i] != NULL) /// .....
			delete u[i];
	}
	u.clear();

	for (unsigned int i = 0; i<e.size(); i++){
		if (e[i] != NULL)  // ....
			delete e[i];
	}
	e.clear();
}

string Populacao::getNome() const{
	return nome;
}

void Populacao::AdicionaEdificio(Edificio *ob){
	e.push_back(ob);
}

void Populacao::AdicionaUnidade(Unidade *uni){
	u.push_back(uni);
}

void Populacao::removeUnidade(string uniId){
	for (size_t i = 0; i < u.size(); i++){
		if (u[i]->getNomeUnidade() == uniId){
			if (u.size() == 1)
				u.clear();
			else{
				delete u[i];
				//u.erase(u.begin() + i);
				break;
			}
		}
	}
}

int Populacao::getIdJogador()const{
	return idJog;
}

Edificio * Populacao::getEdificioByIndex(int i){
	return e[i];
}

Unidade * Populacao::getUnidadeByIndex(int i){
	return u[i];
}

int Populacao::getNumEdificios(){
	return e.size();
}

int Populacao::getNumUnidades(){
	return u.size();
}

void Populacao::addOuro(int o){
	this->Ouro += o;
}
void Populacao::addPedra(int p){
	this->Pedra += p;
}
void Populacao::addMadeira(int m){
	this->Madeira += m;
}

void Populacao::setOuro(int o){
	this->Ouro = o;
}
void Populacao::setPedra(int p){
	this->Pedra = p;
}
void Populacao::setMadeira(int m){
	this->Madeira = m;
}

int Populacao::getOuro(){
	return Ouro;
}
int Populacao::getPedra(){
	return Pedra;
}
int Populacao::getMadeira(){
	return Madeira;
}
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Edificio.h"
#include "Unidade.h"

using namespace std;

#ifndef POPULACAO_H
#define POPULACAO_H
class Populacao
{
	string nome;
	static int nJog;
	int idJog;
	vector<Edificio*> e;
	vector<Unidade*> u;

	int Ouro;
	int Pedra;
	int Madeira;

public:
	Populacao(string n);
	~Populacao();

	//gets
	int getIdJogador()const;
	string getNome()const;

	//adicionar a pop
	void AdicionaEdificio(Edificio *ob);
	void AdicionaUnidade(Unidade *uni);
	void removeUnidade(string uniId);

	Edificio * getEdificioByIndex(int i);
	Unidade * getUnidadeByIndex(int i);

	int getNumEdificios();
	int getNumUnidades();

	void addOuro(int o);
	void addPedra(int p);
	void addMadeira(int m);
	void setOuro(int o);
	void setPedra(int p);
	void setMadeira(int m);

	int getOuro();
	int getPedra();
	int getMadeira();
};
#endif
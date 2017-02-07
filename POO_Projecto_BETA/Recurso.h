#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

#ifndef RECURSO_H
#define RECURSO_H
class Recurso
{
	string nome;
	string id_fonte;
	int quantidade;
	
public:
	static int n_fonte;
	Recurso();
	Recurso(string nome, int n);
	~Recurso();
	string getIdFonte();
	string getNome();
	int getQuant();
	void decrementaQuantidade(int quant);
};
#endif
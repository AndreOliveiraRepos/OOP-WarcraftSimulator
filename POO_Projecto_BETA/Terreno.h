#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ostream>
#include "Edificio.h"
#include "Unidade.h"
#include "Recurso.h"
#include "Consola.h"

using namespace std;

#ifndef TERRENO_H
#define TERRENO_H
class Terreno{

	bool visivel;

	Recurso *recurso = NULL;	//no inicio nao tem recurso
	Edificio *edificio = NULL; //no inicio nao tem edificio
	vector<Unidade*> unidades;
	
public:

	Terreno();
	~Terreno();

	void AdicionarEdificio(Edificio *e);
	void AdicionarUnidade(Unidade *u);
	void AdicionarRecurso(Recurso *r);
	void setVisible(bool visibility);

	Recurso * getRecurso();
	Edificio * getEdificio();
	Unidade * getUnidadeByID(string id);
	Unidade * getUnidadeByIndex(int index);
	int getNumUnidades();

	void imprimeTerreno(int margin_left, int margin_top);
	void removeUnidade(int i);
	void removeUnidadeById(string id);
	void removeRecurso();
	void removeEdificio();
};
#endif
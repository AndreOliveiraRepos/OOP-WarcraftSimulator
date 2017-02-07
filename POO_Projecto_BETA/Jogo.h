#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "Edificio.h"
#include "Consola.h"
#include "Unidade.h"
#include "Terreno.h"
#include "Populacao.h"
#include "AI.h"

#define ANDAR  0
#define MINAR  1
#define ATACAR 2
#define CONTRA_ATACAR 3
#define REPARAR 4
#define DEAMBULAR 5
#define CONSTRUIR 6

#define CAMPONES 0
#define CAMPONESCAVALO 1
#define SOLDADO 2
#define CAVALEIRO 3

class Jogo{
	vector<Populacao*> Pop;
	vector<AI> intel;
	int NumJogadores;
	
	int n_lin, n_col;
	int currX, currY;
	string lastNotification;
	string lastSelectedItem;
	int lastSelectedItemX;
	int lastSelectedItemY;
	Unidade* encontraUnidade(string unitName);

public:
	vector<vector<Terreno>> Mapa;
	//raio de visão do scroll
	const static int offset = 4;
	const static int width_info_box = 15;
	const static int res_default_value = 60;

	Jogo();
	~Jogo();

	void iterar();

	void drawInterface();
	void drawMap(int &x, int &y);
	void drawWrapper();
	void drawInfoXY(int offset);
	void drawGameContents(string pop);

	string getLastNotification();

	void notificar(string str);
	void readFile(string filename);
	void verificaComando(string cmd);
	void processaComando(int _cmd, string param1, string param2, int x, int y);
	Terreno * getTerreno(int x, int y);
	int encontraPopulacao(string id) const;
	void registaPopulacao(Populacao *p);
	void GerarMapa(int x);
};
#endif
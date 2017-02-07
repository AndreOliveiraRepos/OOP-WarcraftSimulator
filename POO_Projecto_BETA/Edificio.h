#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define CAMPONES 0
#define CAMPONESCAVALO 1
#define SOLDADO 2
#define CAVALEIRO 3

using namespace std;

class Terreno;
class Populacao;

class Edificio{
protected:
	string tipo;
	string nome;
	int nJog;			   //num jogador
	int eID;			   //unico para o tipo

	//custo
	int Madeira;
	int Pedra;
	int Ouro;

	//saude
	int Estado;
	int maxHp;
	bool unitQueue;
	int unitType;
	
public:
	static int edificioID; //unico para todos os tipos
	Edificio();
	~Edificio();
	Edificio(const Edificio & ob);

	int getEstado()const;
	int getMaxHp()const;
	bool getUnitQueue()const;

	int getnJog()const;
	int  getEdificioID()const;
	string getTipoEdificio()const;
	string getNomeEdificio()const;

	//sets
	void setID(int i);
	void setNome(string n);
	void setEstado(int s);
	void setnJog(int idJog);
	void setUnitQueue(bool UnitInQueue);
	void setUnitTypeOnQueue(int theType);
	
	virtual void recruta(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop) = 0;
};

class Castelo :public Edificio
{
	const int MADEIRA = 100;
	const int PEDRA   = 100;
	const int OURO    = 100;
	const int ESTADO  = 200;

public:
	static int casteloID;
	Castelo();
	void recruta(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop);
};

class Quartel :public Edificio
{
	const int MADEIRA = 100;
	const int PEDRA   = 100;
	const int OURO    = 100;
	const int ESTADO  = 100;

public:
	static int quartelID;
	Quartel();
	void recruta(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop);
};

class Estabulo :public Edificio
{
	const int MADEIRA = 100;
	const int PEDRA   = 100;
	const int OURO    = 100;
	const int ESTADO  = 120;

public:
	static int estabuloID;
	Estabulo();
	void recruta(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop);
};

class Quinta :public Edificio
{
	const int MADEIRA = 100;
	const int PEDRA   = 100;
	const int OURO    = 100;
	const int ESTADO  = 80;

public:
	static int quintaID;
	Quinta();
	void recruta(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop);
};
#endif
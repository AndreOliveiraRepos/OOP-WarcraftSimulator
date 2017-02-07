#ifndef UNIDADE_H
#define UNIDADE_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Terreno;
class Populacao;

using namespace std;

class Unidade{
protected: //as restantes classes herdam estas propriedades
	int uID;
	string nome;
	string tipo;
	int nJog;
	bool hasStamina;

	//custo
	int Madeira;
	int Pedra;
	int Ouro;
	int Saude;
	int Capacidade;
	int Velocidade;

	//movimento
	int targetX; //localizaçao alvo
	int targetY;

	int carga;
	int ultimaOrdem;
	string actionTargetId;

	int Ataque;
	int Defesa;

public:
	static int unidadeID;
	Unidade();
	Unidade(const Unidade & ob);//copia

	void movimentar(vector<vector<Terreno>>& mapa, int currY, int currX);
	void deambular(int limX, int limY);

	virtual void resposta_ataque(Unidade &atacante, vector<vector<Terreno>>& mapa) = 0;
	void revealMap(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX);

	virtual void atacar(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX, Populacao* &pop);
	virtual void patrol(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX);

	virtual void minar(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX, Populacao* &pop);
	virtual void reparar(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX, Populacao* &pop);
	virtual void construir(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop);
	
	//gets
	int getCustoMadeira() const;
	int getCustoPedra() const;
	int getCustoOuro() const;

	int getUnidadeID()const;
	int getnJog() const;
	string getNomeUnidade()const;
	string getTipoUnidade()const;
	int getSaude()const;
	int getcapacidade()const;
	int getvelocidade()const;
	bool getStamina()const;
	int getTarX() const;
	int getTarY() const;
	int getOrdem() const;
	int getAtaque() const;
	int getDefesa() const;

	//sets
	void setIDUnidade(int i);
	void setnJog(int njog);
	void setNome(string n);
	void setSaude(int s);
	void setcapacidade(int c);
	void setvelocidade(int v);
	void setStamina(bool stamina);
	void setTarX(int x);
	void setTarY(int y);
	void setActionTargetId(string id);
	void setOrdem(int ordem);
	void setDefesa(int defesa);
	void setAtaque(int ataque);
};

class Campones :public Unidade 
{
	const int MADEIRA = 10;
	const int PEDRA   = 0;
	const int OURO    = 5;
	const int SAUDE   = 20;
	const int CAPACIDADE = 5;
	const int VELOCIDADE = 1;
	const int ATAQUE = 0;
	const int DEFESA = 0;

public:
	static int camponesID;
	Campones();
	void atacar();
	void patrol();
	void resposta_ataque(Unidade &atacante, vector<vector<Terreno>>& mapa);
};

class Soldado :public Unidade 
{
	const int MADEIRA = 10;
	const int PEDRA   = 0;
	const int OURO    = 10;
	const int SAUDE   = 40;
	const int CAPACIDADE = 0;
	const int VELOCIDADE = 2;
	const int ATAQUE	 = 5;
	const int DEFESA	 = 20;

public:
	static int soldadoID;
	Soldado();
	void construir();
	void reparar();
	void minar();
	void resposta_ataque(Unidade &atacante, vector<vector<Terreno>>& mapa);
};

class Cavaleiro :public Unidade 
{
	const int MADEIRA = 20;
	const int PEDRA   = 5;
	const int OURO    = 10;
	const int SAUDE   = 60;
	const int CAPACIDADE = 0;
	const int VELOCIDADE = 2;
	const int ATAQUE	 = 8;
	const int DEFESA	 = 40;

public:
	static int cavaleiroID;
	Cavaleiro();
	void construir();
	void reparar();
	void minar();
	void resposta_ataque(Unidade &atacante, vector<vector<Terreno>>& mapa);
};

class CamponesCavalo :public Unidade 
{
	const int MADEIRA = 20;
	const int PEDRA   = 5;
	const int OURO    = 5;
	const int SAUDE   = 40;
	const int CAPACIDADE = 10;
	const int VELOCIDADE = 2;
	const int ATAQUE = 0;
	const int DEFESA = 0;

public:
	static int camponesCavaloID;
	CamponesCavalo();
	void atacar();
	void patrol();
	void resposta_ataque(Unidade &atacante, vector<vector<Terreno>>& mapa);
};
#endif
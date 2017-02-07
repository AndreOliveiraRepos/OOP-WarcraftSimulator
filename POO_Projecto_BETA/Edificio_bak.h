#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#ifndef EDIFICIO_H
#define EDIFICIO_H

class Edificio
{
protected:
	string tipo;
	string nome;

private:
	int nJog;
	//id & contagem
	static int edificioID;
	int eID;
	//custo
	int Madeira;
	int Pedra;
	int Ouro;
	//saude
	int Estado;
	
public:
	Edificio(){
		nJog = 0;

		eID = 0;
		nome = "";

		Madeira = 0;
		Pedra = 0;
		Ouro = 0;

		Estado = 0;

	}
	~Edificio();
	Edificio(const Edificio & ob);
	//gets
	int getMadeira()const;
	int getPedra()const;
	int getOuro()const;
	int getnJog()const;
	int getEstado()const;

	string getTipoEdificio()const;
	string getNomeEdificio()const;
	int  getEdificioID()const;

	//sets
	void setID(int i);
	void setNome(string n);
	void setMadeira(int m);
	void setPedra(int p);
	void setOuro(int o);
	void setEstado(int s);
	void setnJog(int idJog);

};

class Castelo :public Edificio
{
	const int Madeira = 100;
	const int Pedra = 100;
	const int Ouro = 100;

	const int Estado = 200;

	static int edificioID;

public:
	Castelo(){
		setID(edificioID);

		setMadeira(Madeira);
		setPedra(Pedra);
		setOuro(Ouro);

		setEstado(Estado);

		ostringstream os;
		if (edificioID >= 10)
			os << "C" << edificioID++;
		else
			os << "C" << "0" << edificioID++;
		nome = os.str();
		tipo = "CAS";
	}

	Castelo(const Castelo & ob);
};

class Quartel :public Edificio
{
	const int Madeira = 100;
	const int Pedra = 100;
	const int Ouro = 100;

	const int Estado = 200;

	static int edificioID;
	string nome;

public:
	Quartel(){
		setID(edificioID);
		edificioID++;
		setNome("Q");

		setMadeira(Madeira);
		setPedra(Pedra);
		setOuro(Ouro);

		setEstado(Estado);
	}

	Quartel(const Quartel & ob);
};



class Estabulo :public Edificio
{
	const int Madeira = 100;
	const int Pedra = 100;
	const int Ouro = 100;

	const int Estado = 200;

	static int edificioID;
	string nome;


public:
	Estabulo(){
		setID(edificioID);
		edificioID++;
		setNome("E");

		setMadeira(Madeira);
		setPedra(Pedra);
		setOuro(Ouro);

		setEstado(Estado);
	}

	Estabulo(const Estabulo & ob);

};

class Quinta :public Edificio
{
	const int Madeira = 100;
	const int Pedra = 100;
	const int Ouro = 100;

	const int Estado = 200;

	static int edificioID;
	string nome;


public:
	Quinta(){
		setID(edificioID);
		edificioID++;
		setNome("F");

		setMadeira(Madeira);
		setPedra(Pedra);
		setOuro(Ouro);

		setEstado(Estado);

	}

	Quinta(const Quinta & ob);

};

int Edificio::edificioID = 1;

int Quartel::edificioID = 1;
int Castelo::edificioID = 1;
int Quinta::edificioID = 1;
int Estabulo::edificioID = 1;

Edificio::~Edificio(){}

Edificio::Edificio(const Edificio & ob){
	//edificioID++;
	Madeira = ob.Madeira;
	Pedra = ob.Pedra;
	Ouro = ob.Ouro;

	eID = ob.eID;
	nome = ob.nome;

	Estado = ob.Estado;
}

//custo de recurso
int Edificio::getMadeira()const{ return Madeira; }
int Edificio::getPedra()const{ return Pedra; }
int Edificio::getOuro()const{ return Ouro; }

//identficações

int  Edificio::getEdificioID()const{ return edificioID; }
string Edificio::getNomeEdificio()const{ return nome; }
string Edificio::getTipoEdificio()const{ return tipo;  }

//propriedades gets e sets
int Edificio::getEstado()const{ return Estado; }
int Edificio::getnJog()const{ return nJog; }

void Edificio::setNome(string n){ nome = n; }
void Edificio::setMadeira(int m){ Madeira = m; }
void Edificio::setPedra(int p){ Pedra = p; }
void Edificio::setOuro(int o){ Ouro = o; }
void Edificio::setEstado(int s){ Estado = s; }
void Edificio::setID(int i){ eID = i; }
void Edificio::setnJog(int idJog){ nJog = idJog; }

#endif
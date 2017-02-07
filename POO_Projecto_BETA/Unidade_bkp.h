#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <array>
#include "Edificio.h"

using namespace std;

#ifndef UNIDADE_H
#define UNIDADE_H

//NOTA: falta definir a unidade misterio, a capacidade, ataque, defesa e velocidade;

class Unidade{
	int nJog;
	//id & contagem
	static int unidadeID;
	int uID;
	string nome;
	//custo
	int Madeira;
	int Pedra;
	int Ouro;
	//saude
	int Saude;
	//transporte
	int Capacidade;
	int Velocidade;

public:
	//Unidade(int np,int uID,string n, int m, int p, int o, int s, int cap, int vel) :nJog(np),unidadeID(uID),nome(n),Madeira(m),Pedra(p),Ouro(o),Saude(s),Capacidade(cap),Velocidade(vel){}
	Unidade(){//predefinido
		nJog = 0;
		
		uID = 0;
		nome = "";
		
		Madeira = 0;
		Pedra = 0;
		Ouro = 0;
		
		Saude = 0;
		
		Capacidade = 0;
		Velocidade = 0;
	}

	Unidade(const Unidade & ob);//copia
	
	//gets
	int getMadeira()const;
	int getPedra()const;
	int getOuro()const;

	int getSaude()const;
	int getcapacidade()const;
	int getvelocidade()const;

	
	int  getUnidadeID()const;
	string getNomeUnidade()const;
	
	/*void setUnidadeMatrizX(int x);
	void setUnidadeMatrizY(int y);
	void setUnidadeEcraX(int x);
	void setUnidadeEcraY(int y);*/

	//sets
	void setIDUnidade(int i);
	void setNome(string n);
	void setMadeira(int m);
	void setPedra(int p);
	void setOuro(int o);

	void setSaude(int s);
	void setcapacidade(int c);
	void setvelocidade(int v);
protected:
	string tipo;

};

//define o campones derivado da unidade
class Campones :public Unidade 
{
	const int Madeira = 10;
	const int Pedra = 0;
	const int Ouro = 5;

	const int Saude = 20;
	int uID;
	static int unidadeID;
	string nome;


public:
	Campones(){ 
		//uID = unidadeID;
		setIDUnidade(unidadeID);
		unidadeID++;
		setNome("C");

		setMadeira(Madeira);		
		setPedra(Pedra);
		setOuro(Ouro);

		setSaude(Saude);
		setcapacidade(0);
		setvelocidade(0);
		
	}

	Campones(const Campones & ob);

	int getMadeira();
	int getPedra();
	int getOuro();
	int getSaude();

	
	int getUnidadeID();
	string getNomeUnidade();

};
int Campones::unidadeID = 0;
//int Campones::camponesID = 1;
//define o Soldado derivado da unidade
class Soldado :public Unidade 
{
	const int Madeira = 10;
	const int Pedra = 0;
	const int Ouro = 10;

	const int Saude = 40;

	static int soldadoID;
	string nome;

public:
	Soldado(){ 
		setIDUnidade(soldadoID);
		soldadoID++;

		setMadeira(Madeira);
		setPedra(Pedra);
		setOuro(Ouro);

		setSaude(Saude);
		setcapacidade(0);
		setvelocidade(0);

		ostringstream os;
		if (soldadoID >= 10)
			os << "S" << soldadoID++;
		else
			os << "S" << "0" << soldadoID++;
		setNome(os.str());
		tipo = "SOL";
	}
	Soldado(const Soldado & ob);

	int getMadeira();
	int getPedra();
	int getOuro();
	int getSaude();

	int  getUnidadeID();
	string getNomeUnidade();
};
int Soldado::unidadeID = 1;

//define o Cavaleiro
class Cavaleiro :public Unidade 
{
	const int Madeira = 20;
	const int Pedra = 5;
	const int Ouro = 10;

	const int Saude = 60;

	static int unidadeID;
	string nome;
	

public:
	Cavaleiro(){ 

		setIDUnidade(unidadeID);
		unidadeID++;
		
		setNome("CV");

		setMadeira(Madeira);
		setPedra(Pedra);
		setOuro(Ouro);

		setSaude(Saude);
		setcapacidade(0);
		setvelocidade(0);
	}
	Cavaleiro(const Cavaleiro & ob);

	

	int getMadeira();
	int getPedra();
	int getOuro();
	int getSaude();

	int  getUnidadeID();
	string getNomeUnidade();
};
int Cavaleiro::unidadeID = 0;

//define o CamponesCavalo
class CamponesCavalo :public Unidade 
{
	const int Madeira = 20;
	const int Pedra = 5;
	const int Ouro = 5;

	const int Saude = 40;

	static int unidadeID;
	string nome;
	


public:
	CamponesCavalo(){
		setIDUnidade(unidadeID);
		unidadeID++;
		setNome("CC");

		setMadeira(Madeira);
		setPedra(Pedra);
		setOuro(Ouro);

		setSaude(Saude);
		setcapacidade(0);
		setvelocidade(0);
		
	}
	CamponesCavalo(const CamponesCavalo & ob);

	

	int getMadeira();
	int getPedra();
	int getOuro();
	int getSaude();

	int  getUnidadeID();
	string getNomeUnidade();
};
int CamponesCavalo::unidadeID = 0;
int Unidade::unidadeID = 0;
Unidade::Unidade(const Unidade & ob){

	Unidade::unidadeID++;
	Madeira = ob.Madeira;
	Pedra = ob.Pedra;
	Ouro = ob.Ouro;

	uID = ob.uID;
	nome = ob.nome;

	Saude = ob.Saude;

	Capacidade = ob.Capacidade;
	Velocidade = ob.Velocidade;
}

//custo de recurso
int Unidade::getMadeira()const{ return Madeira; }
int Unidade::getPedra()const{ return Pedra; }
int Unidade::getOuro()const{ return Ouro; }

//identficações
int  Unidade::getUnidadeID()const{ return uID; }
string Unidade::getNomeUnidade()const{ return nome; }

//propriedades gets e sets
int Unidade::getSaude()const{ return Saude; }
int Unidade::getcapacidade()const{ return Capacidade; }
int Unidade::getvelocidade()const{ return Velocidade; }

void Unidade::setNome(string n){ nome = n; }
void Unidade::setMadeira(int m){ Madeira = m; }
void Unidade::setPedra(int p){ Pedra = p; }
void Unidade::setOuro(int o){ Ouro = o; }

void Unidade::setSaude(int s){ Saude = Saude; }
void Unidade::setcapacidade(int c){ Capacidade = Capacidade; }
void Unidade::setvelocidade(int v){ Velocidade = Velocidade; }
void Unidade::setIDUnidade(int i){ uID = i; }



#endif
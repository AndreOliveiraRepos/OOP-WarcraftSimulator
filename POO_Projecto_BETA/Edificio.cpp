#include "Edificio.h"
#include "Populacao.h"
#include "Terreno.h"

int Edificio::edificioID = 0;

int Castelo::casteloID = 1;
int Quartel::quartelID = 1;
int Estabulo::estabuloID = 1;
int Quinta::quintaID = 1;

Edificio::Edificio(){
	unitQueue = false;
}
Edificio::~Edificio(){}

Edificio::Edificio(const Edificio & ob){
	edificioID++;
	Madeira = ob.Madeira;
	Pedra = ob.Pedra;
	Ouro = ob.Ouro;

	eID = ob.eID;
	nome = ob.nome;

	Estado = ob.Estado;
}

Castelo::Castelo(){
	eID = casteloID;
	edificioID++;

	Madeira = MADEIRA;
	Pedra   = PEDRA;
	Ouro    = OURO;
	Estado  = ESTADO;

	ostringstream os;
	if (casteloID >= 10)
		os << "C" << casteloID++;
	else
		os << "C" << "0" << casteloID++;
	nome = os.str();
	tipo = "CAS";
}

Quartel::Quartel(){
	eID = quartelID;
	edificioID++;

	Madeira = MADEIRA;
	Pedra   = PEDRA;
	Ouro    = OURO;
	Estado  = ESTADO;

	ostringstream os;
	if (quartelID >= 10)
		os << "Q" << quartelID++;
	else
		os << "Q" << "0" << quartelID++;
	nome = os.str();
	tipo = "QUA";
}

Estabulo::Estabulo(){
	eID = estabuloID;
	edificioID++;

	Madeira = MADEIRA;
	Pedra   = PEDRA;
	Ouro    = OURO;
	Estado  = ESTADO;

	ostringstream os;
	if (estabuloID >= 10)
		os << "E" << estabuloID++;
	else
		os << "E" << "0" << estabuloID++;
	nome = os.str();
	tipo = "EST";
}

Quinta::Quinta(){
	eID = quintaID;
	edificioID++;

	Madeira = MADEIRA;
	Pedra   = PEDRA;
	Ouro    = OURO;
	Estado  = ESTADO;

	ostringstream os;
	if (quintaID >= 10)
		os << "F" << quintaID++;
	else
		os << "F" << "0" << quintaID++;
	nome = os.str();
	tipo = "QUI";
}

int  Edificio::getEdificioID()const{ return edificioID; }
string Edificio::getNomeEdificio()const{ return nome; }
string Edificio::getTipoEdificio()const{ return tipo; }
bool Edificio::getUnitQueue()const{ return unitQueue; }
int Edificio::getEstado()const	{ return Estado; }
int Edificio::getMaxHp()const	{ return maxHp;  }
int Edificio::getnJog()const	{ return nJog;   }

void Edificio::setNome(string n){ nome = n; }
void Edificio::setEstado(int s){ Estado = s; }
void Edificio::setID(int i){ eID = i; }
void Edificio::setnJog(int idJog){ nJog = idJog; }
void Edificio::setUnitQueue(bool UnitInQueue){ this->unitQueue = UnitInQueue; }
void Edificio::setUnitTypeOnQueue(int theType){ unitType = theType; }

void Castelo::recruta(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop){
	if (unitType == CAMPONES){
		Campones * _u = new Campones();

		if (pop->getMadeira() >= _u->getCustoMadeira()
			&& pop->getPedra() >= _u->getCustoPedra()
			&& pop->getOuro() >= _u->getCustoOuro()){

			_u->setnJog(pop->getIdJogador());
			pop->AdicionaUnidade(_u);
			mapa[currY][currX].AdicionarUnidade(_u);

			pop->setMadeira(pop->getMadeira() - _u->getCustoMadeira());
			pop->setPedra(pop->getPedra() - _u->getCustoPedra());
			pop->setOuro(pop->getOuro() - _u->getCustoOuro());
		}
	}
	unitQueue = false;
}
void Quartel::recruta(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop){
	if (unitType == SOLDADO){
		Soldado * _u = new Soldado();
		if (pop->getMadeira() >= _u->getCustoMadeira()
			&& pop->getPedra() >= _u->getCustoPedra()
			&& pop->getOuro() >= _u->getCustoOuro()){

			_u->setnJog(pop->getIdJogador());
			pop->AdicionaUnidade(_u);
			mapa[currY][currX].AdicionarUnidade(_u);

			pop->setMadeira(pop->getMadeira() - _u->getCustoMadeira());
			pop->setPedra(pop->getPedra() - _u->getCustoPedra());
			pop->setOuro(pop->getOuro() - _u->getCustoOuro());
		}
	}
	unitQueue = false;
}
void Estabulo::recruta(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop){
	if (unitType == CAMPONESCAVALO){
		CamponesCavalo* _u = new CamponesCavalo();
		if (pop->getMadeira() >= _u->getCustoMadeira()
			&& pop->getPedra() >= _u->getCustoPedra()
			&& pop->getOuro() >= _u->getCustoOuro()){

			_u->setnJog(pop->getIdJogador());
			pop->AdicionaUnidade(_u);
			mapa[currY][currX].AdicionarUnidade(_u);

			pop->setMadeira(pop->getMadeira() - _u->getCustoMadeira());
			pop->setPedra(pop->getPedra() - _u->getCustoPedra());
			pop->setOuro(pop->getOuro() - _u->getCustoOuro());
		}
	}
	else if (unitType == CAVALEIRO){
		Cavaleiro * _u = new Cavaleiro();
		if (pop->getMadeira() >= _u->getCustoMadeira()
			&& pop->getPedra() >= _u->getCustoPedra()
			&& pop->getOuro() >= _u->getCustoOuro()){

			_u->setnJog(pop->getIdJogador());
			pop->AdicionaUnidade(_u);
			mapa[currY][currX].AdicionarUnidade(_u);

			pop->setMadeira(pop->getMadeira() - _u->getCustoMadeira());
			pop->setPedra(pop->getPedra() - _u->getCustoPedra());
			pop->setOuro(pop->getOuro() - _u->getCustoOuro());
		}
	}
	unitQueue = false;
}
void Quinta::recruta(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop){
	cout << "Edificio sem capacidade de recrutar!" << endl;
}
#include "Unidade.h"
#include "Terreno.h"
#include "Populacao.h"

int Unidade::unidadeID = 0;
int Campones::camponesID = 1;
int Soldado::soldadoID = 1;
int Cavaleiro::cavaleiroID = 1;
int CamponesCavalo::camponesCavaloID = 1;

Unidade::Unidade(){
	targetX = -1;
	targetY = -1;
	hasStamina = true;
	carga = 0;
	ultimaOrdem = 0;
}

Unidade::Unidade(const Unidade & ob){

	++unidadeID;
	Madeira = ob.Madeira;
	Pedra = ob.Pedra;
	Ouro = ob.Ouro;

	uID = ob.uID;
	nome = ob.nome;

	Saude = ob.Saude;

	Capacidade = ob.Capacidade;
	Velocidade = ob.Velocidade;
}

Campones::Campones(){
	uID = camponesID;
	++unidadeID;

	Madeira = MADEIRA;
	Pedra   = PEDRA;
	Ouro    = OURO;
	Saude   = SAUDE;
	Capacidade = CAPACIDADE;
	Velocidade = VELOCIDADE;
	Ataque = ATAQUE;
	Defesa = DEFESA;

	ostringstream os;
	if (camponesID >= 10)
		os << "P" << camponesID++;
	else
		os << "P" << "0" << camponesID++;
	nome = os.str();
	tipo = "CMP";
}

Soldado::Soldado(){
	uID = soldadoID;
	++unidadeID;

	Madeira = MADEIRA;
	Pedra   = PEDRA;
	Ouro    = OURO;
	Saude   = SAUDE;
	Capacidade = CAPACIDADE;
	Velocidade = VELOCIDADE;
	Ataque	   = ATAQUE;
	Defesa	   = DEFESA;

	ostringstream os;
	if (soldadoID >= 10)
		os << "S" << soldadoID++;
	else
		os << "S" << "0" << soldadoID++;
	nome = os.str();
	tipo = "SOL";
}

Cavaleiro::Cavaleiro(){
	uID = cavaleiroID;
	++unidadeID;

	Madeira = MADEIRA;
	Pedra   = PEDRA;
	Ouro    = OURO;
	Saude   = SAUDE;
	Capacidade = CAPACIDADE;
	Velocidade = VELOCIDADE;
	Ataque = ATAQUE;
	Defesa = DEFESA;

	ostringstream os;
	if (cavaleiroID >= 10)
		os << "K" << cavaleiroID++;
	else
		os << "K" << "0" << cavaleiroID++;
	nome = os.str();
	tipo = "CAV";
}

CamponesCavalo::CamponesCavalo(){
	uID = camponesCavaloID;
	++unidadeID;

	Madeira = MADEIRA;
	Pedra   = PEDRA;
	Ouro    = OURO;
	Saude   = SAUDE;
	Capacidade = CAPACIDADE;
	Velocidade = VELOCIDADE;
	Ataque = ATAQUE;
	Defesa = DEFESA;

	ostringstream os;
	if (camponesCavaloID >= 10)
		os << "B" << camponesCavaloID++;
	else
		os << "B" << "0" << camponesCavaloID++;
	nome = os.str();
	tipo = "CCV";
}

/* gets */
int Unidade::getcapacidade()const{ return Capacidade; }
int Unidade::getvelocidade()const{ return Velocidade; }
int Unidade::getSaude()const     { return Saude;   }
int Unidade::getTarX() const     { return targetX; }
int Unidade::getTarY() const     { return targetY; }
int Unidade::getOrdem()const	 { return ultimaOrdem;}
int Unidade::getAtaque() const   { return Ataque; }
int Unidade::getDefesa() const	 { return Defesa; }
int Unidade::getUnidadeID()const { return uID; }
int Unidade::getnJog()const		 { return nJog; }
int Unidade::getCustoMadeira() const{ return Madeira; }
int Unidade::getCustoPedra() const	{ return Pedra;   }
int Unidade::getCustoOuro() const	{ return Ouro;    }
bool Unidade::getStamina() const	 { return hasStamina; }
string Unidade::getNomeUnidade()const{ return nome; }
string Unidade::getTipoUnidade()const{ return tipo; }

/* sets */
void Unidade::setIDUnidade(int i)	{ uID = i; }
void Unidade::setNome(string n)		{ nome = n;    }
void Unidade::setSaude(int s)		{ Saude = s;   }
void Unidade::setnJog(int njog)		{ nJog = njog; }
void Unidade::setcapacidade(int c)	{ Capacidade = c; }
void Unidade::setvelocidade(int v)	{ Velocidade = v; }
void Unidade::setTarX(int x)		{ this->targetX = x; }
void Unidade::setTarY(int y)		{ this->targetY = y; }
void Unidade::setAtaque(int ataque) { this->Ataque = ataque; }
void Unidade::setDefesa(int defesa) { this->Defesa = defesa; }
void Unidade::setOrdem(int ordem)   { this->ultimaOrdem = ordem; }
void Unidade::setStamina(bool stamina){ hasStamina = stamina; }
void Unidade::setActionTargetId(string id){ this->actionTargetId = id; }

void Unidade::reparar(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX, Populacao* &pop){
	Edificio* p;
	for (int i = 0; i < n_lin; i++){
		for (int j = 0; j < n_col; j++){
			if ((p = mapa[i][j].getEdificio()) != NULL && 
				p->getNomeEdificio() == this->actionTargetId){
				
				this->targetX = j;
				this->targetY = i;

				if (currY == i && currX == j){ //Se já chegou ao edifício
					if (pop->getOuro() > 0){
						//verificar se o edificio precisa de ser reparado
						if (p->getEstado() < p->getMaxHp()){
							pop->setOuro(pop->getOuro() - 1);

							//verificar se a capacidade de reparo não supera o estado máximo do edificio
							if (p->getEstado() + 10 <= p->getMaxHp()){ //caso geral
								p->setEstado(p->getEstado() + 10);
							}
							else {
								p->setEstado(p->getMaxHp());
							}
						}
					}
				} //endif - esta no local do edif
			}
		} //j
	} //i
}

void Unidade::atacar(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX, Populacao* &pop){
	Unidade * p;
	Edificio* e;

	for (int i = 0; i < n_lin; i++){
		for (int j = 0; j < n_col; j++){

			//se for uma unidade
			for (int k = 0; k < mapa[i][j].getNumUnidades(); k++){
				if ((p = mapa[i][j].getUnidadeByID(this->actionTargetId)) != NULL){

					//caso geral
					this->targetX = j;
					this->targetY = i;

					//se já chegou á posição do adversário
					if (this->targetX == currX && this->targetY == currY){

						//ataca
						p->setSaude(float(p->getSaude()) - ((float)this->Ataque) *  ((100 - float(p->getDefesa())) / 100));

						//A unidade alvo reage ao ataque...
						p->resposta_ataque(*this,mapa);
					}
				}
			}// for k unidades

			//verificar se o id alvo é um edificio
			if ((e = mapa[i][j].getEdificio()) != NULL 
				&& mapa[i][j].getEdificio()->getNomeEdificio() == this->actionTargetId){
				this->targetX = j;
				this->targetY = i;
				if (this->targetX == currX && this->targetY == currY){
					e->setEstado(e->getEstado() - this->Ataque);
				}
			}
		}
	}
}

void Unidade::movimentar(vector<vector<Terreno>> &mapa,int currY, int currX){
	int toX, toY;
	
	if ((targetX != -1 && targetX != currX) || (targetY != -1 && targetY != currY)){ //quer deslocar-se.
		toX = currX;
		toY = currY;

		for (int vel = 0; vel < Velocidade; vel++)
		{
			if (targetX > toX) ++toX;
			else if (targetX < toX) --toX;
			if (targetY > toY) ++toY;
			else if (targetY < toY) --toY;
		}

		this->hasStamina = false;
		mapa[toY][toX].AdicionarUnidade(this);
		mapa[currY][currX].removeUnidadeById(this->nome);
	}
}

void Unidade::deambular(int limX, int limY){

	int dir = rand() % 8; //obter uma direcção aleatória

	switch (dir)
	{
	case 0: //esquerda
		this->targetX -= this->Velocidade;
		break;
	case 1: //direita
		this->targetX += this->Velocidade;
		break;
	case 2: //cima
		this->targetY -= this->Velocidade;
		break;
	case 3: //baixo
		this->targetY += this->Velocidade;
		break;

	case 4: //diag sup esquerda
		this->targetY -= this->Velocidade;
		this->targetX -= this->Velocidade;
		break;
	case 5: //diag sup direita
		this->targetY -= this->Velocidade;
		this->targetX += this->Velocidade;
		break;
	case 6: //diag inf esquerda
		this->targetY += this->Velocidade;
		this->targetX -= this->Velocidade;
		break;
	case 7: //diag inf direita
		this->targetY += this->Velocidade;
		this->targetX += this->Velocidade;
		break;
	default:
		break;
	}
	if ((this->targetX < 0 || this->targetX >= limX) || (this->targetY < 0 || this->targetY >= limY))
		deambular(limX,limY);
}

void Unidade::minar(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX, Populacao* &pop){
	//idRec - id do recurso a minar
	int recX = -1, recY = -1; //cordenadas do recurso alvo
	int edfX, edfY; //cordenadas do edificio alvo

	bool _loop = true; //depositar e regressar?
	string tipoRecurso;

	for (int i = 0; i < n_lin; i++){
		for (int j = 0; j < n_col; j++){
			if (mapa[i][j].getRecurso() != NULL && mapa[i][j].getRecurso()->getIdFonte() == actionTargetId){ //quando encontrar recurso
				recX = j; 
				recY = i;
				tipoRecurso = mapa[i][j].getRecurso()->getNome();
			}
		}
	}

	ostringstream oss;
	if (this->nJog < 10)
		oss << "C0" << this->nJog;
	else
		oss << "C" << this->nJog;

	for (int i = 0; i < n_lin; i++){
		for (int j = 0; j < n_col; j++){
			if (mapa[i][j].getEdificio() != NULL && mapa[i][j].getEdificio()->getNomeEdificio() == oss.str()){
				edfX = j;
				edfY = i;
			}
		}
	}

	if (currX == recX && currY == recY){ //se está na mina

		if (mapa[recY][recX].getRecurso()->getQuant() > this->Capacidade)
			this->carga = this->Capacidade;
		else{
			this->carga = mapa[recY][recX].getRecurso()->getQuant();
			_loop = false;
		}

		mapa[recY][recX].getRecurso()->decrementaQuantidade(this->carga);
		if (_loop == false)
			mapa[recY][recX].removeRecurso();

		this->targetX = edfX;
		this->targetY = edfY;
	}

	else if (currX == edfX && currY == edfY){ //se está no castelo
		if (tipoRecurso == "MIN")
			pop->addOuro(this->carga);
		else if (tipoRecurso == "PED")
			pop->addPedra(this->carga);
		else if (tipoRecurso == "FLO")
			pop->addMadeira(this->carga);
		this->carga = 0;

		//verificar se o recurso ainda existe, então volta a minar
		if (_loop == true){
			this->targetX = recX;
			this->targetY = recY;
		}
		else {
			this->setOrdem(0);
		}
	}				
	else {
		if (this->carga > 0){
			this->targetX = edfX;
			this->targetY = edfY;
		}
		else {
			this->targetX = recX;
			this->targetY = recY;
		}
	}
}

void Unidade::construir(vector<vector<Terreno>>& mapa, int currY, int currX, Populacao* &pop){

	//verifica se já chegou á posição alvo
	if (this->targetX == currX && this->targetY == currY){
		//verifica se já existe algum recurso ou edificio na posição alvo
		if (mapa[this->targetX][this->targetY].getEdificio() == NULL
			&& mapa[this->targetX][this->targetY].getRecurso() == NULL){
			//verifica se a população tem os recursos necessários

			if (this->actionTargetId == "cas"){
				Castelo * _e = new Castelo();
				_e->setnJog(pop->getIdJogador());
				pop->AdicionaEdificio(_e);
				mapa[this->targetX][this->targetY].AdicionarEdificio(_e);
			}
			else if (this->actionTargetId == "qua"){
				Quartel * _e = new Quartel();
				_e->setnJog(pop->getIdJogador());
				pop->AdicionaEdificio(_e);
				mapa[this->targetX][this->targetY].AdicionarEdificio(_e);
			}
			else if(this->actionTargetId == "est"){
				Estabulo * _e = new Estabulo();
				_e->setnJog(pop->getIdJogador());
				pop->AdicionaEdificio(_e);
				mapa[this->targetX][this->targetY].AdicionarEdificio(_e);
			}
			else if (this->actionTargetId == "qui"){
				Quinta * _e = new Quinta();
				_e->setnJog(pop->getIdJogador());
				pop->AdicionaEdificio(_e);
				mapa[this->targetX][this->targetY].AdicionarEdificio(_e);
			}
			else cout << "Erro!";
		}
	}
}

void Campones::resposta_ataque(Unidade &atacante, vector<vector<Terreno>>& mapa){
	ostringstream oss;
	if (this->nJog < 10)
		oss << "C0" << this->nJog;
	else
		oss << "C" << this->nJog;

	for (int i = 0; i < mapa.size(); i++){
		for (int j = 0; j < mapa[i].size(); j++){
			if (mapa[i][j].getEdificio() != NULL 
				&& mapa[i][j].getEdificio()->getNomeEdificio() == oss.str()){
				this->targetX = i;
				this->targetY = j;
				this->ultimaOrdem = 0;
			}
		}
	}
}

void CamponesCavalo::resposta_ataque(Unidade &atacante, vector<vector<Terreno>>& mapa){
	ostringstream oss;
	if (this->nJog < 10)
		oss << "C0" << this->nJog;
	else
		oss << "C" << this->nJog;

	for (int i = 0; i < mapa.size(); i++){
		for (int j = 0; j < mapa[i].size(); j++){
			if (mapa[i][j].getEdificio() != NULL
				&& mapa[i][j].getEdificio()->getNomeEdificio() == oss.str()){
				this->targetX = i;
				this->targetY = j;
				this->ultimaOrdem = 0;
			}
		}
	}
}

void Soldado::resposta_ataque(Unidade &atacante, vector<vector<Terreno>>& mapa){
	//Interrompe o que estava a fazer para reagir ao ataque
	this->targetX = -1;
	this->targetY = -1;
	this->ultimaOrdem = 3; //CONTRA_ATACAR
	atacante.setSaude(
		float(atacante.getSaude()) -
		((float)this->Ataque) *  ((100 - float(atacante.getDefesa())) / 100)
		);
}

void Cavaleiro::resposta_ataque(Unidade &atacante, vector<vector<Terreno>>& mapa){
	//Interrompe o que estava a fazer para reagir ao ataque
	this->targetX = -1;
	this->targetY = -1;
	this->ultimaOrdem = 3; //CONTRA_ATACAR
	atacante.setSaude(
		float(atacante.getSaude()) -
		((float)this->Ataque) *  ((100 - float(atacante.getDefesa())) / 100)
		);
}

void Unidade::patrol(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX){
	int offset = 2;
	for (int i = (currY - offset); i <= (currY + offset); i++)
	{
		for (int j = (currX - offset); j <= (currX + offset); j++)
		{
			if ((i >= 0 && i < n_lin) && (j >= 0 && j < n_col)){
				for (int k = 0; k < mapa[i][j].getNumUnidades(); k++){
					if (mapa[i][j].getUnidadeByIndex(k)->getnJog() != this->nJog){
						this->actionTargetId = mapa[i][j].getUnidadeByIndex(k)->getNomeUnidade();
						this->ultimaOrdem = 2; //ATACAR

						//se encontrou um alvo pode retornar
						return;
					}
				}
			}
		}
	}
}

void Unidade::revealMap(vector<vector<Terreno>>& mapa, int n_lin, int n_col, int currY, int currX){
	int offset = 2;
	for (int i = (currY - offset); i <= (currY + offset); i++)
	{
		for (int j = (currX - offset); j <= (currX + offset); j++)
		{
			if ((i >= 0 && i < n_lin) && (j >= 0 && j < n_col))
				mapa[i][j].setVisible(true);
		}
	}
}

// Overloading
void Soldado::construir(){
	cout << "Esta unidade nao tem a capacidade de construir"; getchar();
}

void Cavaleiro::construir(){
	cout << "Esta unidade nao tem a capacidade de construir"; getchar();
}

void Soldado::reparar(){
	cout << "Esta unidade nao tem a capacidade de reparar"; getchar();
}

void Cavaleiro::reparar(){
	cout << "Esta unidade nao tem a capacidade de reparar"; getchar();
}

void Soldado::minar(){
	cout << "Esta unidade nao tem a capacidade de minar"; getchar();
}

void Cavaleiro::minar(){
	cout << "Esta unidade nao tem a capacidade de minar"; getchar();
}

void Campones::atacar(){
	cout << "Esta unidade nao tem a capacidade de atacar"; getchar();
}

void CamponesCavalo::atacar(){
	cout << "Esta unidade nao tem a capacidade de atacar"; getchar();
}

void Campones::patrol(){
	//cout << "Esta unidade nao tem capacidade de patrulhar!";
}

void CamponesCavalo::patrol(){
	//cout << "Esta unidade nao tem capacidade de patrulhar!";
}
#include "Jogo.h"


Jogo::Jogo(){
	string lastNotification = "";
	string lastSelectedItem = "";
	int lastSelectedItemX = -1;
	int lastSelectedItemY = -1;
}

Jogo::~Jogo(){
	for (unsigned int i = 0; i<Pop.size(); i++){
		delete Pop[i];
	}
	Pop.clear();
}

void Jogo::iterar(){
	Unidade * p;
	for (int i = 0; i < n_lin; i++){
		for (int j = 0; j < n_col; j++){

			//por cada unidade
			for (int k = 0; k < Mapa[i][j].getNumUnidades(); k++){
				if (Mapa[i][j].getUnidadeByIndex(k)->getStamina()){ //se ainda realizou nenhuma acção
					//veririca se foi dada a ordem de minar
					p = Mapa[i][j].getUnidadeByIndex(k);
					switch (p->getOrdem())
					{
					case MINAR:
						p->minar(Mapa, n_lin, n_col, i, j, Pop[p->getnJog() - 1]);
						break;
					case ATACAR:
						p->atacar(Mapa, n_lin, n_col, i, j, Pop[p->getnJog() - 1]);
						break;
					case REPARAR:
						p->reparar(Mapa, n_lin, n_col, i, j, Pop[p->getnJog() - 1]);
						break;
					case DEAMBULAR:
						p->deambular(n_lin, n_col);
						break;
					case CONSTRUIR:
						p->construir(Mapa, i, j, Pop[p->getnJog() - 1]);
						break;
					}
					//caso geral
					if (p->getnJog() == 1)
						p->revealMap(Mapa, n_lin, n_col, i, j);
					p->movimentar(Mapa, i, j);
					//soldados atacam automaticamente
					p->patrol(Mapa, n_lin, n_col, i, j);
				}
			}
			//por cada edificio
			if (Mapa[i][j].getEdificio() != NULL){
				if (Mapa[i][j].getEdificio()->getUnitQueue() == true){
					Mapa[i][j].getEdificio()->recruta(Mapa, i, j, Pop[Mapa[i][j].getEdificio()->getnJog() - 1]);
				}
			}
		}
	}

	//Desbloquear unidades e actualizar mapa
	for (int i = 0; i < n_lin; i++){
		for (int j = 0; j < n_col; j++){
			for (int k = 0; k < Mapa[i][j].getNumUnidades(); k++){
				p = Mapa[i][j].getUnidadeByIndex(k);
				if (p->getSaude() <= 0){
					int njog = p->getnJog();
					string uniId = p->getNomeUnidade();
					Mapa[i][j].removeUnidade(k); //remove a unidade do mapa (erase)
					Pop[njog-1]->removeUnidade(uniId); //remove a unidade da populacao com delete
				}
				else {
					Mapa[i][j].getUnidadeByIndex(k)->setStamina(true);
				}
			}
			if (Mapa[i][j].getEdificio() != NULL && Mapa[i][j].getEdificio()->getEstado() <= 0)
				Mapa[i][j].removeEdificio();
		}
	}
}

string Jogo::getLastNotification(){
	return this->lastNotification;
}

void Jogo::registaPopulacao(Populacao *p){
	if (encontraPopulacao(p->getNome()) == -1)
		Pop.push_back(p);
	else
		notificar("Populacao ja existe!");
}

int Jogo::encontraPopulacao(string n) const{
	int indice = -1;
	for (size_t i = 0; i < Pop.size(); i++){
		if (Pop[i]->getNome() == n){
			indice = i;
			break;
		}
	}
	return indice;
}

Unidade* Jogo::encontraUnidade(string unitName){
	Unidade* u;
	for (int i = 0; i < n_lin; i++){
		for (int j = 0; j < n_col; j++){
			if ((u = Mapa[i][j].getUnidadeByID(unitName)) != NULL){
				return u;
			}
		}
	}
	return NULL;
}

void Jogo::notificar(string str){
	this->lastNotification = str;
	Consola c;
	c.gotoxy(2, 1);
	for (size_t i = 0; i < (offset * 2 + 1) * 3 + width_info_box; i++) 
		cout << " ";
	c.gotoxy(2, 1);
	cout << this->lastNotification;
	c.gotoxy(2, (offset * 2 + 1) * 3 + 4);
}

void Jogo::drawInterface(){
	Consola c;
	//Imprimir limites
	this->drawWrapper();

	//Imprimir mapa
	if (!Mapa.empty()){
		this->drawMap(this->currX, this->currY); //scroll no centro
	}
	else{
		c.gotoxy(3, (offset * 2 + 1) + 4);
		cout << "Bem-vindo ao Warcraft!";
		c.gotoxy(3, (offset * 2 + 1) + 5);
		cout << "Digite:" << endl;
		c.gotoxy(3, (offset * 2 + 1) + 6);
		cout << "mkgame <linhas> <colunas>" << endl;
		c.gotoxy(3, (offset * 2 + 1) + 7);
		cout << "Na linha inferior,";
		c.gotoxy(3, (offset * 2 + 1) + 8);
		cout << "para iniciar um novo jogo";
		c.gotoxy(3, (offset * 2 + 1) + 9);
		cout << "   (Sem '<' e '>')";
		c.gotoxy(3, (offset * 2 + 1) + 10);
		cout << "Ex: mkgame 10 10";
		c.gotoxy(3, (offset * 2 + 1) + 11);
		cout << "Ex: novo 2";
		c.gotoxy(3, (offset * 2 + 1) + 12);
		cout << "Ex: novo 4";
	}

	drawInfoXY(0);
	//drawGameContents();
	//prepara cursor para introduzir comandos
	//numero de terrenos em display * 3 caracteres cada terreno + salta 4 elementos y(linhas, etc)
	notificar(this->lastNotification);
	c.gotoxy(2, (offset * 2 + 1) * 3 + 4);
}

void Jogo::drawWrapper(){
	Consola c;
	c.gotoxy(0, 0);
	//linha 1 - limite superior
	cout << char(218);
	for (size_t i = 0; i < (offset * 2 + 1) * 3 + width_info_box + 1; i++) //+1 é a linha de coluna que é somada em baixo
		cout << char(196);
	cout << char(191) << endl;

	//linha 2 - notificações
	cout << char(179);
	for (size_t i = 0; i < (offset * 2 + 1) * 3 + width_info_box + 1; i++)
		cout << " ";
	cout << char(179) << endl;

	//linha 3 | limite superior box
	cout << char(195);
	for (size_t i = 0; i < (offset * 2 + 1) * 3; i++)
		cout << char(196);
	cout << char(194); //separador de coluna
	for (size_t i = 0; i < width_info_box; i++)
		cout << char(196); //espaço para a info box
	cout << char(180) << endl;

	//box do mapa
	for (size_t i = 0; i < (offset * 2 + 1) * 3; i++) //linhas
	{
		cout << char(179);
		for (size_t j = 0; j < (offset * 2 + 1) * 3; j++) //colunas mapa
		{
			cout << " ";
		}
		cout << char(179);
		for (size_t j = 0; j < width_info_box; j++) //colunas info
		{
			cout << " ";
		}
		cout << char(179) << endl;
	}

	//limite inferior mapa
	cout << char(195);
	for (size_t i = 0; i < (offset * 2 + 1) * 3; i++)
		cout << char(196);
	cout << char(193);
	for (size_t i = 0; i < width_info_box; i++)
		cout << char(196);
	cout << char(180) << endl;

	//linha para comandos
	cout << char(179);
	cout << ">"; //1 char a menos no for
	for (size_t i = 0; i < (offset * 2 + 1) * 3 + width_info_box; i++) //-1(char coluna)+1(char comandos)= +0
		cout << " ";
	cout << char(179) << endl;

	//limite inferior
	cout << char(192);
	for (size_t i = 0; i < (offset * 2 + 1) * 3 + width_info_box + 1; i++)
		cout << char(196);
	cout << char(217) << endl;
}

void Jogo::drawMap(int &x, int &y){
	//int x, int y - posições de focus do mapa

	//validar o scroll
	if ((x - offset) < 0) x = offset;
	else if ((x + offset) > n_col - 1) x = n_col - 1 - offset;
	if ((y - offset) < 0) y = offset;
	else if ((y + offset) > n_lin - 1) y = n_lin - 1 - offset;

	for (int i = y - offset; i <= y + offset; i++)
	{
		for (int j = x - offset; j <= x + offset; j++)
		{
			Mapa[i][j].imprimeTerreno((j - (x - offset)) * 3 + 1, (i - (y - offset)) * 3 + 3);
		}
	}
}

void Jogo::drawInfoXY(int _top){
	Consola c;
	Edificio* selEdf; //Edificio selecionado
	Unidade* selUni;  //Unidade selecionada
	_top += 4;
	int margin_left = (offset * 2 + 1) * 3 + 3; //2 linhas + tam mapa
	c.gotoxy(margin_left, 3);
	cout << "Info:";
	if (lastSelectedItemX >= 0 && lastSelectedItemY >= 0 && !lastSelectedItem.empty()){

		selEdf = Mapa[lastSelectedItemY][lastSelectedItemX].getEdificio();

		c.gotoxy(margin_left, _top);
		if (selEdf != NULL &&
			selEdf->getNomeEdificio() == lastSelectedItem)
		{
			c.gotoxy(margin_left, ++_top);
			cout << selEdf->getNomeEdificio();
			c.gotoxy(margin_left, ++_top);
			cout << "Jog: " << selEdf->getnJog();
			c.gotoxy(margin_left, ++_top);
			cout << selEdf->getTipoEdificio();
			c.gotoxy(margin_left, ++_top);
			cout << selEdf->getEstado();
		}
		else if ((selUni = Mapa[lastSelectedItemY][lastSelectedItemX].getUnidadeByID(lastSelectedItem)) != NULL)
		{
			c.gotoxy(margin_left, ++_top);
			cout << selUni->getNomeUnidade();
			c.gotoxy(margin_left, ++_top);
			cout << "Jog: " << selUni->getnJog();
			c.gotoxy(margin_left, ++_top);
			cout << selUni->getTipoUnidade();
			c.gotoxy(margin_left, ++_top);
			cout << selUni->getSaude();
			c.gotoxy(margin_left, ++_top);

			int tarX = selUni->getTarX();
			int tarY = selUni->getTarY();
			if ((tarX != -1 && tarX != lastSelectedItemX) || (tarY != -1 && tarY != lastSelectedItemY))
				cout << "A mover-se";
			else cout << "Parado";
		}
	}
}

void Jogo::drawGameContents(string pop){
	Consola c;
	int indice;
	int margin_left = (offset * 2 + 1) * 3 + width_info_box + 6; //3 linhas + tam mapa + tamInfoXY+ margem(3)
	int margin_top = 3;

	if ((indice = encontraPopulacao(pop)) != -1){
		c.gotoxy(margin_left, margin_top);
		cout << "Populacao: " << pop;

		++margin_top;
		c.gotoxy(++margin_left, ++margin_top);
		cout << "Ouro: " << Pop[indice]->getOuro();
		c.gotoxy(margin_left, ++margin_top);
		cout << "Pedra: " << Pop[indice]->getPedra();
		c.gotoxy(margin_left, ++margin_top);
		cout << "Madeira: " << Pop[indice]->getMadeira();

		++margin_top;
		c.gotoxy(--margin_left, ++margin_top);
		cout << Pop[indice]->getNumEdificios() << " Edificios:";

		c.gotoxy(++margin_left, ++margin_top);
		for (int i = 0; i < Pop[indice]->getNumEdificios(); i++)
		{
			c.gotoxy(margin_left, ++margin_top);
			cout << Pop[indice]->getEdificioByIndex(i)->getNomeEdificio();
		}

		++margin_top;
		c.gotoxy(--margin_left, ++margin_top);
		cout << Pop[indice]->getNumUnidades() << " Unidades:";

		c.gotoxy(++margin_left, ++margin_top);
		for (int i = 0; i < Pop[indice]->getNumUnidades(); i++)
		{
			c.gotoxy(margin_left, ++margin_top);
			cout << Pop[indice]->getUnidadeByIndex(i)->getNomeUnidade();
			cout << " " << Pop[indice]->getUnidadeByIndex(i)->getOrdem();
		}
	}
}

void Jogo::readFile(string filename)
{
	ifstream infile(filename);
	string line;
	while (getline(infile, line)){
		notificar(line);
		verificaComando(line);
	}
}

void Jogo::processaComando(int _cmd, string param1, string param2, int x, int y){
	//int _cmd - id de comando
	//param1, param2 (nomes, ids, tipo ...)
	Consola c;
	ostringstream oss;
	Unidade* p = NULL;
	Edificio* e = NULL;
	int nQuintas = 0;
	int nUnidades = 0;

	int indice;
	switch (_cmd){
	case 1: //mkgame <linhas> <colunas>
		if (x >= 9 && y >= 9){
			Mapa.resize(y, vector<Terreno>(x));
			this->n_col = x;
			this->n_lin = y;
			this->currX = n_col / 2; //scroll centro
			this->currY = n_lin / 2; //scroll centro

			oss << "Mapa criado! <" << y << "> <" << x << ">";
			notificar(oss.str());
		}
		else {
			oss << "X e Y devem ser maiores que 8!";
			notificar(oss.str());
		}
		break;

	case 2: //pop <nome>
		registaPopulacao(new Populacao(param1));
		oss << "Populacao criada! Nome: " << param1 << endl;
		notificar(oss.str());
		break;

	case 3: //setf <oque> <linha> <coluna>
		Mapa[x][y].AdicionarRecurso(new Recurso(param1, res_default_value));
		oss << "Recurso Adicionado! Tipo: " << param1 << endl;
		notificar(oss.str());
		break;

	case 4: //sete <pop> <oque> <linha> <coluna>
		if ((indice = this->encontraPopulacao(param1)) != -1){
			if (param2.compare("cas") == 0){

				//pointer para a nova instancia da classe castelo
				Castelo * _cas = new Castelo();
				_cas->setnJog(Pop[indice]->getIdJogador());
				//constroi o castelo na populacao definida
				//a população fica encarregue de destruir "delete" os edificios (quem os detem)
				Pop[indice]->AdicionaEdificio(_cas);

				//o terreno aponta para o edificio criado
				Mapa[x][y].AdicionarEdificio(_cas);
			}
			else if (param2.compare("qui") == 0){
				Quinta * _qui = new Quinta();
				_qui->setnJog(Pop[indice]->getIdJogador());
				Pop[indice]->AdicionaEdificio(_qui);
				Mapa[x][y].AdicionarEdificio(_qui);
			}
			else if (param2.compare("qua") == 0){
				Quartel * _qua = new Quartel();
				_qua->setnJog(Pop[indice]->getIdJogador());
				Pop[indice]->AdicionaEdificio(_qua);
				Mapa[x][y].AdicionarEdificio(_qua);
			}
			else if (param2.compare("est") == 0){
				Estabulo * _est = new Estabulo();
				_est->setnJog(Pop[indice]->getIdJogador());
				Pop[indice]->AdicionaEdificio(_est);
				Mapa[x][y].AdicionarEdificio(_est);
			}
			else return;

			oss << "Edificio criado para a populacao: " << param1 << " | " << param2 << " " << x << " " << y;
			//<< "    Tipo: " << param2 << " Linha: " << y << " Coluna: " << x << endl;
			notificar(oss.str());
		}
		else {
			oss << "Populacao nao encontrada!" << endl;
			notificar(oss.str());
		}
		break;

	case 5: //setu <pop> <oque> <linha> <coluna>
		indice = this->encontraPopulacao(param1);
		if (indice != -1){
			if (param2.compare("camp") == 0){
				//pointer para a nova instancia da classe campones
				Campones * _camp = new Campones();
				_camp->setnJog(Pop[indice]->getIdJogador());
				//coloca o campones na populacao definida
				//a população fica encarregue de destruir "delete" as unidades (quem os detem)
				Pop[indice]->AdicionaUnidade(_camp);

				//o terreno aponta para a unidade criada
				Mapa[y][x].AdicionarUnidade(_camp);
			}
			else if (param2.compare("sold") == 0){
				Soldado * _sold = new Soldado();
				_sold->setnJog(Pop[indice]->getIdJogador());
				Pop[indice]->AdicionaUnidade(_sold);
				Mapa[y][x].AdicionarUnidade(_sold);
			}
			else if (param2.compare("cav") == 0){
				Cavaleiro * _cav = new Cavaleiro();
				_cav->setnJog(Pop[indice]->getIdJogador());
				Pop[indice]->AdicionaUnidade(_cav);
				Mapa[y][x].AdicionarUnidade(_cav);
			}
			else if (param2.compare("cv") == 0){
				CamponesCavalo * _cv = new CamponesCavalo();
				_cv->setnJog(Pop[indice]->getIdJogador());
				Pop[indice]->AdicionaUnidade(_cv);
				Mapa[y][x].AdicionarUnidade(_cv);
			}
			else return;
			//cout << "Unidade criada para a populacao: " << param1 << endl
				//<< "    Tipo: " << param2 << " Linha: " << y << " Coluna: " << x << endl;
			oss << "Unidade criada para a populacao: " << param1 << endl;
			notificar(oss.str());
		}
		else notificar("Populacao nao encontrada!");
		break;
	case 6: //load <file>
		notificar("A carregar ficheiro...");
		readFile(param1);
		break;
	case 7: //mostra <pop>
		drawGameContents(param1);
		getchar();
		break;
	//case 8 -> exit
	case 9: //sel <id>
		for (int i = 0; i < n_lin; i++){
			for (int j = 0; j < n_col; j++){
				if (Mapa[i][j].getUnidadeByID(param1) != NULL || 
					(Mapa[i][j].getEdificio() != NULL 
					&& Mapa[i][j].getEdificio()->getNomeEdificio() == param1)){

					//scroll
					this->currX = j;
					this->currY = i;

					//log
					this->lastSelectedItem = param1;
					this->lastSelectedItemX = j;
					this->lastSelectedItemY = i;

					oss << "Item selecionado: " << param1 << endl;
					notificar(oss.str());
				}
			}
		}
		break;

	case 10: //scroll
		notificar("Prima ESC para sair do modo Scroll");
		while (true)
		{
			switch (c.getch())
			{
			case c.CIMA:
				drawMap(this->currX, --this->currY);
				break;
			case c.BAIXO:
				drawMap(this->currX, ++this->currY);
				break;
			case c.ESQUERDA:
				drawMap(--this->currX, this->currY);
				break;
			case c.DIREITA:
				drawMap(++this->currX, this->currY);
				break;
			case c.ESCAPE:
				return;
				break;
			}
		}
		break;
	case 11: //next
		iterar();
		break;
	case 12: //next n
		for (int i = 0; i < x; i++)
			iterar();
		break;
	case 13: //go
		for (int i = 0; i < n_lin; i++){
			for (int j = 0; j < n_col; j++){
				if ((p = Mapa[i][j].getUnidadeByID(param1)) != NULL){
					p->setTarX(x + j);
					p->setTarY(y + i);
					p->setOrdem(ANDAR);
					oss << param1 + " moveu-se para " << (y + i) << " " << (x + j);
					notificar(oss.str());
				}
			}
		}
		break;
	case 14: //goto
		if ((p = encontraUnidade(param1)) != NULL){
			p->setTarX(x);
			p->setTarY(y);
			p->setOrdem(ANDAR);
			oss << param1 + " moveu-se para " << y << " " << x;
			notificar(oss.str());
		}
		break;
	case 15: //mina
		if ((p = encontraUnidade(param1)) != NULL){
			if (p->getTipoUnidade() == "CMP" || p->getTipoUnidade() == "CCV"){
				p->setActionTargetId(param2);
				p->setOrdem(MINAR);

				oss << "Unidade " << param1 << " a minar " << param2 << endl;
				notificar(oss.str());
			}
		}
		break;
	case 16: //ataca
		if ((p = encontraUnidade(param1)) != NULL){
			if (p->getTipoUnidade() == "SOL" || p->getTipoUnidade() == "KNT"){
				p->setActionTargetId(param2);
				p->setOrdem(ATACAR); //IZAA!!

				oss << "Unidade " << param1 << " a atacar " << param2 << endl;
				notificar(oss.str());
			}
		}
		break;
	case 17: //conserta
		if ((p = encontraUnidade(param1)) != NULL){
			if (p->getTipoUnidade() == "CMP" || p->getTipoUnidade() == "CCV"){
				p->setActionTargetId(param2);
				p->setOrdem(REPARAR);

				oss << "Unidade " << param1 << " a reparar " << param2 << endl;
				notificar(oss.str());
			}
		}
		break;
	case 18: //deambula
		if ((p = encontraUnidade(param1)) != NULL){
			p->setActionTargetId(param2);
			p->setOrdem(DEAMBULAR);

			oss << "Unidade " << param1 << " a reparar " << param2 << endl;
			notificar(oss.str());
		}
		break;
	case 19: //mke
		if ((p = encontraUnidade(param1)) != NULL){
			if (p->getTipoUnidade() == "CMP" || p->getTipoUnidade() == "CCV"){
				p->setActionTargetId(param2);
				p->setOrdem(CONSTRUIR);
				p->setTarX(x);
				p->setTarY(y);

				oss << "Unidade " << param1 << " a construir " << param2 << endl;
				notificar(oss.str());
			}
		}
		break;
	case 20: //mku
		for (int i = 0; i < Pop[0]->getNumEdificios(); i++){
			if (Pop[0]->getEdificioByIndex(i)->getTipoEdificio() == "qui")
				++nQuintas;
		}
		for (int i = 0; i < Pop[0]->getNumUnidades(); i++)
			++nUnidades;

		if (nUnidades < (nQuintas * 4)){
			//Dá as ordens aos edificios para recrutar
			if (param1 == "camp"){
				for (int i = 0; i < Pop[0]->getNumEdificios(); i++){
					if (Pop[0]->getEdificioByIndex(i)->getTipoEdificio() == "CAS"){
						Pop[0]->getEdificioByIndex(i)->setUnitQueue(true);
						Pop[0]->getEdificioByIndex(i)->setUnitTypeOnQueue(CAMPONES);
					}
				}
			}
			else if (param1 == "sold"){
				for (int i = 0; i < Pop[0]->getNumEdificios(); i++){
					if (Pop[0]->getEdificioByIndex(i)->getTipoEdificio() == "QUA"){
						Pop[0]->getEdificioByIndex(i)->setUnitQueue(true);
						Pop[0]->getEdificioByIndex(i)->setUnitTypeOnQueue(SOLDADO);
					}
				}
			}
			else if (param1 == "cav"){
				for (int i = 0; i < Pop[0]->getNumEdificios(); i++){
					if (Pop[0]->getEdificioByIndex(i)->getTipoEdificio() == "EST"){
						Pop[0]->getEdificioByIndex(i)->setUnitQueue(true);
						Pop[0]->getEdificioByIndex(i)->setUnitTypeOnQueue(CAVALEIRO);
					}
				}
			}
			else if (param1 == "cv"){
				for (int i = 0; i < Pop[0]->getNumEdificios(); i++){
					if (Pop[0]->getEdificioByIndex(i)->getTipoEdificio() == "est"){
						Pop[0]->getEdificioByIndex(i)->setUnitQueue(true);
						Pop[0]->getEdificioByIndex(i)->setUnitTypeOnQueue(CAMPONESCAVALO);
					}
				}
			}
		}
		break;
	case 21:
		if ((indice = encontraPopulacao(param1)) != -1)
			this->Pop[indice]->addOuro(x);
		break;
	case 22:
		if ((indice = encontraPopulacao(param1)) != -1)
			this->Pop[indice]->addPedra(x);
		break;
	case 23:
		if ((indice = encontraPopulacao(param1)) != -1)
			this->Pop[indice]->addMadeira(x);
		break;
	case 24:
		for (int i = 0; i < stoi(param1); i++)
		{
			if (i == 0)
			{
				verificaComando("pop j1");
			}
			else
			{
				verificaComando("pop pc" + to_string(i));
			}

		}
		GerarMapa(stoi(param1));
		break;
	}
}

void Jogo::verificaComando(string cmd){

	string str[5];
	istringstream iss(cmd);
	int argc = 0;

	while (iss){
		iss >> str[argc++];
	} --argc;

	//ao carregar enter, faz next
	if (cmd == "") {
		iterar();
		return;
	}

	//=============COMANDOS RELATIVOS A CRIACAO DO JOGO E POPULACOES=========
	//1
	if (str[0] == "mkgame"){
		if (stoi(str[1]) && stoi(str[2])){
			processaComando(1, "", "", stoi(str[1]), stoi(str[2]));
		}
		else notificar("Erro ao criar! Usar: mkgame <linhas> <colunas>");
	}
	//2
	else if (str[0] == "pop"){
		if (!str[1].empty()){
			processaComando(2, str[1], "", NULL, NULL);
		}
		else notificar("Erro ao criar populacao! Usar: pop <nome>");
	}
	//3
	else if (str[0] == "setf"){
		if (!str[1].empty() && stoi(str[2]) >= 0 && stoi(str[3]) >= 0){
			if (str[1] == "min" || str[1] == "ped" || str[1] == "flo")
				processaComando(3, str[1], "", stoi(str[2]), stoi(str[3]));
			else notificar("Erro ao criar! Param-> setf <oque> ");
				//<< "    oque: min->mina, ped->pedreira, flo->floresta" << endl;
		}
		else notificar("Erro ao criar recurso!");
			//<< "    Usar: setf <oque> <linha> <coluna>" << endl;
	}
	//4
	else if (str[0] == "sete"){
		if (!str[1].empty() && !str[2].empty() && stoi(str[3]) >= 0 && stoi(str[4]) >= 0){
			if (str[2] == "qua" || str[2] == "est" || str[2] == "qui" || str[2] == "cas")
				processaComando(4, str[1], str[2], stoi(str[3]), stoi(str[4]));
			else notificar("Erro ao criar! Param-> sete <oque>");
				//<< "    oque: cas->castelo, qua->quartel, est->estabulo, quin->quinta" << endl;
		}
		else notificar("Erro ao criar edificio!");
			//<< "   Usar: sete <nome> <oque> <linha> <coluna>" << endl;
	}
	//5
	else if (str[0] == "setu"){
		if (!str[1].empty() && !str[2].empty() && stoi(str[3]) >= 0 && stoi(str[4]) >= 0){
			if (str[2] == "camp" || str[2] == "sold" || str[2] == "cav" || str[2] == "cv")
				processaComando(5, str[1], str[2], stoi(str[3]), stoi(str[4]));
			else notificar("Erro ao criar! Param-> sete <oque>");
				//<< "    oque: camp->campones, sold->soldado, cav->cavaleiro, cv->campones a cavalo" << endl;
		}
		else notificar("Erro ao criar unidade!");
			//<< "    Usar: setu <nome> <oque> <linha> <coluna>" << endl;
	}
	//6
	else if (str[0] == "load"){
		if (!str[1].empty())
			processaComando(6, str[1], "", 0, 0);
		else notificar("Erro! Usar: load <filename>");
	}
	//7
	else if (str[0] == "mostra"){
		if (!str[1].empty())
			processaComando(7, str[1], "", 0, 0);
		else notificar("Erro! Usar: mostra <nome>");
	}
	//8
	else if (str[0] == "sair"){
		exit(EXIT_SUCCESS);
	}

	//=============COMANDOS RELATIVOS A INTERACCAO COM O JOGO=========

	//9
	else if (str[0] == "sel"){
		if (!str[1].empty())
			processaComando(9, str[1], "", 0, 0);
			//cout << "centrar a parte visivel no ecran no item selecionado";
		else notificar("Erro! Usar: sel <id>");
	}

	//10
	else if (str[0] == "scroll"){
		processaComando(10, "", "", 0, 0);
	}
	//11,12
	else if (str[0] == "next"){
		if (!str[1].empty())
		processaComando(12, "", "", stoi(str[1]), 0);
		else processaComando(11, "", "", 0, 0);
	}
	//=============COMANDOS RELATIVOS A INTERACCAO COM O JOGO=========
	//13
	else if (str[0] == "go"){
		if (!str[1].empty() && stoi(str[2]) >= 0 && stoi(str[3]) >= 0 
			&& stoi(str[2]) < n_lin && stoi(str[3]) < n_col){
			if (str[1] == "."){
				processaComando(13, lastSelectedItem, "", stoi(str[2]), stoi(str[3]));
			}
			else{
				//str[1] - ID
				// str[2] e str[3] delta_linha, delta_col
				processaComando(13, str[1], "", stoi(str[2]), stoi(str[3]));
			}
		}
		else notificar("Erro! Usar: go <id> <delta_linha> <delta_coluna>");
	}
	//14
	else if (str[0] == "goto"){
		//mesma coisa que o go, mas no goto e' indicado o destino
		if (!str[1].empty() && stoi(str[2]) >= 0 && stoi(str[3]) >= 0){
			if (str[1] == "."){
				processaComando(14, lastSelectedItem, "", stoi(str[2]), stoi(str[3]));
			}
			else{
				processaComando(14, str[1], "", stoi(str[2]), stoi(str[3]));
			}
		}
		else notificar("Erro! Usar: goto <id> < linha> < coluna>");
	}
	//15
	else if (str[0] == "mina"){
		if (!str[1].empty() && !str[2].empty()){
			if (str[1] == "."){
				processaComando(15, lastSelectedItem, str[2], 0, 0);
			}
			else{
				processaComando(15, str[1], str[2], 0, 0);
			}
		}
		else notificar("Erro! Usar: mina <id> <idfonte>");
	}
	//16
	else if (str[0] == "ataca"){
		if (!str[1].empty() && !str[2].empty()){
			if (str[1] == "."){
				processaComando(16, lastSelectedItem, str[2], 0, 0);
			}
			else{
				processaComando(16, str[1], str[2], 0, 0);
			}
		}
		else notificar("Erro! Usar: ataca <id> <idvitima>");
	}
	//17
	else if (str[0] == "conserta"){
		if (!str[1].empty() && !str[2].empty()){
			if (str[1] == "."){
				processaComando(17, lastSelectedItem, str[2], 0, 0);
			}
			else{
				processaComando(17, str[1], str[2], 0, 0);
			}
		}
		else notificar("Erro! Usar: conserta <id> <ide>");
	}
	//18
	else if (str[0] == "deambula"){
		if (!str[1].empty()){
			if (str[1] == "."){
				processaComando(18, lastSelectedItem, "", 0, 0);
			}
			else{
				processaComando(18, str[1], "", 0, 0);
			}
		}
		else notificar("Erro! Usar: deambula <id>");
	}
	//19
	else if (str[0] == "mke"){
		if (!str[1].empty() && !str[2].empty() && stoi(str[3]) >= 0 && stoi(str[4]) >= 0){
			if (str[2] == "qua" || str[2] == "est" || str[2] == "qui" || str[2] == "cas")
			{
				if (str[1] == "."){
					processaComando(19, lastSelectedItem, str[2], stoi(str[3]), stoi(str[4]));
				}
				else{
					processaComando(19, str[1], str[2], stoi(str[3]), stoi(str[4]));
				}
			}
			else notificar("Erro! Usar: mke <oque>");
				//<< "oque: cas ->castelo, quar->quartel, est->estabulo, quin->quinta" << endl;
		}
		else notificar("Erro! Usar: mke <id> <oque> <linha> <coluna>");
	}
	//20
	else if (str[0] == "mku"){
		if (!str[1].empty()){
			if (str[1] == "camp" || str[1] == "sold" || str[1] == "cav" || str[1] == "cv"){
				processaComando(20, str[1], "", 0, 0);
			}
			else notificar("Erro! Usar: mku <oque>");
				//<< "oque: camp->campones, sold->soldado, cav->cavaleiro, cv->campones a cavalo" << endl;
		}
		else notificar("Erro! Usar: mku <oque>");
	}

	//=============COMANDOS PARA OS RECURSOS=========
	//21
	else if (str[0] == "ouro"){
		if (!str[1].empty() && stoi(str[2])){
			//populacao str[1] recebe str[2]
			processaComando(21, str[1], "", stoi(str[2]), 0);
		}
		else notificar("Erro! Usar: ouro <nome> <n>");
	}
	//22
	else if (str[0] == "pedra"){
		if (!str[1].empty() && stoi(str[2])){
			processaComando(22, str[1], "", stoi(str[2]), 0);
		}
		else notificar("Erro! Usar: pedra <nome> <n>");
	}
	//23
	else if (str[0] == "madeira"){
		if (!str[1].empty() && stoi(str[2])){
			processaComando(22, str[1], "", stoi(str[2]), 0);
		}
		else notificar("Erro! Usar: madeira <nome> <n>");
	}
	//ai
	else if (str[0] == "novo"){
		if (!str[1].empty()){
			processaComando(24, str[1], "", 0, 0);
		}
		else cout << "Erro! Usar: novo <npop>" << endl;
	}
	else notificar("Comando Invalido!");
}

void Jogo::GerarMapa(int x){

	verificaComando("mkgame " + to_string(((x + 4)) * 6) + " " + to_string(((x + 4) * 6)));
	if (x <= 4)
	{
		for (int i = 0; i < Pop.size(); i++)
		{
			switch (i)
			{
			case 0:
				verificaComando("sete " + Pop[i]->getNome() + " cas 0 0");
				verificaComando("setu " + Pop[i]->getNome() + " camp 0 2");
				verificaComando("setu " + Pop[i]->getNome() + " cv 1 2");
				verificaComando("setf flo 3 0");
				verificaComando("setf flo 3 1");
				verificaComando("setf flo 4 0");
				verificaComando("setf flo 4 1");
				verificaComando("setf flo 0 3");
				verificaComando("setf flo 1 3");
				verificaComando("setf flo 0 4");
				verificaComando("setf flo 1 4");
				verificaComando("setf min 0 2");
				verificaComando("setf ped 0 5");
				intel.push_back(AI(Pop[i]));
				intel[i].EncontrarRecursos(Mapa, this);//provisoriamente pelos limites da base

				break;
			case 1:

				verificaComando("sete " + Pop[i]->getNome() + " cas " + to_string(((x + 4) * 6) - 1) + " " + to_string(((x + 4) * 6) - 1));
				verificaComando("setu " + Pop[i]->getNome() + " camp " + to_string(((x + 4) * 6) - 3) + " " + to_string(((x + 4) * 6) - 1));
				verificaComando("setu " + Pop[i]->getNome() + " cv " + to_string(((x + 4) * 6) - 2) + " " + to_string(((x + 4) * 6) - 1));
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 1) + " " + to_string(((x + 4) * 6) - 4));
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 1) + " " + to_string(((x + 4) * 6) - 5));
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 5) + " " + to_string(((x + 4) * 6) - 1));
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 4) + " " + to_string(((x + 4) * 6) - 1));
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 4) + " " + to_string(((x + 4) * 6) - 2));
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 5) + " " + to_string(((x + 4) * 6) - 2));
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 2) + " " + to_string(((x + 4) * 6) - 4));
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 2) + " " + to_string(((x + 4) * 6) - 5));
				verificaComando("setf min " + to_string(((x + 4) * 6) - 3) + " " + to_string(((x + 4) * 6) - 1));
				verificaComando("setf ped " + to_string(((x + 4) * 6) - 6) + " " + to_string(((x + 4) * 6) - 1));
				intel.push_back(AI(Pop[i]));
				intel[i].EncontrarRecursos(Mapa, this);
				break;




			case 2:
				verificaComando("sete " + Pop[i]->getNome() + " cas " + to_string(((x + 4) * 6) - 1) + " 0");
				verificaComando("setu " + Pop[i]->getNome() + " camp 2 " + to_string(((x + 4) * 6) - 1));
				verificaComando("setu " + Pop[i]->getNome() + " cv 1 " + to_string(((x + 4) * 6) - 1));
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 1) + " 3");
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 1) + " 4");
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 2) + " 3");
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 2) + " 4");
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 4) + " 0");
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 5) + " 0");
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 4) + " 1");
				verificaComando("setf flo " + to_string(((x + 4) * 6) - 5) + " 1");
				verificaComando("setf min " + to_string(((x + 4) * 6) - 3) + " 0");
				verificaComando("setf ped " + to_string(((x + 4) * 6) - 6) + " 0");
				intel.push_back(AI(Pop[i]));
				intel[i].EncontrarRecursos(Mapa, this);
				break;
			case 3:
				verificaComando("sete " + Pop[i]->getNome() + " cas 0 " + to_string(((x + 4) * 6) - 1));
				verificaComando("setu " + Pop[i]->getNome() + " camp " + to_string(((x + 4) * 6) - 3) + " 1");
				verificaComando("setu " + Pop[i]->getNome() + " cv " + to_string(((x + 4) * 6) - 2) + " 1");
				verificaComando("setf flo 0 " + to_string(((x + 4) * 6) - 4));
				verificaComando("setf flo 0 " + to_string(((x + 4) * 6) - 5));
				verificaComando("setf flo 1 " + to_string(((x + 4) * 6) - 4));
				verificaComando("setf flo 1 " + to_string(((x + 4) * 6) - 5));
				verificaComando("setf flo 3 " + to_string(((x + 4) * 6) - 1));
				verificaComando("setf flo 4 " + to_string(((x + 4) * 6) - 1));
				verificaComando("setf flo 3 " + to_string(((x + 4) * 6) - 2));
				verificaComando("setf flo 4 " + to_string(((x + 4) * 6) - 2));
				verificaComando("setf min 0 " + to_string(((x + 4) * 6) - 3));
				verificaComando("setf ped 0 " + to_string(((x + 4) * 6) - 6));
				intel.push_back(AI(Pop[i]));
				intel[i].EncontrarRecursos(Mapa, this);
				break;
			default:
				break;
			}
		}
	}
}
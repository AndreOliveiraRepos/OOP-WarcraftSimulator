#include "Terreno.h"
void Terreno::setVisible(bool visibility){
	this->visivel = visibility;
}

void Terreno::imprimeTerreno(int margin_left, int margin_top){
	const int PLAYER_CLR = 9;
	const int AI_CLR = 12;
	Consola console;

	if (this->visivel == true){
		if (this->recurso != NULL)
		{
			console.setTextColor(0);
			if (this->recurso->getNome() == "MIN")
				console.setBackgroundColor(14);
			else if (this->recurso->getNome() == "PED")
				console.setBackgroundColor(8);
			else if (this->recurso->getNome() == "FLO")
				console.setBackgroundColor(2);

			console.gotoxy(margin_left, margin_top);
			cout << recurso->getNome();
			console.gotoxy(margin_left, ++margin_top);
			cout << recurso->getIdFonte();
			console.gotoxy(margin_left, ++margin_top);
			cout << " " << recurso->getQuant();
		}
		else if (this->edificio != NULL)
		{
			int playerClr = PLAYER_CLR;
			if (edificio->getnJog() != 1) //jogador = azul | Ai = vermelho
				playerClr = AI_CLR;

			console.setTextColor(0);
			console.setBackgroundColor(playerClr);
			console.gotoxy(margin_left, margin_top);
			cout << edificio->getTipoEdificio();
			console.gotoxy(margin_left, ++margin_top);
			cout << edificio->getNomeEdificio();
			console.gotoxy(margin_left, ++margin_top);
			cout << edificio->getEstado();
		}
		else if (!this->unidades.empty()){
			int playerClr = PLAYER_CLR;
			if (unidades[unidades.size() - 1]->getnJog() != 1) //visualizar a unidade mais recente no terreno
				playerClr = AI_CLR;
			console.setTextColor(0);
			console.setBackgroundColor(playerClr);
			console.gotoxy(margin_left, margin_top);
			cout << unidades[unidades.size() - 1]->getTipoUnidade();
			console.gotoxy(margin_left, ++margin_top);
			cout << unidades[unidades.size() - 1]->getNomeUnidade();
			console.gotoxy(margin_left, ++margin_top);
			cout << " " << unidades[unidades.size() - 1]->getSaude();
		}
		else //SE O TERRENO ESTIVER VAZIO
		{
			console.setTextColor(10);
			console.setBackgroundColor(8);
			console.gotoxy(margin_left, margin_top);
			cout << (char)176 << (char)176 << (char)176;
			console.gotoxy(margin_left, ++margin_top);
			cout << (char)176 << (char)176 << (char)176;
			console.gotoxy(margin_left, ++margin_top);
			cout << (char)176 << (char)176 << (char)176;

			/*console.setBackgroundColor(0);
			console.setTextColor(7);
			console.gotoxy(margin_left, ++margin_top);
			cout << char(196) << char(196) << char(196) << char(197);
			console.gotoxy(margin_left + 3, margin_top - 3); cout << char(179);
			console.gotoxy(margin_left + 3, margin_top - 2); cout << char(179);
			console.gotoxy(margin_left + 3, margin_top - 1); cout << char(179);*/
		}
	}
	else {
		console.setTextColor(8);
		console.setBackgroundColor(0);
		console.gotoxy(margin_left, margin_top);
		cout << (char)176 << (char)176 << (char)176;
		console.gotoxy(margin_left, ++margin_top);
		cout << (char)176 << (char)176 << (char)176;
		console.gotoxy(margin_left, ++margin_top);
		cout << (char)176 << (char)176 << (char)176;
	}

	/*=========== RESET CONSOLE VALUES ============ */
	console.setTextColor(7); //letra branca
	console.setBackgroundColor(0); //fundo preto
}

Terreno::Terreno(){
	visivel = false;
}

Terreno::~Terreno(){
	delete recurso;
}

void Terreno::AdicionarEdificio(Edificio *e){
	if (this->recurso == NULL)
		this->edificio = e;
}

void Terreno::AdicionarRecurso(Recurso *r){
	if (this->edificio == NULL)
		this->recurso = r;
}

void Terreno::AdicionarUnidade(Unidade *uni){
	unidades.push_back(uni);
}

Recurso * Terreno::getRecurso(){
	if (recurso != NULL)
		return recurso;
	else return NULL;
}

Edificio * Terreno::getEdificio(){
	if (edificio != NULL)
		return edificio;
	else return NULL;

}

int Terreno::getNumUnidades(){
	if (unidades.empty())
		return 0;
	else return unidades.size();
}

Unidade * Terreno::getUnidadeByID(string id){
	for (size_t i = 0; i < unidades.size(); i++)
	{
		if (unidades[i]->getNomeUnidade() == id)
		{
			return unidades[i];
			break;
		}
	}
	return NULL;
}

Unidade * Terreno::getUnidadeByIndex(int index){
	return unidades[index];
}

void Terreno::removeUnidade(int i){
	if (unidades.size() == 1)
		unidades.clear();
	else
		//delete unidades[i];
	unidades.erase(unidades.begin() + i);
}

void Terreno::removeUnidadeById(string id){
	for (size_t i = 0; i < unidades.size(); i++){
		if (unidades[i]->getNomeUnidade() == id){
			if (unidades.size() == 1)
				unidades.clear();
			else
				//delete unidades[i];
				unidades.erase(unidades.begin() + i);
			break;
		}
	}			
}

void Terreno::removeRecurso(){
	this->recurso = NULL;
}

void Terreno::removeEdificio(){
	this->edificio = NULL;
}
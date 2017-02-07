
#ifndef AI_H
#define AI_H
#include <vector>
class Jogo;
class Populacao;
class Terreno;

using namespace std;

class AI
{
	
	Populacao *p;
	Jogo *jog;

public:
	AI(Populacao *p);

	~AI();
	void Defender();
	
	void VerificarUnidades();
	void CriaEdificio();
	void CriaUnidade();
	void EncontrarRecursos(vector<vector<Terreno>> &map,Jogo *j);

};



#endif
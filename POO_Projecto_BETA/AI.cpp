
#include "AI.h"
#include "Jogo.h"


AI::AI(Populacao *pop)
{
	p = pop;
}



AI::~AI()
{
}

void AI::Defender(){

}


void AI::VerificarUnidades()
{

}
void AI::CriaEdificio()
{

}
void AI::CriaUnidade()
{

}
void AI::EncontrarRecursos(vector < vector<Terreno>> &mapa, Jogo *t)
{
	jog = t;

	for (int y = 0; y < p->getNumUnidades(); y++)
	{
		if (p->getUnidadeByIndex(y)->getTipoUnidade() == "CMP")
		{
			if (p->getUnidadeByIndex(y)->getOrdem() == 0)
			{
				//jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j].getRecurso()->getIdFonte());
				for (int i = 0; i < mapa.size(); i++)
				{
					for (int j = 0; j < mapa[i].size(); j++)
					{
						for (int x = 0; x < mapa[i][j].getNumUnidades(); x++)
						{
							if (mapa[i][j].getUnidadeByIndex(x)->getNomeUnidade() == p->getUnidadeByIndex(y)->getNomeUnidade())
							{
								if (i == 0 && j == 0)
								{
									if (mapa[i][j + 1].getRecurso() != NULL)
									{
										if (mapa[i][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									if (mapa[i + 1][j + 1].getRecurso() != NULL)
									{
										if (mapa[i + 1][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									if (mapa[i + 1][j].getRecurso() != NULL)
									{
										if (mapa[i + 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
								}
								//fim valor 0 de 0
								if (i == mapa.size() && j == mapa[i].size())//canto
								{
									if (mapa[i - 1][j - 1].getRecurso() != NULL)
									{
										if (mapa[i - 1][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									if (mapa[i - 1][j].getRecurso() != NULL)
									{
										if (mapa[i - 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
									if (mapa[i][j - 1].getRecurso() != NULL)
									{
										if (mapa[i][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}

								}//fim do valor 36 de 36
								if (i == mapa.size() && j == 0)//canto
								{
									if (mapa[i][j + 1].getRecurso() != NULL)
									{
										if (mapa[i][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									if (mapa[i - 1][j].getRecurso() != NULL)
									{
										if (mapa[i - 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
									if (mapa[i - 1][j + 1].getRecurso() != NULL)
									{
										if (mapa[i - 1][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
								}//36 de 0
								if (i == 0 && j == mapa[i].size())//canto
								{


									if (mapa[i][j - 1].getRecurso() != NULL)
									{
										if (mapa[i][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									if (mapa[i - 1][j].getRecurso() != NULL)
									{
										if (mapa[i - 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
									if (mapa[i - 1][j - 1].getRecurso() != NULL)
									{
										if (mapa[i - 1][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}


								}//fim do valor de 0 de 36
								if (i - 1 < 0)//baixo
								{
									if (mapa[i][j - 1].getRecurso() != NULL)
									{
										if (mapa[i][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i][j + 1].getRecurso() != NULL)
									{
										if (mapa[i][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i + 1][j - 1].getRecurso() != NULL)
									{
										if (mapa[i + 1][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i + 1][j].getRecurso() != NULL)
									{
										if (mapa[i + 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i + 1][j + 1].getRecurso() != NULL)
									{
										if (mapa[i + 1][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
								}
								if (j +1 > mapa[i].size())//esquerda
								{
									if (mapa[i][j - 1].getRecurso() != NULL)
									{
										if (mapa[i][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}

									else if (mapa[i + 1][j - 1].getRecurso() != NULL)
									{
										if (mapa[i + 1][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i + 1][j].getRecurso() != NULL)
									{
										if (mapa[i + 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i - 1][j - 1].getRecurso() != NULL)
									{
										if (mapa[i - 1][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i - 1][j].getRecurso() != NULL)
									{
										if (mapa[i - 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
								}
								if (j -1 < 0)//limite esquerda
								{
									if (mapa[i - 1][j + 1].getRecurso() != NULL)
									{
										if (mapa[i - 1][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i][j + 1].getRecurso() != NULL)
									{
										if (mapa[i][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i - 1][j].getRecurso() != NULL)
									{
										if (mapa[i - 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i + 1][j].getRecurso() != NULL)
									{
										if (mapa[i + 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
											
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i + 1][j + 1].getRecurso() != NULL)
									{
										if (mapa[i + 1][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte()); 
											break;
										}
										else if (mapa[i + 1][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
								}
								if (i + 1 >= mapa.size())//topo
								{
									if (mapa[i][j - 1].getRecurso() != NULL)
									{
										if (mapa[i][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i][j + 1].getRecurso() != NULL)
									{
										if (mapa[i][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i - 1][j + 1].getRecurso() != NULL)
									{
										if (mapa[i - 1][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i - 1][j - 1].getRecurso() != NULL)
									{
										if (mapa[i - 1][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i - 1][j].getRecurso() != NULL)
									{
										if (mapa[i - 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
								}
								else//meios
								{
									if (mapa[i][j - 1].getRecurso() != NULL)
									{
										if (mapa[i][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i][j + 1].getRecurso() != NULL)
									{
										if (mapa[i][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i - 1][j + 1].getRecurso() != NULL)
									{
										if (mapa[i - 1][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i - 1][j - 1].getRecurso() != NULL)
									{
										if (mapa[i - 1][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i - 1][j].getRecurso() != NULL)
									{
										if (mapa[i - 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i - 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i - 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i + 1][j].getRecurso() != NULL)
									{
										if (mapa[i + 1][j].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i + 1][j - 1].getRecurso() != NULL)
									{
										if (mapa[i + 1][j - 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j - 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j - 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j - 1].getRecurso()->getIdFonte());
											break;
										}
									}
									else if (mapa[i + 1][j + 1].getRecurso() != NULL)
									{
										if (mapa[i + 1][j + 1].getRecurso()->getNome() == "MIN" && p->getOuro() < 100)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j + 1].getRecurso()->getNome() == "PED" && p->getPedra() < 200)
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
										else if (mapa[i + 1][j + 1].getRecurso()->getNome() == "FLO")
										{
											jog->verificaComando("mina " + p->getUnidadeByIndex(y)->getNomeUnidade() + " " + mapa[i + 1][j + 1].getRecurso()->getIdFonte());
											break;
										}
									}
									
								}//fim meios
								jog->verificaComando("go " + p->getUnidadeByIndex(y)->getNomeUnidade() + " 1 0");
								//jog->verificaComando("");
								//this->EncontrarRecursos(mapa, jog);
								break;
							}
						
							
							
							
						
						}
						
					}
				}

			}
		}
	}
}
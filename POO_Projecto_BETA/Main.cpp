#include <iostream>
#include <string>
#include <vector>
#include "Consola.h"
#include "Jogo.h"

#pragma warning(push)
#pragma warning(disable: 4996)
//#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void main(){
	Consola console;
	
	Jogo * game = new Jogo;
	string usrCmd;

	console.setScreenSize(45, 80);
	
	while (true)
	{
		console.clrscr();
		game->drawInterface();

		getline(cin, usrCmd); //Stdin

		game->verificaComando(usrCmd);
		//game->iterar();
	}
	delete game;
}
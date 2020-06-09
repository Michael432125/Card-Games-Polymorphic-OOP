#include <iostream>
#include <iomanip>

#include "BaseGame.h"

using namespace std;


BaseGame::BaseGame(Deck d, BasePlayer* p):
	player(p),deck(d){}

Deck BaseGame::getDeck() const
{
	return deck;
}

void BaseGame::setDeck(const Deck&d)
{
	deck = d;
}

BasePlayer* BaseGame::getPlayer() const
{
	return player;
}

void BaseGame::setPlayer(BasePlayer* p)
{
	player = p;
}

void BaseGame::gameLogic()
{
	deck.populate();

	deck.shuffle();
}




void BaseGame::win()
{
	cout << "\n************************************";
	cout << "\n******* Congratulations!!!! ********";
	cout << "\n************************************";
}

void BaseGame::intro()
{
	cout << "\nCard Guessing Game V1.0\n@Author: Michael Cruz Cerver\n@Date: 20/03/2020\n\n";
}







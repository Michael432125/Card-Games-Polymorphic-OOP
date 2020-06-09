#ifndef BASEGAME_H_
#define BASEGAME_H_

#include "Deck.h"
#include "BasePlayer.h"
#include <vector>

class BaseGame
{
public:

	BaseGame(Deck, BasePlayer*);

	Deck getDeck() const;
	void setDeck(const Deck &);

	BasePlayer* getPlayer()const;

	virtual void gameLogic()=0;
	//virtual void dealTo() ;

	virtual void win();
	virtual void intro();

	virtual void setPlayer(BasePlayer*);


private:
	Deck deck;
	BasePlayer* player;
};

#endif /*BASEGAME_H_*/
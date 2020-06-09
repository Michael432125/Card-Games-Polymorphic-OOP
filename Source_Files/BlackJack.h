#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include "BaseGame.h"
#include "BlackJackPlayer.h"
#include "Deck.h"
#include <vector>


class BlackJack :
	public BaseGame
{
public:
	BlackJack(const Deck&, BlackJackPlayer*, BlackJackPlayer*, size_t=0);

	virtual void gameLogic() override;


	void dealTo(BlackJackPlayer*);

	virtual void intro() override;
	virtual void win(BlackJackPlayer* p);
	void bust(BlackJackPlayer*);


	BlackJackPlayer createPlayer() const;

	void printRules()const;

private:
	BlackJackPlayer* house;
	BlackJackPlayer* player;
	const size_t max = 21;
	size_t round;
};
#endif /*BLACKJACK_H_*/


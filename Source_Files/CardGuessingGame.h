#ifndef CARDGUESSINGGAME_H_
#define CARDGUESSINGGAME_H_

#include "Deck.h"
#include "GGPlayer.h"
#include "BaseGame.h"


class CardGuessingGame: public BaseGame{
public:
	CardGuessingGame(const Deck&, Card, GGPlayer*, size_t = 0);

	virtual void gameLogic() override;

	virtual void deal();


	virtual void intro() override;
	virtual void win() override;

	GGPlayer createPlayer() const;
private:
	Card dealtCard;
	size_t round=0;
	GGPlayer* player;



};
#endif /*CARDGUESSINGGAME*/

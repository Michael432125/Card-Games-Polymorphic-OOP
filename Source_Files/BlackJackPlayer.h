#ifndef BLACKJACKPLAYER_H_
#define BLACKJACKPLAYER_H_

#include "BasePlayer.h"
class BlackJackPlayer :
	public BasePlayer
{
public:
	BlackJackPlayer(const std::string&, const Hand&,std::vector<bool>);
	virtual ~BlackJackPlayer() {
	}

	void setRoundResult(const bool&);
	std::vector<bool> getRoundVec()const;

	void addToHand(const Card&);
	Hand getHand()const;
	void clearHand();
	size_t getHandTotal()const;

	virtual void print() const;

	virtual void printHand(bool) const;

	virtual void printStats() const;

private:
	Hand hand;
	//double pot;

	std::vector<bool> stats;
};

#endif /*BLACKJACKPLAYER_H_*/


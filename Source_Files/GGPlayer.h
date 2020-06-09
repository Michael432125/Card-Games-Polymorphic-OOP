#ifndef GGPLAYER_H_
#define GGPLAYER_H_

#include "BasePlayer.h"
class GGPlayer :
	public BasePlayer
{
public:
	
	GGPlayer(std::vector<size_t>, const std::string & );
	virtual ~GGPlayer() {
	}

	void addGuessNo(const size_t&);

	std::vector<size_t> getGuesses()const;



	virtual void print() const;

	virtual void printStats() const ;

private:
	std::vector<size_t> guessVector;
};

#endif /*GGPLAYER_H_*/

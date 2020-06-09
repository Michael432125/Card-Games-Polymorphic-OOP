#ifndef BASEPLAYER_H_
#define BASEPLAYER_H_

#include <string>
#include "Hand.h"

class BasePlayer
{
public:
	BasePlayer(const std::string &);

	void setName(const std::string&);

	std::string getName()const;

	virtual void print() const;
private:
	std::string name;
};

#endif /*BASEPLAYER_H_*/


#include "BasePlayer.h"

using namespace std;

BasePlayer::BasePlayer(const std::string& n):
	name(n) {}

void BasePlayer::setName(const std::string &n)
{
	if (n != "") {
		name = n;
	}
	else {
		throw invalid_argument("Name cannot be empty");
	}
}

std::string BasePlayer::getName() const
{
	return name;
}

void BasePlayer::print() const
{
	cout << "Player: " << getName() << "\n";
}

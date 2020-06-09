#include "GGPlayer.h"

using namespace std;

GGPlayer::GGPlayer(vector<size_t> guesses, const string& name ):
	BasePlayer(name), guessVector(guesses){
}



void GGPlayer::addGuessNo(const size_t &round)
{

	if(guessVector.size() < round+1) {
		guessVector.push_back(1);
	}
	else {
		guessVector[round] = guessVector[round] + 1;
	}
}

vector<size_t> GGPlayer::getGuesses() const
{
	return guessVector;
}

void GGPlayer::print() const
{
	cout << "Guessing Game ";
	BasePlayer::print();
	printStats();
}

void GGPlayer::printStats() const
{
	size_t size = guessVector.size();
	cout << "\n Guess Statistics\n";
	for (size_t count = 0; count < size; ++count) {
		cout << "round " << count + 1 << ":";
		//print stars
		for (size_t n = 0; n < guessVector[count]; ++n) {
			cout << "*";
		}
		cout << "\n";
	}
}




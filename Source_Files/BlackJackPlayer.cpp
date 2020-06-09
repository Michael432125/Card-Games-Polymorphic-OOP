#include "BlackJackPlayer.h"

using namespace std;

BlackJackPlayer::BlackJackPlayer(const string&name, const Hand& h,vector<bool>s):
	BasePlayer(name), hand(h), stats(s){
}

void BlackJackPlayer::setRoundResult(const bool&result)
{
	stats.push_back(result);
}

std::vector<bool> BlackJackPlayer::getRoundVec() const
{
	return stats;
}

void BlackJackPlayer::addToHand(const Card&card)
{
	hand.push(card);
}

Hand BlackJackPlayer::getHand() const
{
	return hand;
}

void BlackJackPlayer::clearHand()
{
	hand.clear();
}

size_t BlackJackPlayer::getHandTotal() const
{
	Hand temp = getHand();
	int total = 0;
	while (!temp.isEmpty()) {
		Card n = temp.top();
		int val = static_cast<typename std::underlying_type<Face>::type>(n.getFace());
		if (val > 10) {
			total += 10;
		}
		else {
			total += val;
		}
		temp.pop();
	}

	return total;
}

void BlackJackPlayer::print() const
{
	cout << "BlackJack ";
	BasePlayer::print();
	printStats();
}

void BlackJackPlayer::printHand(bool visible) const
{
	Hand hand = getHand();
	hand.setHandVisibility(visible);
	cout << "\n\n" << BasePlayer::getName() << "'s hand: \n";

	hand.print();
	if (visible) {
		cout << "\nValue: " << getHandTotal() <<"\n";
	}
}

void BlackJackPlayer::printStats() const
{
	size_t size = stats.size();
	cout << "\nBlackJack Statistics:\n";

	cout << "\nRounds: " << size << "\n";

	for (size_t count = 0; count < size; ++count) {
		cout << "round " << count + 1 << ":";
		//print round outcome
		if (stats[count]) {
			cout << "Won";
		}
		else {
			cout << "Lost";
		}
		cout << "\n";
	}
}

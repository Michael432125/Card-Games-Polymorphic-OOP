#ifndef DECK_H_
#define DECK_H_

#include <deque>
#include <random>

#include "Hand.h"

class Deck: public Hand {
public:

	void push(const Card& pushValue) { 
		if (isFull()) {
			std::cout << "\nDeck is Full.\n";
		}
		else {
			hand.push_back(pushValue);
		}
	}

	bool isFull() const { return hand.size()>=maxDeckSize; }


	void shuffle() {
		if (isEmpty()) {
			std::cout << "\nDeck is Empty\n";
		}
		else { 
			std::random_shuffle(hand.begin(), hand.end()); 
		}
	}


	void populate() {
		if (isEmpty()) {
			for (Suit s = Suit::Begin; s < Suit::End; s = Suit((int)s + 1)) {
				for (Face f = Face::Ace; f < Face::End; f =Face((int)f + 1)) {
					Card card = Card(s,f, false);
					push(card);
				}
			}
		}
		else {
			std::cout << "\nDeck needs to be Empty\n";
		}
	}

private:
	//std::deque<Card> hand;
	size_t maxDeckSize= 52;
};
#endif /*DECK_H_*/
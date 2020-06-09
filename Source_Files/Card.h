#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <iomanip>
#include <vector>

#include <map>



enum class Suit {
	Begin, Diamonds = Begin, Hearts, Spades, Clubs, End, Invalid
};

enum class Face {
	Ace = 1, _2 = 2, _3 = 3, _4 = 4, _5 = 5, _6 = 6, _7 = 7, _8 = 8, _9 = 9, _10 = 10, Jack = 11, Queen = 12, King = 13, End, Invalid
};

class Card {
public:



	Card(const Suit&, const Face&, bool);



	Suit getSuit() const;
	void setSuit(const Suit&);
	Face getFace() const;
	void setFace(const Face&);

	void setVisibility(const bool &);
	bool isVisible()const;

	std::vector<std::string> getCardLines()const;


	friend std::ostream& operator<<(std::ostream&, const Card&);

	friend bool operator<(const Card&, const Card&);
	friend bool operator==(const Card&, const Card&);
	
	void fromString(const std::string &);

	friend std::string ToString(const Suit &value);
	friend std::string ToString(const Face & value);
	friend std::string ToString(const Card& value);
	
private:
	Suit suit;
	Face face;
	bool visible;

};


#endif /*CARD_H_*/
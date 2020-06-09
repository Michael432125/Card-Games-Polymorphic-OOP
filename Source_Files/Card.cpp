#include <iostream>
#include <iomanip>

#include <string>
#include <stdio.h>
#include <clocale>

#include "Card.h"

using namespace std;

Card::Card(const Suit& s, const Face& f, bool v=false) :
	suit(s), face(f), visible(v) {}

Suit Card::getSuit() const
{
	return suit;
}

void Card::setSuit(const Suit &s)
{
	suit = s;
}

Face Card::getFace() const
{
	return face;
}

void Card::setFace(const Face &f)
{
	face = f;
}

void Card::setVisibility(const bool &v)
{
	visible = v;
}

bool Card::isVisible() const
{
	return visible;
}

string ToString(const Suit& value);
string ToString(const Face& value);

vector<string> Card::getCardLines() const
{
	string faceString = ToString(face);

	if (faceString.size() != 2) {
		faceString = (faceString.front());
		faceString += " ";
	}
	string suitString (1, ToString(suit).front());

	vector<string> card(8);

	card[0]= " _________ ";

	if (visible) {
		card[1] = "|         |";
		card[2] = "| " + faceString + "      |";
		card[3] = "|         |";
		card[4] = "|    "+suitString+"    |";
		card[5] = "|         |";
		card[6] = "|       " + faceString +"|";
	}
	else {
		fill_n(card.begin() + 1, 6, "|:::::::::|");
	}

	card[7] = "|_________|";
	return card;
}


string ToString(const Face &value)
{
	int cardFace = static_cast<typename std::underlying_type<Face>::type>(value);
	switch (value)
	{
	case Face::Ace: return "Ace"; break;
	case Face::Jack: return "Jack"; break;
	case Face::Queen: return "Queen"; break;
	case Face::King: return "King"; break;

	default: return to_string(cardFace);  break;
	}

	return "";
}

string ToString(const Suit& value)
{
	switch (value)
	{
	case Suit::Diamonds: return "Diamonds"; break;
	case Suit::Hearts: return "Hearts"; break;
	case Suit::Spades: return "Spades"; break;
	case Suit::Clubs: return "Clubs"; break;
	}

	return "";
}

string ToString(const Card& value)
{
	return ToString(value.getFace()) + " of " + ToString(value.getSuit());
}

void Card::fromString(const string & str) {

	string wordList[3];
	string word = "";
	int counter = 0;
	for (auto c : str) {
		
		if (c == ' ') {
			wordList[counter] = word;
			word = "";
			counter++;
		}
		else {
			char temp = tolower(c);
			word = word + temp;
		}
	}
	wordList[counter]=word;
	
	Suit s ;
	
	if (wordList[2] == "diamonds") {
		s = Suit::Diamonds;
	}
	else if (wordList[2] == "hearts") {
		s = Suit::Hearts;
	}
	else if (wordList[2] == "spades") {
		s = Suit::Spades;
	}else if (wordList[2] == "clubs") {
		s = Suit::Clubs;
	}
	else {
		s = Suit::Invalid;
	}

	Face f;

	if (wordList[0]=="ace") {
		f = Face::Ace;
	}
	else if (wordList[0] == "jack") {
		f = Face::Jack;
	}
	else if (wordList[0] == "queen") {
		f = Face::Queen;
	}
	else if (wordList[0] == "king") {
		f = Face::King;
	}
	else {
		string temp = wordList[0];
		int value = 0;
		try {
			value = stoi(temp);
		}
		catch (invalid_argument & e) {

		}
		catch (out_of_range & e) {

		}
		catch (...) {

		}
		
		if (value != 0) {
			f = (Face)value;
		}
		else {
			f = Face::Invalid;
		}
		
		
	}

	setSuit(s);
	setFace(f);
}

ostream& operator<<(ostream& out, const Card& card) {



	out << "\n\n";

	if (card.getFace() != Face::Invalid && card.getSuit() != Suit::Invalid) {
		vector<string> cardI = card.getCardLines();

		for (string line : cardI) {
			out << "  " << line << "\n";
		}

		if (card.isVisible()) {
			out << ToString(card);
		}
	}else {
		out << "Invalid Card\n";
	}


	return out;
}

bool operator<(const Card& card1, const Card& card2)
{
	int cardface1 = static_cast<typename std::underlying_type<Face>::type>(card1.getFace());
	int cardface2 = static_cast<typename std::underlying_type<Face>::type>(card2.getFace());
	return cardface1 < cardface2;
}

bool operator==(const Card& card1, const Card& card2)
{
	bool s = card1.getSuit() == card2.getSuit();
	bool f = card1 < card2 || card2 < card1;
	return s && !f;
}


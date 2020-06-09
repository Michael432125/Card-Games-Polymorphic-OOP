#include <iostream>
#include <iomanip>

#include <string>
#include "CardGuessingGame.h"

using namespace std;
CardGuessingGame::CardGuessingGame(const Deck& d,Card c , GGPlayer* p, size_t r) :
	BaseGame(d, p), dealtCard(c), round(r), player(p){}

void CardGuessingGame::gameLogic()
{

	intro();

	GGPlayer* player = &createPlayer();
	setPlayer(player);

	BaseGame::gameLogic();


	while (true) {
		deal();

		while (!dealtCard.isVisible()) {
			string input = "";
			cout << "\nGuess the Card(e.g. Ace of Spades):\n";
			cin.clear();
			getline(cin, input);
			
			if (input == "quit") {
				exit(0);
			}
			else if (input == "stats") {

				player->print();
			}
			else {
				Card result(Suit::Clubs, Face::Ace, false);

				result.fromString(input);
				cout << "\n\n";
				if (result.getFace() != Face::Invalid && result.getSuit() != Suit::Invalid) {

					player->addGuessNo(round);

					if (dealtCard < result) {
						cout << "\nFace value is too large.";
					}
					else if (result < dealtCard) {
						cout << "\nFace value is too small.";
					}

					if (result.getSuit() != dealtCard.getSuit()) {
						cout << "\nSuit is not correct";
					}

					if (result == dealtCard) {
						win();
					}

				}
				else {
					cout << "Card is not valid";
				}

				cout << "\n\n";
			}
		}

		round++;
	}
	

}


void CardGuessingGame::deal()
{
	Deck deck = getDeck();
	dealtCard = deck.top();
	deck.pop();
	setDeck(deck);
	cout << dealtCard;
}


void CardGuessingGame::intro()
{
	BaseGame::intro();
	cout << "\n   _____              _    _____                     _                _____                      ";
	cout << "\n  / ____|            | |  / ____|                   (_)              / ____|                     ";
	cout << "\n | |     __ _ _ __ __| | | |  __ _   _  ___  ___ ___ _ _ __   __ _  | |  __  __ _ _ __ ___   ___";
	cout << "\n | |    / _` | '__/ _` | | | |_ | | | |/ _ \\/ __/ __| | '_ \\ / _` | | | |_ |/ _` | '_ ` _ \\ / _ \\";
	cout << "\n | |___| (_| | | | (_| | | |__| | |_| |  __/\\__ \\__ \\ | | | | (_| | | |__| | (_| | | | | | |  __/";
	cout << "\n  \\_____\\__,_|_|  \\__,_|  \\_____|\\__,_|\\___||___/___/_|_| |_|\\__, |  \\_____|\\__,_|_| |_| |_|\\___|";
	cout << "\n                                                              __/ |                              ";
	cout << "\n                                                             |___/                               ";
	cout << "\n\nGuess the value of the hidden card in the fewest number of Guesses!!!";
	cout << "\nControls:\n - input 'quit' to quit the game at any time.\n - input 'stats' to see you scores over time\n";
}

void CardGuessingGame::win(){
	
	BaseGame::win();
	dealtCard.setVisibility(true);
	cout << dealtCard;
	vector<size_t> temp = player->getGuesses();
	cout << "\nNumber of Guesses: " << temp[round];
}

GGPlayer CardGuessingGame::createPlayer() const
{
	string n;
	cout << "\nEnter Name: ";
	cin >> n;
	cin.ignore();
	vector<size_t> g {0};
	GGPlayer player(g,n);
	return player;
}

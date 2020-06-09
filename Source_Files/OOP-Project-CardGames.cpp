
#include <iostream>
#include <iomanip>

#include<string>
#include<vector>

#include "Card.h"
#include "Deck.h"
#include "GGPlayer.h"
#include "BlackJackPlayer.h"

#include "CardGuessingGame.h"
#include "BlackJack.h"

using namespace std;

void virtualViaPointer(BaseGame*); //prototype

int main()
{


    vector<BaseGame*> games(2);

    //Card Guessing Game
    vector<size_t> g{ 0 };
    string name = "";
    GGPlayer p(g, name);
    Card temp(Suit::Clubs, Face::_3, false);
    Deck deck;

    size_t t = 0;
    CardGuessingGame n = CardGuessingGame(deck, temp, &p, t);
    


    //Blackjack

	vector<bool> boolVec{};
	Hand h;
	BlackJackPlayer player(name, h, boolVec);
	BlackJackPlayer house(name, h, boolVec);


	BlackJack bj = BlackJack(deck, &player, &house);



    games[0] = &n;
    games[1] = &bj;
    

    cout << "\nThe Casino";

    cout << "Card Guessing Game[1], BlackJack [2]: ";

    string input = "";
    cin >> input;
    cin.ignore();
    
    if (input == "1") {

        virtualViaPointer(games[0]);
    }
    else if (input == "2") {
        virtualViaPointer(games[1]);
    }
    else {
        cout << "\nNot a valid input";
    }
}

void virtualViaPointer(BaseGame* baseClassPtr) {
    baseClassPtr->gameLogic();
}

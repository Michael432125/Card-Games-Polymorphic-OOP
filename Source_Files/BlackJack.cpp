#include "BlackJack.h"

using namespace std;
BlackJack::BlackJack(const Deck&d, BlackJackPlayer*p, BlackJackPlayer*h, size_t r):
	BaseGame(d,p), house(h), round(r), player(p){
	house->setName("Bank");

}

void BlackJack::gameLogic()
{
	intro();

	BlackJackPlayer* player = &createPlayer();
	setPlayer(player);

	BaseGame::gameLogic();


	while (true) {
		house->clearHand();
		dealTo(house);
		dealTo(house);
		house->printHand(false);


		player->clearHand();
		dealTo(player);
		dealTo(player);

		player->printHand(true);

		house->printHand(true);

		while (true) {
			string input = "";
			cout << "\n[s]tand or [h]it\n";
			getline(cin, input);

			if (input == "stats") {
				player->print();
			}
			else if (input == "rules") {
				printRules();
			}
			else {
				if (input == "s") {
					while (house->getHandTotal() <= player->getHandTotal() && house->getHand().size() < 5) {
						dealTo(house);
						if (house->getHandTotal() > max) {
							house->printHand(true);
							bust(house);
							player->setRoundResult(true);
							break;
						}
						else {
							house->printHand(true);
						}
					}
					break;

				}
				else if (input == "h") {
					dealTo(player);

					if (player->getHandTotal() > max) {
						player->printHand(true);
						bust(player);
						player->setRoundResult(false);
						break;
					}
					else {
						player->printHand(true);
					}
				}
				else {
					cout << "\nNot a valid input";
				}
			}

		}
		if (player->getHandTotal() > house->getHandTotal()&& player->getHandTotal()<=max && house->getHandTotal() <=max) {
			win(player);
			player->setRoundResult(true);
		}
		else if (player->getHandTotal() < house->getHandTotal() && player->getHandTotal() <= max && house->getHandTotal() <= max) {
			win(house);
			player->setRoundResult(false);
		}
		string input = "";
		cout << "\n[q]uit or [c]ontinue\n";
		getline(cin, input);

		if (input == "q") {
			player->printStats();
			break;
		}

		round++;
	}
	


	
}


void BlackJack::dealTo(BlackJackPlayer* p)
{
	if (p->getHand().size() < 5) {
		Deck deck = getDeck();
		if (deck.isEmpty()) {
			BaseGame::gameLogic();
			cout << "\nDeck is Empty!!!";
			cout << "\nNew deck added!!!";
		}

		cout << "\n"<<p->getName() <<" is dealt a card.";

		Card temp = deck.top();
		deck.pop();
		setDeck(deck);
		p->addToHand(temp);
	}

}

void BlackJack::intro()
{
	BaseGame::intro();
	cout << "\n.______    __          ___       ______  __  ___       __       ___       ______  __  ___ ";
	cout << "\n|   _  \\  |  |        /   \\     /      ||  |/  /      |  |     /   \\     /      ||  |/  /";
	cout << "\n|  |_)  | |  |       /  ^  \\   |  ,----'|  '  /       |  |    /  ^  \\   |  ,----'|  '  /";
	cout << "\n|   _ <   |  |      /  /_\\  \\  |  |     |    <  .--.  |  |   /  /_\\  \\  |  |     |    <";
	cout << "\n|  |_)  | |  `----./  _____  \\ |  `----.|  .  \\ |  `--'  |  /  _____  \\ |  `----.|  .  \\  ";
	cout << "\n|______/  |_______/__/     \\__\\ \\______||__|\\__\\ \\______/  /__/     \\__\\ \\______||__|\\__\\ ";
	cout << "\n\nTry to beat the Bank!!!";
	cout << "\nControls:\n - input 'rules' to print the games rules.\n - input 'stats' to see you scores over time\n";
}

void BlackJack::win(BlackJackPlayer* p)
{
	string name = p->getName();


	if (p == house) {
		//house has won
		cout <<"\n"<< "Bank Wins!!"<< "\n";
		cout << "\n" << name << " has Lost!!" << "\n";

	}
	else {
		//player has won
		BaseGame::win();
		cout << "\n" <<"Bank has Lost!!" << "\n";
		cout << "\n" << name << " has Won!!"<< "\n";
	}
	

}

void BlackJack::bust(BlackJackPlayer* p)
{
	string name = p->getName();

	cout << "\n" << name << " has bust!!" << "\n";

	if (p == house) {
		win(player);
	}
	else {
		win(house);
	}
}


BlackJackPlayer BlackJack::createPlayer() const
{
	string n;
	cout << "\nEnter Name: ";
	cin >> n;
	cin.ignore();
	vector<bool> g{ };
	Hand h;
	BlackJackPlayer player(n,h,g);
	return player;
}

void BlackJack::printRules() const
{
	cout << "\nBlackJack Rules:";
	cout << "\n1. ace to 9 according to pip value, tens and royals are worth 10.";
	//cout << "\n2. "
}

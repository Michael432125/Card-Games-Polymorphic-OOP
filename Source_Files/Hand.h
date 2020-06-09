#ifndef HAND_H_
#define HAND_H_

#include <deque>

#include <string>
#include <vector>
#include "Card.h"


class Hand {
public:
	
	std::deque<Card> hand; //internal representation of Hand

	Card top() const {
		if (isEmpty()) {
			std::cout << "\nDeck is Empty.\n";
		}
		else {
			return hand.front();
		}
	}

	void push(const Card& pushValue) { hand.push_back(pushValue); }

	void pop() {
		if (isEmpty()) {
			std::cout << "\nDeck is Empty.\n";
		}
		else {
			hand.pop_front();
		}
	}

	void clear() {
		while (!isEmpty()) {
			pop();
		}
	}

	void setHandVisibility(const bool& visible) {
		Hand temp;
		while (!isEmpty()) {
			temp.push(top());
			pop();
		}
		while (!temp.isEmpty()) {
			Card c = temp.top();
			c.setVisibility(visible);
			push(c);
			temp.pop();
		}
	}

	bool isEmpty() const { return hand.empty(); }

	size_t size() const { return hand.size(); }

	void print(){

		Hand temp;
		while(!isEmpty()){
			temp.push(top());
			pop();
		}
		

		std::vector<std::vector<std::string>> handLines{};

		while (!temp.isEmpty()) {

			handLines.push_back(temp.top().getCardLines());
			push(temp.top());
			temp.pop();
			
		}

		for (unsigned int j = 0; j < handLines[0].size(); j++) {

			for (unsigned int i = 0; i < handLines.size(); i++) {
				std::cout << handLines[i][j] << "    ";
			}
			std::cout << "\n";

		}
	}

private:
};




#endif /*Hand_H_*/

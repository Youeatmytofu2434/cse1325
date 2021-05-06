#include"Card.h"
#include<vector>

class Deck
{
	vector<Card> _cards;
	vector<string> _options;
	int next_card;

public:
	void add_card(string, string);
	void add_false_answer(string);
	vector<string> options();
	Card deal();

};
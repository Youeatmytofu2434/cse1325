#include<iostream>
#include<string>
using namespace std;

class Card
{
	string _question;
	string _answer;

public:
	Card(string, string);
	string attempt(string);
	friend ostream& operator << (ostream&, Card&);

};
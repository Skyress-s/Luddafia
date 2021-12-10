#pragma once


#include <iostream>
#include <vector>
#include <conio.h>



using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int Choice(vector<string>, string);
string Spacing(int space, string input);

class Player {
public:
	Player(){}
	virtual ~Player(){}

	std::string name{"N/A"};
	bool isAlive = true;
	bool isProtected = false;
	bool attemptedMurder = false;
	bool bad = false;
	
	virtual std::string GetType();
	virtual void Action(vector<Player*>);
	virtual Player* MakeThisClass();
	void ResolveActions();
	void ResentRelevantVariables();
	vector<string> getPlayerNames(vector<Player*> players, bool withClassTypes);
	

};





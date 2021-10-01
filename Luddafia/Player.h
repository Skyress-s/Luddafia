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

class Player {
public:
	Player(){}
	virtual ~Player(){}

	std::string name{"N/A"};
	bool isAlive = true;
	bool isProtected = false;
	bool attemptedMurder = false;

	std::string virtual GetType();

	void virtual Action(vector<Player*>);

	void ResolveActions();
	
	void ResentRelevantVariables();

};





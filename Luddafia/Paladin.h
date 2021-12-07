#pragma once
#include "Player.h"

#include <iostream>
class Paladin : public Player {
public: 
	Paladin() {}

	std::string GetType() override;
	void Action(vector<Player*>) override;
	Player* MakeThisClass() override;
};


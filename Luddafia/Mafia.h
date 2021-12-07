#pragma once
#include "Player.h"

#include <iostream>
class Mafia : public Player {
public:
	Mafia();

	static bool hasActed;
	std::string GetType() override;
	void Action(vector<Player*>) override;
	Player* MakeThisClass() override;
};


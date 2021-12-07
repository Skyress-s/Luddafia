#pragma once
#include "Player.h"
class Sheriff : public Player {
public:
	Sheriff();

	std::string GetType() override;
	void Action(vector<Player*>) override;
	Player* MakeThisClass() override;


private:

};


#pragma once
#include "Player.h"

#include <iostream>
class Human : public Player {
public:
	Human() {}

	std::string GetType() override;
	void Action() override;
};


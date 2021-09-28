#pragma once
#include "Player.h"

#include <iostream>
class Mafia : public Player {
public:
	Mafia() {}

	std::string GetType() override;
	void Action() override;
};


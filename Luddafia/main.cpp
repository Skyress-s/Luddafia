#include <iostream>

using namespace std;


class Player
{
public:
	Player();
	~Player();

	bool isAlive = true;

private:

};

Player::Player()
{
}

Player::~Player()
{
}

class Mafia : public Player
{
public:
	Mafia();
	~Mafia();

private:

};

Mafia::Mafia()
{
}

Mafia::~Mafia()
{
}

int main() {

	Player test;
	bool woah = test.isAlive;
	std::cout << woah << endl;

	Mafia maf;
	bool Bwaf = maf.isAlive;
	std::cout << Bwaf;
	

}

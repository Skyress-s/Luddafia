#pragma once
#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

namespace test {

	class Player {
	public:
		Player();
		~Player();

		string name{};
		bool isAlive{ true };
		bool isProtected{ false };
		string GetType() {
			return "Player";
		}
	private:

	};
	Player::Player() {
	}
	Player::~Player() {
	}

	class Human : public Player{
	public:
		Human();
		~Human();

		//using Player::GetType;
		string GetType() {
			return "Human";
		}

	private:

	};

	Human::Human() {
	}

	Human::~Human() {
	}

	class Mafia : public Player {
	public:
		Mafia();
		~Mafia();

		void TryToKill(Player& p) {
			if (!p.isProtected) {
				p.isAlive = false;
			}

		}
		string GetType() {
			return "Mafia";
		}

	private:

	};
	Mafia::Mafia() {

	}
	Mafia::~Mafia() {
	}

	class Paladin : public Player{
	public:
		Paladin();
		~Paladin();
		void Protect(Player& p) {
			p.isProtected = true;
		}


	private:

	};
	Paladin::Paladin() {
	}
	Paladin::~Paladin() {
	}


	class AllPlayers {
	public:
		AllPlayers();
		~AllPlayers();

		vector<Player> humans{};
		vector<Mafia> mafias{};

		vector<string> GetallNames() {
			vector<string> names{};

			for (int i = 0; i < humans.size(); i++) {
				names.push_back(humans[i].name);
			}
			for (int i = 0; i < mafias.size(); i++) {
				names.push_back(mafias[i].name);
			}

			return names;

		}

	private:

	};

	AllPlayers::AllPlayers() {
	}

	AllPlayers::~AllPlayers() {
	}


}

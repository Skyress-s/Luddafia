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

	class Paladin {
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

	private:

	};

	AllPlayers::AllPlayers() {
	}

	AllPlayers::~AllPlayers() {
	}


}

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
		Player() {}
		~Player(){}

		string name{};
		bool isAlive{ true };
		bool isProtected{ false };

		virtual string GetType() {
			return "Player";
		}
	private:

	};


	class Human : public Player{
	public:
		Human();
		~Human();

		//using Player::GetType;
		string GetType() final override { // final if none other inheritd/
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
		string GetType() override {
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
		string GetType() override {
			return "Paladin";
		}

	private:

	};
	Paladin::Paladin() {
	}
	Paladin::~Paladin() {
	}


	

}

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };


void GetPlayerNames(vector<string>&);

void CinClear();
int GetRandomNum(int, int);

class Player
{
public:
	Player();
	~Player();

	bool isAlive{true};
	bool isProtected{ false };

	

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

	void TryToKill(Player& p) {
		if (!p.isProtected) { 
			p.isAlive = false; 
		}

	}

private:

};
Mafia::Mafia()
{
}
Mafia::~Mafia()
{
}

class Paladin
{
public:
	Paladin();
	~Paladin();
	void Protect(Player& p) {
		p.isProtected = true;
	}


private:

};
Paladin::Paladin()
{
}
Paladin::~Paladin()
{
}



int main() {
	//the name of the players
	vector<string> names{};
	GetPlayerNames(names);

	//determines how many mafias

	int personsPerMafia = 3; // 4 manes three persons and one mafia
	if (personsPerMafia > names.size()) // ensures there always is atleast ONE mafia ^^
	{
		personsPerMafia = names.size();
	}

	int n = floor((float(names.size()) / (personsPerMafia + 1)));
	cout << "Num of mafias : " << n << endl;

	//debug print
	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << endl;
	}


	//assign the mafias and player
	cout << GetRandomNum(0, names.size());
}


void GetPlayerNames(vector<string>& names) {
	bool accepted = false;
	while (accepted == false)
	{
		string answer{};
		cout << " Please input name / 'q' to exit loop : ";
		getline(cin, answer);
		//cin >> answer; // 
		//CinClear();  //why cant i have this ? ? ? !? !? !? !?


		//exit the loop when you have selected all the players you want
		if (answer[0] == 'q' && answer.size() == 1)
		{
			break;
		}

		names.push_back(answer);
	}
}

//void MainGameLoop(vector<string> names)

void CinClear() {
	std::cin.clear(); // clears the cin buffer for errors
	std::cin.ignore(32767, '\n');
	
}

int GetRandomNum(int from, int too) {
	std::uniform_int_distribution<> die{ from, too };
	return die(mersenne);
}

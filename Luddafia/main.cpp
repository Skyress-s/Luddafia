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

	string name{};
	bool isAlive{true};
	bool isProtected{ false };
	string GetType() {
		return "Player";
	}
	

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
	string GetType() {
		return "Mafia";
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

	int numOfMafias = floor((float(names.size()) / (personsPerMafia + 1)));
	cout << "Num of mafias : " << numOfMafias << endl;


	//assign the mafias and players
	
	//generate indexes for random slots
	vector<int> indexes{};

	// make random array
	vector<int> larr{};
	for (int i = 0; i < names.size(); i++)
	{
		larr.push_back(i);
	}

	for (int i = 0; i < numOfMafias; i++)
	{
		int n = GetRandomNum(0, larr.size() - 1 - i);
		indexes.push_back(larr[n]);
		larr.erase(larr.begin() + n);
	}

	cout << endl <<endl;
	for (int i = 0; i < indexes.size(); i++)
	{
		cout << indexes[i] << endl;
	}
	
	//assign them mafias and players


	vector<char> charAssi(names.size(), 'h'); // h for human

	for (int i = 0; i < indexes.size(); i++)
	{
		charAssi[indexes[i]] = 'm';
	}


	cout << endl << endl;
	for (int i = 0; i < charAssi.size(); i++)
	{
		cout << charAssi[i] << endl;
	}

			
	vector<Player> players{};
	vector<Mafia> mafias{};
	for (int i = 0; i < names.size(); i++)
	{
		switch (charAssi[i])
		{
		case 'h':
			
			players.push_back(Player{});
			break;

		case 'm':
			mafias.push_back(Mafia{});
			
			
			break;

		default:
			players.push_back(Player{});
			break;
		}
	}


	//debug display players
	for (int i = 0; i < players.size(); i++)
	{
		cout << players[i].GetType() << " | " << players[i].name << endl;
	}
	for (int i = 0; i < mafias.size(); i++)
	{
		cout << mafias[i].GetType() << " | " << mafias[i].name << endl;
	}



}


void GetPlayerNames(vector<string>& names) {
	bool accepted = false;
	while (accepted == false)
	{
		string answer{};
		cout << " q - finished / input player " << names.size() + 1 << " : ";
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

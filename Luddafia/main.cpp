#include <iostream>
#include <string>
#include <vector>

using namespace std;

void CinClear();

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
	//the name of the players
	vector<string> names{};

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


	//determines how many mafias

	int personsPerMafia = 4;
	if (personsPerMafia > names.size()) // ensures there always is atleast ONE mafia ^^
	{
		personsPerMafia = names.size();
	}

	int n = floor((float(names.size()) / personsPerMafia));
	cout << "Num of mafias : " << n << endl;





	//debug print
	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << endl;
	}

}

void CinClear() {
	std::cin.clear(); // clears the cin buffer for errors
	std::cin.ignore(32767, '\n');
	
}

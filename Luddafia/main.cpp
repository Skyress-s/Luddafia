#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

#include "Player.h"
#include "Human.h"
#include "Mafia.h"
#include "Paladin.h"

//using namespace test;

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };


void CinClear();


int GetRandomNum(int, int);
vector<int> CreateRandomIndexArray(int size) {
	//creates the linear array
	vector<int> larr{};

	for (int i = 0; i < size; i++) {
		larr.push_back(i);
		//cout << larr[i] << endl;
	}

	vector<int> mixedIndexes(size);
	for (int i = 0; i < size; i++) {
		int n = GetRandomNum(0, larr.size() - 1);
		mixedIndexes[i] = larr[n];
		larr.erase(larr.begin() + n);
	}
	/*cout << endl;
	for (int i = 0; i < mixedIndexes.size(); i++) {
		cout << mixedIndexes[i] << endl;
	}
	cout << endl;*/

	return mixedIndexes;
}
vector<string> MixNameVector(vector<string> a_names) {

	vector<int> mixedIndexes = CreateRandomIndexArray(a_names.size());
	vector<string> result(a_names.size());
	for (int i = 0; i < a_names.size(); i++) {
		result[i] = a_names[mixedIndexes[i]];
	}

	return result;
}


void GetPlayerNames(vector<string>&);
void MainGameLoop(vector<Player*>);

void DisplayPlayerStatuses(vector<Player*>);

int main() {

	//the name of the players
	vector<string> names{};
	GetPlayerNames(names);

	//determines how many mafias

	int personsPerMafia = 3; // 3 manes three persons per ONE mafia
	if (personsPerMafia > names.size()) { // ensures there always is atleast ONE mafia ^^
	
		personsPerMafia = names.size();
	}

	
	cout << endl;
	int numOfMafias = floor((float(names.size()) / (personsPerMafia + 1)));
	cout << "Num of mafias : " << numOfMafias << endl << endl;

	//mixes the names randomly
	names = MixNameVector(names);

	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << endl;
	}



	//assign the mafias and players
	
	vector<Player*> players{};
	

	for (int i = 0; i < names.size(); i++) {
		if (i < numOfMafias) {
			Mafia *temp = new Mafia{};
			temp->name = names[i];
			players.push_back(temp);
		}
		else if (i < 1 + numOfMafias) {
			Paladin* temp = new Paladin{};
			temp->name = names[i];
			players.push_back(temp);
		}
		else {
			Human* temp = new Human{};
			temp->name = names[i];
			players.push_back(temp);
		}
	}


	

	MainGameLoop(players);
	


	return 0;
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


void MainGameLoop(vector<Player*> a_players) {
	while (true) {

		//actions
		for (int i = 0; i < a_players.size(); i++) {
			a_players[i]->Action(a_players);
		}

		//resolve actions
		for (int i = 0; i < a_players.size(); i++) {
			a_players[i]->ResolveActions();
			
		}

		//reset relevant variables
		for (int i = 0; i < a_players.size(); i++) {
			a_players[i]->ResentRelevantVariables();
		}

		DisplayPlayerStatuses(a_players);

		// Remove dead players
		for (size_t i = 0; i < a_players.size(); i++) {
			if (!a_players[i]->isAlive) {
				a_players.erase(a_players.begin() + i);
			}
		}

		
		

	}
}


void CinClear() {
	std::cin.clear(); // clears the cin buffer for errors
	std::cin.ignore(32767, '\n');
	
}

int GetRandomNum(int from, int too) {
	std::uniform_int_distribution<> die{ from, too };
	return die(mersenne);
}

string Spacing(int space) {
	string output{};
	for (int i = 0; i < space; i++) {
		output += " ";

	}
	//cout << output << "t" << endl;

	return output;
}

void DisplayPlayerStatuses(vector<Player*> a_players) {
	system("cls");
	for (int i = 0; i < a_players.size(); i++) {
		string line{};
		line += a_players[i]->GetType();
		line += Spacing(12 - line.size());

		line += a_players[i]->name;

		line += Spacing(20 - line.size());

		line += "Killed! : " + std::to_string(!a_players[i]->isAlive);

		
		
		cout << line << endl;
	}
	system("pause");
}

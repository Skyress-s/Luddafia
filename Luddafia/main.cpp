#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "classes.h"

using namespace test;

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };


void GetPlayerNames(vector<string>&);
void CinClear();
void MainGameLoop(AllPlayers);


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


	AllPlayers allPlayers{};
	int NAI{}; //Name Assign Index


	for (int i = 0; i < numOfMafias; i++) {
		Mafia temp{};
		temp.name = names[NAI];
		allPlayers.mafias.push_back(temp);
		NAI++;
	}

	int rest = names.size() - numOfMafias;
	for (int i = 0; i < rest; i++) {
		Player temp{};
		temp.name = names[NAI];
		allPlayers.humans.push_back(temp);
		NAI++;
	}
			
	
	


	//debug display players
	for (int i = 0; i < allPlayers.mafias.size(); i++)
	{
		cout << allPlayers.mafias[i].GetType() << "   | " << allPlayers.mafias[i].name << endl;
	}
	for (int i = 0; i < allPlayers.humans.size(); i++)
	{
		cout << allPlayers.humans[i].GetType() << " | " << allPlayers.humans[i].name << endl;
	}

	MainGameLoop(allPlayers);
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

void Day() {
	//implement timer func
	char ans{};
	cout << "Vote player out? y/n : ";
	cin >> ans;
	if (tolower(ans) == 'y') {
		Vote();
	}

	system("pause");

}

void Vote() {
	string ans{};
	cout << "Choose player : ";
	cin >> ans;

	for (size_t i = 0; i < length; i++) {

	}

}

void Night() {
	
}


void MainGameLoop(AllPlayers a_allPlayers) {
	system("cls");
	bool finishedMainLoop = false;
	while (finishedMainLoop == false) {

		Day();

		Vote();

		Night();
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

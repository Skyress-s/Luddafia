#include "FunctionsDecler.h"

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

bool Mafia::hasActed = false;		//have to init the static variable here, outside the class


// definitions
int main() {
	
	//the name of the players
	vector<string> names{};
	GetPlayerNames(names);

	vector<Player*> classes{
		new Human(),
		new Mafia(),
		new Paladin(),
		new Sheriff()
	};
	
	vector<std::pair<Player*, int>> amount = chooseClasses(classes, names);


	//mixes the names randomly
	names = MixNameVector(names);

	//players vector
	vector<Player*> players{};

	//inserts the roles to players
	for (int i = 0; i < amount.size(); i++) {

		//goes the right amoundt og times for <player*, INT>
		for (int j = 0; j < amount[i].second; j++) {
			Player* temp = amount[i].first->MakeThisClass();
			players.push_back(temp);
		}
	}

	//inserts the names
	for (int i = 0; i < players.size(); i++) {
		players[i]->name = names[i];
	}

	//plays the game
	MainGameLoop(players);
	return 0;
}

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

vector<std::pair<Player*, int>> chooseClasses(vector<Player*> classes, vector<string> names) {
	vector<int> amount(classes.size(), 0);

	bool finished{ false };
	int currentChoice{};
	while (!finished) {
		//draws
		system("cls");
		for (int i = 0; i < classes.size(); i++) {
			if (i == currentChoice) {
				cout << " ->  ";
			}
			else {
				cout << "    ";
			}

			cout << amount[i] << "   " << classes[i]->GetType() << endl;
		}
		//draws total number and number needed
		cout << endl;


		int totalNeeded = names.size();

		int currentTotal{};
		for (int i = 0; i < amount.size(); i++) {
			currentTotal += amount[i];
		}
		cout << "current           : " << currentTotal << endl;
		cout << "total needed      : " << totalNeeded << endl;



		//input and
		char act = _getch();


		switch (tolower(act)) {
		case 'a':
			amount[currentChoice]--;
			if (amount[currentChoice] < 0) {
				amount[currentChoice] = 0;
			}
			break;
		case 'd':
			amount[currentChoice]++;
			break;
		case 'w':
			currentChoice--;
			if (currentChoice < 0) {
				currentChoice = classes.size() - 1;
			}
			break;
		case 's':
			currentChoice++;
			if (currentChoice > classes.size() - 1) {
				currentChoice = 0;
			}
			break;
		case ' ':
			if (totalNeeded == currentTotal) {
				finished = true;
			}

			break;
		default:
			break;
		}
	}

	//creates the vector of the player types and the amound
	vector<std::pair<Player*, int>> output{};
	for (int i = 0; i < classes.size(); i++) {
		if (amount[i] > 0) {
			output.push_back(std::pair<Player*, int>(classes[i], amount[i]) );
		}
	}

	return output;
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
		//night ---------------------

		//actions
		for (int i = 0; i < a_players.size(); i++) {
			a_players[i]->Action(a_players);
		}

		//resolve actions
		for (int i = 0; i < a_players.size(); i++) {
			a_players[i]->ResolveActions();
		}

		Mafia::hasActed = false;
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

		//VOTE --------------------------------------
		dayVote(a_players);
	}
}

void dayVote(vector<Player*>& a_players) {
	vector<string> names{};
	for (int i = 0; i < a_players.size(); i++) {
		names.push_back(a_players[i]->name);
	}
	names.push_back("No Consensus");

	int act = Choice(names, "Whom to vote to the noose ? ");
	if (act < names.size() - 1) {
		a_players.erase(a_players.begin() + act);
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
		line += "name : ";
		line += a_players[i]->name;

		line += Spacing(20 - line.size());

		line += "Alive : " + std::to_string(!a_players[i]->isAlive);

		cout << line << endl;
	}
	system("pause");
}
#include "Sheriff.h"

Sheriff::Sheriff() {
	bad = false;
}

std::string Sheriff::GetType() {
	return "Sheriff";
}

void Sheriff::Action(vector<Player*> players) {
	vector<string> options = { "Investigate", "Skip" };

	int act = Choice(options, "Will " + name + " investigate?");
	if (act == 0) {
		vector<string> names = getPlayerNames(players, true);

		act = Choice(names, "Who will " + name + " investigate?");
		
		cout << names[act] << " is a ";
		if (players[act]->bad) {
			cout << "BAD";
		}
		else {
			cout << "GOOD";
		}
		cout << endl;
		system("pause");
	}
	else {
		//skips
	}
}

Player* Sheriff::MakeThisClass() {
	return new Sheriff();
}

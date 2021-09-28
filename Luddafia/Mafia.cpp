#include "Mafia.h"

std::string Mafia::GetType() {
	return "Mafia";
}

void Mafia::Action(vector<Player*> a_players) {
	vector<string> list{ "Kill", "Skip" };
	int act = Choice(list, name);
	if (act == 0) {
		vector<string> playerNames{};
		for (int i = 0; i < a_players.size(); i++) {
			playerNames.push_back(a_players[i]->name);
		}

		act = Choice(playerNames, name);
		a_players[act]->attemptedMurder = true;
	}
}
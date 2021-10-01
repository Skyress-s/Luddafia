#include "Mafia.h"

std::string Mafia::GetType() {
	return "Mafia";
}


void Mafia::Action(vector<Player*> a_players) {
	if (a_players[0]->name == name) { // this requires that the first element of the players vector is always a mafia
		
		vector<string> list{ "Kill", "Skip" };
		int act = Choice(list, "Mafias turn");
		if (act == 0) {
			vector<string> playerNames{};
			for (int i = 0; i < a_players.size(); i++) {
				playerNames.push_back(a_players[i]->name);
			}

			act = Choice(playerNames, name);
			a_players[act]->attemptedMurder = true;
		}
	}
}
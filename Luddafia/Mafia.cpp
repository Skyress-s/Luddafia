#include "Mafia.h"

std::string Mafia::GetType() {
	return "Mafia";
}

bool MafiaHasActed{};
void Mafia::Action(vector<Player*> a_players) {
	if (!MafiaHasActed) { 
		MafiaHasActed = true;
		vector<string> list{ "Kill", "Skip" };
		int act = Choice(list, "Mafias");
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
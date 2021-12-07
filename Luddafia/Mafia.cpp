#include "Mafia.h"


Mafia::Mafia() {
	//Mafia::hasActed = false;
	bad = true;
}

std::string Mafia::GetType() {
	return "Mafia";
	
}


void Mafia::Action(vector<Player*> a_players) {
	if (Mafia::hasActed == false) {
		Mafia::hasActed = true;
		vector<string> list{ "Kill", "Skip" };
		int act = Choice(list, "Mafias turn");
		if (act == 0) {
			vector<string> playerNames{};
			for (int i = 0; i < a_players.size(); i++) {
				playerNames.push_back(a_players[i]->name + "   " + a_players[i]->GetType());
			}

			act = Choice(playerNames, "Whom to kill ?");
			a_players[act]->attemptedMurder = true;
		}
	}
}

Player* Mafia::MakeThisClass() {
	return new Mafia();
}

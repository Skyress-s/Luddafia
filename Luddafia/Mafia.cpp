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
			vector<string> playerNames = getPlayerNames(a_players, true);
			

			act = Choice(playerNames, "Whom to kill ?");
			a_players[act]->attemptedMurder = true;
			//a_players[act]->log.push_back(name + " Tried to kill " + a_players[act]->name);
		}
	}
}

Player* Mafia::MakeThisClass() {
	return new Mafia();
}

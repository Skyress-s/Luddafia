#include "Paladin.h"

std::string Paladin::GetType() {
	return "Paladin";
}

void Paladin::Action(vector<Player*> a_players) {
	vector<string> options{ "Protect", "Skip" };
	int act = Choice(options, "Will " + name + " Protect? ");
	if (act == 0) {
		vector<string> names = getPlayerNames(a_players, true);
		
		act = Choice(names, "Who Will " + name + " Protect ? ");

		a_players[act]->isProtected = true;
	}
}

Player* Paladin::MakeThisClass() {
	return new Paladin();
}

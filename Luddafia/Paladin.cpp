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
		//a_players[act]->log.push_back(name + " Protected " + a_players[act]->name);
	}
}

Player* Paladin::MakeThisClass() {
	return new Paladin();
}

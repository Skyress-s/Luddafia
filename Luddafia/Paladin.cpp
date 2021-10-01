#include "Paladin.h"

std::string Paladin::GetType() {
	return "Paladin";
}

void Paladin::Action(vector<Player*> a_players) {
	vector<string> options{ "Protect", "Skip" };
	int act = Choice(options, "Will " + name + " Protect? ");
	if (act == 0) {
		vector<string> names{};
		for (int i = 0; i < a_players.size(); i++) {
			names.push_back(a_players[i]->name);
		}
		
		act = Choice(names, "Who Will " + name + " Protect ? ");

		a_players[act]->isProtected = true;

	}

}

#include "Human.h"

std::string Human::GetType() {
	return "Human";
}

void Human::Action(vector<Player*> a_players) {
	//vector<string> list{ "a", "b", "c" };
	//Choice(list, name);
}
Player* Human::MakeThisClass() {
	return new Human();
}
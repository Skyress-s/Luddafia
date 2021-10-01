#include "Player.h"

std::string Player::GetType() {
	return "N/A - Player";
}

void Player::Action(vector<Player*> a_players) {
	std::cout << "This i a N/A, PLAYER" << std::endl;
}

void Player::ResolveActions() {
	if (attemptedMurder == true && isProtected == true) {
		isAlive = true;
	}
	else if (attemptedMurder == true && isProtected == false) {
		isAlive = false;
	}
}

void Player::ResentRelevantVariables() {
	isProtected = false;

}


//some functions most of the subclasses use :)
int Choice(vector<string> options, string activePlayer) {
	int currentChoice{};

	bool accAns{};
	while (!accAns) {
		system("cls");
		cout << " | " << activePlayer << "'s action" << endl << endl;
		for (int i = 0; i < options.size(); i++) {
			if (currentChoice == i) {
				cout << " ->   ";
			}
			else {
				cout << "    ";
			}
			cout /* << "Option "*/ << options[i] << endl;

		}

		char input = _getch();
		switch (tolower(input)) {
		case 'w':
			if (currentChoice - 1 < 0) {
				
				break;
			}
			currentChoice += -1;
			break;

		case 's':
			if (currentChoice + 1 >= options.size()) {
				break;
			}
			currentChoice += 1;
			break;

		case ' ':
			accAns = true;
			break;

		default:
			break;
			}

		//system("pause");
	}

	return currentChoice;
}


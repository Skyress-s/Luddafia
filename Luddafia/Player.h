#pragma once


#include <iostream>
#include <vector>
#include <conio.h>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

//int Choice(vector<string> options);

class Player {
public:
	Player(){}
	virtual ~Player(){}

	std::string name{"N/A"};
	bool isAlive = true;
	bool isProtected = false;

	std::string virtual GetType();

	void virtual Action();
};

//some functions most of the subclasses use :)
//int Choice(vector<string> options) {
//	int currentChoice{};
//
//	bool accAns{};
//	while (!accAns) {
//		system("cls");
//
//		for (int i = 0; i < options.size(); i++) {
//			if (currentChoice == i) {
//				cout << " ->   ";
//			}
//			else {
//				cout << "    ";
//			}
//			cout << "Option " << options[i] << endl;
//
//		}
//
//		char input = _getch();
//		switch (tolower(input)) {
//		case 'w':
//			if (currentChoice - 1 < 0) {
//				break;
//			}
//			currentChoice += -1;
//			break;
//
//		case 's':
//			if (currentChoice + 1 >= options.size()) {
//				break;
//			}
//			currentChoice += 1;
//			break;
//
//		case ' ':
//			accAns = true;
//			break;
//
//		default:
//			break;
//		}
//
//		//system("pause");
//	}
//
//	return currentChoice;
//}


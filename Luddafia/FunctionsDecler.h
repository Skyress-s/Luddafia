#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "Player.h"
#include "Human.h"
#include "Mafia.h"
#include "Paladin.h"
#include "Sheriff.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;


void CinClear();
int GetRandomNum(int, int);
void dayVote(vector<Player*>& a_players);
void GetPlayerNames(vector<string>&);
void MainGameLoop(vector<Player*>);
void DisplayPlayerStatuses(vector<Player*>);
vector<int> CreateRandomIndexArray(int size);
vector<string> MixNameVector(vector<string> a_names);
vector<std::pair<Player*, int>> chooseClasses(vector<Player*> classes);

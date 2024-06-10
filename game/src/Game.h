#pragma once
#include <string>

#include "Room.h"
class Game{
public:
	vector<Room*>rooms;
	vector<Room*>activeRooms;
	Game();
	Game(string filepath);
};

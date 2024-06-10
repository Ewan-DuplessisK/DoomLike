#pragma once
#include "Cell.h"
class Room{
public:
	int number;
	vector<Cell>cells;
	void update();
};

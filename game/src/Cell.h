#pragma once
#include <map>
#include <vector>

#include "Static.h"
#include "Entity.h"
using namespace std;
class Cell{
public:
	Vector3 position;
	map<char,Static*> statics;//front,left,right,back,ground,ceiling,middle //walls, ceiling, floor, ramp
	vector<Entity> entities;//player,enemies,bullets,doors
	void update();
	Cell();
};

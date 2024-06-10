#include "Flat.h"

#include <iostream>

void Flat::Hit(/*Entity* other*/BoundingBox bb){
	if(CheckCollisionBoxes(box,/*other->box*/bb)){
		//if(direction)other->movement.x=0;
		//else other->movement.y=0;
		std::cout << "true"<<std::endl;
	}
}

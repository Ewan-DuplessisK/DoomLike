#pragma once
#include "Static.h"
class Flat:public Static{
public:
	bool direction;
	//void Hit(Entity* other) override;
	void Hit(BoundingBox bb) override;
};

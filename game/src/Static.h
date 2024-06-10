#pragma once
#include "Entity.h"
#include "raylib.h"

class Static{
public:
	Vector3 min;
	Vector3 max;
	BoundingBox box = BoundingBox{min,max};
	Model model;
	Texture2D texture;
	//virtual void Hit(Entity* other)=0;
	virtual void Hit(BoundingBox bb)=0;
	void Draw();
	Static(){}
};

#pragma once
#include "raylib.h"

class Entity{
public:
	Vector3 position;
	Vector3 movement;
	BoundingBox box;
	void premove();
	void update();
	void hit();
	void Draw();
};

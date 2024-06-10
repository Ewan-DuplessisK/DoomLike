#include "Cell.h"

#include <iostream>
#include <ostream>

#include "Flat.h"
#include "raymath.h"
Cell::Cell(){
	statics.emplace('f',new Flat);
	Texture2D texture=LoadTexture("game/src/Textures/red-sand-ground-256x256.png");
	statics.at('f')->model=LoadModelFromMesh(GenMeshPlane(4, 4, 1, 1));
	statics.at('f')->model.transform = MatrixMultiply(MatrixTranslate(0,-2,-2),MatrixRotateX(PI/2.0f));
	statics.at('f')->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
	statics.at('f')->box={{-2,2.0f,-2.0f},{2,-2,-2.2f}};
	statics.emplace('g',new Flat);
	statics.at('g')->model=LoadModelFromMesh(GenMeshPlane(4, 4, 4, 4));
	//statics.at('g')->model.transform = MatrixTranslate(0,0,1);//+y=up +x=right +z=back
	statics.at('g')->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
	
}
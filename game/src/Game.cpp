#include "Game.h"

#include <iostream>
#include <ostream>
#include "raymath.h"
#include "rcamera.h"



#define CAMERA_MOVE_SPEED                               0.09f
#define CAMERA_ROTATION_SPEED                           0.03f
#define CAMERA_PAN_SPEED                                0.2f

// Camera mouse movement sensitivity
#define CAMERA_MOUSE_MOVE_SENSITIVITY                   0.003f     // TODO: it should be independant of framerate

// Camera orbital speed in CAMERA_ORBITAL mode
#define CAMERA_ORBITAL_SPEED                            0.5f       // Radians per second


Game::Game(){
	rooms.push_back(new Room);
	rooms[0]->number=0;
	activeRooms.push_back(new Room);
	Cell c;
	rooms[0]->cells.push_back(c);
}


void UpdateCameraCustom(Camera *camera){

    bool moveInWorldPlane = true;
    bool rotateAroundTarget = false;
    bool lockView = true;
    bool rotateUp = false;
	
    // Camera rotation
    if (IsKeyDown(KEY_DOWN)) CameraPitch(camera, -CAMERA_ROTATION_SPEED, lockView, rotateAroundTarget, rotateUp);
    if (IsKeyDown(KEY_UP)) CameraPitch(camera, CAMERA_ROTATION_SPEED, lockView, rotateAroundTarget, rotateUp);
    if (IsKeyDown(KEY_RIGHT)) CameraYaw(camera, -CAMERA_ROTATION_SPEED, rotateAroundTarget);
    if (IsKeyDown(KEY_LEFT)) CameraYaw(camera, CAMERA_ROTATION_SPEED, rotateAroundTarget);

    // Camera movement
	
    // Keyboard support
    if (IsKeyDown(KEY_W)) CameraMoveForward(camera, CAMERA_MOVE_SPEED, moveInWorldPlane);
    if (IsKeyDown(KEY_A)) CameraMoveRight(camera, -CAMERA_MOVE_SPEED, moveInWorldPlane);
    if (IsKeyDown(KEY_S)) CameraMoveForward(camera, -CAMERA_MOVE_SPEED, moveInWorldPlane);
    if (IsKeyDown(KEY_D)) CameraMoveRight(camera, CAMERA_MOVE_SPEED, moveInWorldPlane);
}


int main(int argc, char* argv[]){
	InitWindow(1000,500,"test");
	Game g = Game();
	// Define the camera to look into our 3d world
    Camera camera = { { 0.0f, 2.0f, 2.0f }, { 0.0f, 2.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    // Model drawing position
    Vector3 position = { 0.0f, 0.0f, 0.0f };
	

    SetTargetFPS(20);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCameraCustom(&camera);
    	
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
				for(auto [fst, snd]:g.rooms[0]->cells[0].statics){
					DrawModel(snd->model,position,1.0f,WHITE);
					DrawBoundingBox(snd->box,GREEN);
					DrawBoundingBox(BoundingBox {Vector3Add(camera.position,Vector3{-1,-1,-1}),Vector3Add(camera.position,Vector3{1,1,1})},BLUE);
					snd->Hit(BoundingBox {Vector3Add(camera.position,Vector3{-1,-1,-1}),Vector3Add(camera.position,Vector3{1,1,1})});
				}
               //DrawModel(g.rooms[0]->cells[0].statics[0]->model, position, 1.0f, WHITE);
               DrawGrid(10, 1.0);

            EndMode3D();


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


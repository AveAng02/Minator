
#include <iostream>

#include "raylib.h"

#include "include/Body.h"
#include "include/Scene.h"

#define FPS 60

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    const float timeQuantum = 1.0f / FPS;

    /*
    * Defining a new body
    */
    Minator::Body b1;
    b1.x = (float)screenWidth / 4.0f;
    b1.y = (float)screenHeight / 4.0f;
    b1.radius = 50.0f;
    b1.vx = 120.0f;
    b1.vy = 120.0f;

    /*
    * Defining a new Scene
    */
    Minator::Scene newScene;
    newScene.wallX = screenWidth;
    newScene.wallY = screenHeight;
    newScene.addBody(b1);


    InitWindow(screenWidth, screenHeight, "Minator");

    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        newScene.updateScene(timeQuantum);

        if (newScene.detectCollisions())
            std::cout << "Collided" << std::endl;
        
        BeginDrawing();

        newScene.drawScene();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

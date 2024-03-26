
#include <iostream>

#include "raylib.h"

#include "Core/Body.h"
#include "Core/Scene.h"

#define FPS 60

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    const float timeQuantum = 1.0f / FPS;

    /*
    * Defining a new body
    */
    Minator::Body b1 (GREEN, (float)screenWidth * 0.25f, (float)screenHeight * 0.25f, 50.0f, 25.0f, 120.0f, 120.0f, 0.5f);
    Minator::Body b2 (BLUE,  (float)screenWidth * 0.75f, (float)screenHeight * 0.25f, 50.0f, 25.0f, 120.0f, -120.0f, 0.5f);
    Minator::Body b3 (ORANGE,  (float)screenWidth * 0.5f, (float)screenHeight * 0.5f, 50.0f, 25.0f, -150.0f, 90.0f, 0.5f);
    Minator::Body b4 (PURPLE,  (float)screenWidth * 0.6f, (float)screenHeight * 0.75f, 50.0f, 25.0f, 200.0f, 0.0f, 0.5f);
    Minator::Body b5 (MAGENTA,  (float)screenWidth * 0.75f, (float)screenHeight * 0.75f, 50.0f, 25.0f, -120.0f, 160.0f, 0.5f);


    /*
    * Defining a new Scene
    */
    Minator::Scene newScene (screenWidth, screenHeight);
    newScene.addBody(std::make_shared<Minator::Body>(b1));
    newScene.addBody(std::make_shared<Minator::Body>(b2));
    newScene.addBody(std::make_shared<Minator::Body>(b3));
    newScene.addBody(std::make_shared<Minator::Body>(b4));
    newScene.addBody(std::make_shared<Minator::Body>(b5));


    InitWindow(screenWidth, screenHeight, "Minator");

    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        newScene.updateScene(timeQuantum);

        if (newScene.detectCollisions())
            newScene.updateCollisions();
        
        BeginDrawing();

        newScene.drawScene();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

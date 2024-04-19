
#include <random>
#include <iostream>
#include <vector>

#include "raylib.h"

#include "Core/Vector.h"
#include "Core/AABB.h"
#include "Core/Body.h"
#include "Body/Circle.h"
#include "Body/Square.h"
#include "Body/Triangle.h"
#include "Core/Scene.h"

#define FPS 60

int main(void)
{
    /*
    * TODO :
    * 1. Decouple the tick rate of the Sim from the render. That's because of your collision detection style, It's tied to the framerate of your application. A common pitfall. 
    * 2. Narrow and broad phase collision detection.
    * 3. Friction and damping factor, elasticity (coefficient of restitution)
    * 4. Quad tree or a 2D BVH
    * 5. What parameters of the simulation you would like to expose to the users of your library.
    * 6. Optimize Code
    * 7. Decouple Raylib away from the engine.
    */

    const int screenWidth = 800;
    const int screenHeight = 450;

    const float timeQuantum = 1.0f / FPS;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 501);

    Minator::Scene newScene(screenWidth, screenHeight);

    /*
    * Scene with 1590 bodies set up 
    */
    
    std::vector<std::shared_ptr<Minator::Body>> bodyList;

    int spaceQuantum = 50;
    int c = 0;
    int xcount = screenWidth / 100, ycount = screenHeight / 100;

    Minator::point2D center(100, 100);
    Minator::velocity2D velo;

    for (int i = 0; i < xcount; i++)
    {
        for (int j = 0; j < ycount; j++)
        {
            velo.x = dist(rng) - 250;
            velo.y = dist(rng) - 250;



            switch (c)
            {
            case 0:
                bodyList.push_back(std::make_shared<Minator::Circle>(RED, 50.0f, velo, 50.0f, center, 15.0f));
                break;

            case 1:
                bodyList.push_back(std::make_shared<Minator::Square>(GREEN, 50.0f, velo, 50.0f, center, 0.5f));
                break;

            case 2:
                bodyList.push_back(std::make_shared<Minator::Triangle>(GREEN, 50.0f, velo, 50.0f, center, 0.5f));
                break;

            case 3:
                bodyList.push_back(std::make_shared<Minator::Circle>(YELLOW, 50.0f, velo, 50.0f, center, 15.0f));
                break;

            default:
                break;
            }

            center.y += spaceQuantum;
            c++;
            c %= 4;
        }

        center.x += spaceQuantum;
        center.y = spaceQuantum;
    }
    
    newScene.bodyList = bodyList;
    
    //======================================================================//

    // Simulating Tunnelling
    /*
    Minator::Body b1(GREEN, (float)screenWidth * 0.25f, (float)screenHeight * 0.25f, 50.0f, 10.0f, screenWidth * 2, screenHeight * 2, 0.5f);

    newScene.addBody(std::make_shared<Minator::Body>(b1));
    */
    //=====================================================================//



    InitWindow(screenWidth, screenHeight, "Minator");

    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        newScene.updateScene(timeQuantum);
        
        BeginDrawing();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}

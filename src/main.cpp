#include "../includes/game.hpp"
#include "raylib.h"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Vamos los gallos");

    SetTargetFPS(60);
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Los gallos muy gallos", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();

    Game game;
    game.run();

    return 0;
}
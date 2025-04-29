#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Connect 4!");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Start Drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("hello world!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();


    return 0;
}

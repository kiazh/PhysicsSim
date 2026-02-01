#include <iostream>
#include <raylib.h>


int main ()
{
    int width =  900;
    int height = 900;
    Vector2 ballPos = {(float)450, (float)450};

    InitWindow (width, height, "burger");

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ballPos,50,RED);
        EndDrawing();
    }
    CloseWindow();
}
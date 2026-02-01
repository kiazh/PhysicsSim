#include <iostream>
#include <raylib.h>


int main ()
{
    int width =  900;
    int height = 900;

    InitWindow (width, height, "burger");

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
}
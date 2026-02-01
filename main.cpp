#include <iostream>
#include <raylib.h>
#include <cmath>
//For now we are going to
void balPosition (int mass1, int mass2, int distance)
{
    const int G =  6.6743 * pow(10, -11);
    int acl = (G* mass2)/pow(distance, 2);

}

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
        ClearBackground(BLACK);
        DrawCircleV(ballPos,50,RED);
        EndDrawing();
    }
    CloseWindow();
}
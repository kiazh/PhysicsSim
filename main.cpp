#include <iostream>
#include <raylib.h>
#include <cmath>
#include <vector>
const float G = 500;
const float dt = 0.1f;
const float soft = 1.0f;

struct Body {
    Vector2 pos;
    Vector2 vel;
    float mass;
    Color color;
    float radius;
};

float distance(const Vector2& p1, const Vector2& p2)
{
    float dx = abs(p1.x - p2.x);
    float dy = abs(p1.y - p2.y);
    return dx*dx + dy*dy;
}

void UpdateBodies(std::vector<Body>& bodies)
{

}



void balPosition (float mass1,float mass2, float distance)
{
    Vector2 ballPos = {(float)250, (float)450};
    double acl = (G* mass2)/pow(distance, 2);


return Vector2 ballPos;
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
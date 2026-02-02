#include <iostream>
#include <raylib.h>
#include <cmath>
#include <vector>

const float G = 500.0f;
const float dt = 0.1f;
const float soft = 1.0f;

struct Body {
    Vector2 pos;
    Vector2 vel;
    float mass;
    Color color;
    float radius;
};

float distanceSQ(const Vector2& p1, const Vector2& p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

Vector2 gravitationalAccel(const Body& b1, const Body& b2) {
    float dSq = distanceSQ(b1.pos, b2.pos);
    float dist = sqrtf(dSq);

    if (dist < soft) return {0.0f, 0.0f};

    float strength = (G * b2.mass) / (dSq * dist + soft);

    float dx = b2.pos.x - b1.pos.x;
    float dy = b2.pos.y - b1.pos.y;

    return {dx * strength / dist, dy * strength / dist};
}

// MISSING: Add this function!
void UpdateBodies(std::vector<Body>& bodies) {
    for (size_t i = 0; i < bodies.size(); ++i) {
        Vector2 accel = {0, 0};
        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i == j) continue;
            Vector2 a = gravitationalAccel(bodies[i], bodies[j]);
            accel.x += a.x;
            accel.y += a.y;
        }

        // Euler integration
        bodies[i].vel.x += accel.x * dt;
        bodies[i].vel.y += accel.y * dt;
        bodies[i].pos.x += bodies[i].vel.x * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt;
    }
}

int main() {
    InitWindow(900, 900, "Gravity Sim");
    SetTargetFPS(60);

    std::vector<Body> bodies = {
        {{400,450}, {0,5}, 15, YELLOW, 20},
        {{550,450}, {0,-3}, 1, BLUE, 10},
        {{350,500}, {4,0}, 2, GREEN, 12}
    };

    while (!WindowShouldClose()) {
        UpdateBodies(bodies);

        BeginDrawing();
        ClearBackground(BLACK);
        for (const auto& b : bodies) {
            DrawCircleV(b.pos, b.radius, b.color);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

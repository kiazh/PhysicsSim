#include <iostream>
#include <raylib.h>
#include <cmath>
#include <vector>

const float G = 5000.0f;
const float dt = 0.016f;
const float soft = 10.0f;

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
    float dx = b2.pos.x - b1.pos.x;
    float dy = b2.pos.y - b1.pos.y;
    float dSq = dx*dx + dy*dy;

    if (dSq < soft * soft) return {0.0f, 0.0f};

    float dist = sqrtf(dSq);
    float strength = (G * b2.mass) / dSq;

    return {dx * strength / dist, dy * strength / dist};
}

void UpdateBodies(std::vector<Body>& bodies) {
    for (size_t i = 0; i < bodies.size(); ++i) {
        Vector2 accel = {0, 0};
        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i == j) continue;
            Vector2 a = gravitationalAccel(bodies[i], bodies[j]);
            accel.x += a.x;
            accel.y += a.y;
        }

        bodies[i].vel.x += accel.x * dt;
        bodies[i].vel.y += accel.y * dt;
        bodies[i].pos.x += bodies[i].vel.x * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt;
    }
}

int main() {
    InitWindow(1920, 1080, "Gravity Sim");
    SetTargetFPS(60);

    float centerX = 960, centerY = 540;
    float M = 10000;

    float r1 = 200;
    float v1 = sqrtf(G * M / r1);

    float r2 = 300;
    float v2 = sqrtf(G * M / r2);

    std::vector<Body> bodies = {
        {{centerX, centerY}, {0, 0}, M, YELLOW, 30},
        {{centerX, centerY - r1}, {v1, 0}, 1, BLUE, 12},
        {{centerX + r2, centerY}, {0, v2}, 1, GREEN, 10},
        {{centerX, centerY + r1}, {-v1, 0}, 1, WHITE, 15}
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

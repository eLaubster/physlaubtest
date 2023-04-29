#include <iostream>
#include <typeinfo>
#include "physlaub.h"
#include "raylib.h"

using namespace std;

#define WIDTH 1280
#define HEIGHT 720

void DrawBody(Body *body, Color color);

int main() {

    InitWindow(WIDTH, HEIGHT, "PhysLaubTest");
    SetTargetFPS(60);

    World *world = new World();
    world->setGravity(0, 0);

    CircleShape *cs1 = new CircleShape(60);
    Fixture *f1 = new Fixture(cs1);
    f1->mass = 20;
    Body *body1 = new Body((float)WIDTH/8, HEIGHT/2, 0);
    body1->addFixture(f1);
    body1->setType(body1->KINEMATIC);
    world->addBody(body1);

    CircleShape *cs2 = new CircleShape(60);
    Fixture *f2 = new Fixture(cs2);
    f2->mass = 30;
    Body *body2 = new Body((WIDTH/8)*7, HEIGHT/2+1, 0);
    body2->addFixture(f2);
    body2->setType(body2->KINEMATIC);
    world->addBody(body2);

    body1->vel = Vec2d(100, 0);
    body2->vel = Vec2d(-100, 0);

    while(!WindowShouldClose()) {
        world->update(GetFrameTime());

        BeginDrawing();
        ClearBackground(GRAY);
        for(auto b : world->bodies) {
            DrawBody(b, RED);
        }

        DrawFPS(5,5);
        EndDrawing();
    }

    return 0;
}

void DrawBody(Body *body, Color color) {
    CircleShape* cs = dynamic_cast<CircleShape*>(body->fixture->shape);

    if(cs) {
        float x = body->pos.x;
        float y = body->pos.y;
        float r = cs->r;

        DrawCircle(x,y,r,color);
    }
}

#pragma once
#ifndef NDEBUG
#include <vld.h>
#endif

#include "raylib.h"
#include <box2d.h>

class physicsManager {
private:
    b2World* world;

    // variables para el step
    float timeStep;
    int velocityIterations;
    int positionIterations;

public:
    physicsManager(b2Vec2 gravity);
    ~physicsManager();

    // El motor que hace que todo se mueva
    void Update();

    // necesito esto para pasarle el mundo a las cajas y al suelo
    b2World* GetWorld();
};
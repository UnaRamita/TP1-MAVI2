#include "PhysicsManager.h"

physicsManager::physicsManager(b2Vec2 gravity) {
    //inicio de el mundo con la gravedad
    world = new b2World(gravity);

    // variables para la sim
    timeStep = 1.0f / 60.0f;
    velocityIterations = 8;
    positionIterations = 3;
}

void physicsManager::Update() {
    // Avanzamos la simulación física
    world->Step(timeStep, velocityIterations, positionIterations);
}

b2World* physicsManager::GetWorld() {
    return world;
}

physicsManager::~physicsManager() {
    delete world;
}
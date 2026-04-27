#pragma once
//despues chequear bien que uso de aca y que mando adentro de otras classes y no aca
#ifndef NDEBUG
#include <vld.h>
#endif

#include "raylib.h"
#include <box2d.h>

#include <vector>
//hasta aca
#include "Box.h"
#include "BoxPreview.h"
#include "PhysicsManager.h"
#include "StaticObjects.h"

class Game
{
public:					
	Game();
	~Game();	

	void inits();

	void run();

private:

	staticObjects* ground;
	staticObjects* wallLeft;
	staticObjects* wallRight;

	void load();

	void inputs();

	physicsManager* physics;
	boxPreview* preview;

	std::vector<box*> boxes;
	std::vector<staticObjects*> environment;//ambiente, suelo y paredes, dsp capaz le cambio el nombre de esto
};


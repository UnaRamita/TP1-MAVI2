#pragma once
#ifndef NDEBUG
#include <vld.h>
#endif

#include "raylib.h"
#include <box2d.h>

class box
{
public:
	box(b2World* wrld, Vector2 pos, Vector2 siz, float ang);

	void init();
	void draw();

	~box();

private:
	b2World* world;

	b2Body* body;

	Vector2 size;
	Vector2 position;

	Color color;

	float angle;
};

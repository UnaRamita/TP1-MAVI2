#pragma once
#include "raylib.h"

class boxPreview
{
public:
	boxPreview(Vector2 pos, Vector2 siz);

	void Rotate(float amount);
	void Draw();

	float GetAngle() const;

	Vector2 getPosition();
	Vector2 getSize();

	~boxPreview();

private:
	float angle;

	Vector2 position;
	Vector2 size;
};

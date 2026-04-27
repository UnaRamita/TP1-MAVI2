#include "BoxPreview.h"


boxPreview::boxPreview(Vector2 pos, Vector2 siz )
{
	position = pos;
	size = siz;
	angle = 0.0f;
}

void boxPreview::Rotate(float amount)
{
	angle += amount;
}

void boxPreview::Draw()
{
	DrawRectanglePro({ position.x, position.y, size.x, size.y }, { size.x / 2.0f, size.y / 2.0f }, angle, Fade(BLUE,0.5f));
}

Vector2 boxPreview::getPosition()
{
	return position;
}

Vector2 boxPreview::getSize()
{
	return size;
}

float boxPreview::GetAngle() const
{
	return angle;
}


boxPreview::~boxPreview()
{
}
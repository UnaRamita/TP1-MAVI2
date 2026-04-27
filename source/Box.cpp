#include "Box.h"

box::box(b2World* wrld, Vector2 pos, Vector2 siz, float ang)
{
	position = pos;
	size = siz;
	angle = ang;

	color = BLUE;

	body = nullptr;

	world = wrld;
}
void box::init() {
	//definicion del cuerpo (dinamico en este caso)
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(position.x, position.y);
	bodyDef.angle = angle;
	//forma y propiedades 
	//forma
	b2PolygonShape boxShape;
	boxShape.SetAsBox(size.x / 2.0f, size.y / 2.0f);
	//propiedades
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.0f;     // algo de masa
	fixtureDef.friction = 0.3f;     // algo de friccion
	fixtureDef.restitution = 0.2f;  // rebote
	//aplicamos todo
	body = world->CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);
}
void box::draw() {
	//obtenemos la posicion y el angulo del cuerpo
	b2Vec2 pos = body->GetPosition();
	float angle = body->GetAngle() * RAD2DEG;
	//dibujamos el rectangulo con la posicion y el angulo del cuerpo
	DrawRectanglePro({ pos.x, pos.y, size.x, size.y }, { size.x / 2.0f, size.y / 2.0f }, angle, color);
}

box::~box()
{
}
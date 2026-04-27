#include "Game.h"
Game::Game() : physics(nullptr), preview(nullptr)
{

	ground = nullptr;
	wallLeft = nullptr;
	wallRight = nullptr;


}

void Game::inits() {
    //iniciamos pantalla
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "MAVI II - Tp");
    SetTargetFPS(60);

	//iniciamos el mundo fisico
	physics = new physicsManager({ 0.0f, 100.0f });

	preview = new boxPreview({ 400.0f, 100.0f }, { 50.0f, 40.0f });

	//iniciamos los objetos estaticos
	ground = new staticObjects(physics->GetWorld(), { 400, 580 }, { 800, 40 });
	ground->init();

	// Pared Izquierda
	wallLeft = new staticObjects(physics->GetWorld(), { 10, 300 }, { 20, 600 });
	wallLeft->init();

	// Pared Derecha
	wallRight = new staticObjects(physics->GetWorld(), { 790, 300 }, { 20, 600 });
	wallRight->init();

	//los pongo en la lista para dibujarlos dsp
	environment.push_back(ground);
	environment.push_back(wallLeft);
	environment.push_back(wallRight);
}

void Game::inputs() {
	// Rotacion de la preview
	if (IsKeyDown(KEY_LEFT)) {
		preview->Rotate(-3.0f);
	}
	if (IsKeyDown(KEY_RIGHT)) { 
		preview->Rotate(3.0f);
	}
	// Creacion de la caja
	if (IsKeyPressed(KEY_SPACE)) {
		// Paso el angulo de la preview
		float angleInRad = preview->GetAngle() * DEG2RAD;
		// "Materializamos" la caja física con los datos de la preview
		box* newBox = new box(physics->GetWorld(), preview->getPosition(), preview->getSize(), angleInRad);
		newBox->init();
		boxes.push_back(newBox);
	}
}

void Game::load() {
	//actualizamos la fisica
	physics->Update();
	//draws
	DrawText("Use LEFT and RIGHT arrows to rotate the box preview, SPACE to create a new box", 20, 10, 18, BLUE);
	//statics
	for (auto obj : environment) obj->draw();
	//dinamics
	for (auto b : boxes) b->draw();
	//preview
	preview->Draw();
}

void Game::run() {
	inputs();
	load();
}
Game::~Game()
{}
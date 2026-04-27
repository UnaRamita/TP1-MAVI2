#include "Game.h"
#include "raylib.h"


int main() {
    Game game;

    game.inits();


    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(YELLOW);

        game.run();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
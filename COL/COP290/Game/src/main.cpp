#include "../include/game.hpp"

// Game Attributes
const int WIDHT = 1920;
const int HEIGHT = 1080;
const int FPS = 60;
const char *TITLE = "the_game";


int main(int argc, const char *argv[])
{
    Game game;

    SetTraceLogLevel(LOG_ERROR);

    game.init(WIDHT, HEIGHT, TITLE);
    game.startscreen(TITLE);

    SetTargetFPS(FPS);
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        game.render();
        game.update(dt);
        game.endDraw();
    }
    game.close();

    return 0;
}
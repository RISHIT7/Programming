#include "Game.hpp"

Game *game = nullptr;

int main(int argc, const char* argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("Birch Engine", 800, 600, false);

    while(game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}
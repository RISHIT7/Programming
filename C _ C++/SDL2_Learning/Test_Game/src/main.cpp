#include "Game.hpp"

Game *game = nullptr;

int main(int argc, const char *argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    uint32_t frameStart;
    int frameTime;

    game = new Game();
    game->init("Birch Engine", 1400, 1000, false);

    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}
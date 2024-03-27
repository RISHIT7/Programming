#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject* player;

Game::Game()
{
}
Game::~Game()
{
}

void Game::init(const char *title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystem Initialised!..." << endl;

        // creating a window
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if (window)
        {
            cout << "Window Created!" << endl;
        }

        // creating a renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created!" << endl;
        }

        player = new GameObject("../assets/Images/Character.bmp", renderer);

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_SPACE:
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
}

void Game::update()
{
    player->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    player->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Closed" << endl;
}

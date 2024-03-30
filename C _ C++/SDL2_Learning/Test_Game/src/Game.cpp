#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"

Map *map;
Manager manager;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());

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

        map = new Map();

        player.addComponent<TransformComponent>();
        player.addComponent<SpriteComponent>("../assets/Character/player.bmp");
        player.addComponent<KeyboardController>();
        player.addComponent<ColliderComponent>("player");

        wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
        wall.addComponent<SpriteComponent>("../assets/Texture/dirt.bmp");
        wall.addComponent<ColliderComponent>("wall");

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
}

void Game::handleEvents()
{
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
    manager.refresh();
    manager.update();

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,
                        wall.getComponent<ColliderComponent>().collider))
    {
        std::cout << "Wall Hit!" << std::endl;
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Closed" << endl;
}

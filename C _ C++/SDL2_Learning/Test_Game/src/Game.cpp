#include "Game.hpp"

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

        bitmapSurf = SDL_LoadBMP("../assets/Images/Character.bmp");
        bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurf);
        SDL_FreeSurface(bitmapSurf);
        if (bitmapTex) {
            cout << "Texture loaded!" <<endl;
        }

        // Create rectangle
        rectangle.x = 50;
        rectangle.y = 100;
        rectangle.w = 200; 
        rectangle.h = 200;

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
                    rectangle.x += 1;
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
    // cnt++;
    // cout << cnt << endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bitmapTex, NULL, &rectangle);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Closed" << endl;
}

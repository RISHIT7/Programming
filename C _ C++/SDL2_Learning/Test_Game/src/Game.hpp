#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include <iostream>
#include <vector>
using namespace std;

class ColliderComponent;

class Game
{
public:
    Game();
    ~Game();

    void init(const char *title, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();


    static void AddTile(int id, int x, int y);
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;

    bool running()
    {
        return isRunning;
    }


private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
};

#endif /* Game_hpp */
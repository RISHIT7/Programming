#pragma once
#include "Game.hpp"

class Map
{
public:

    Map();
    ~Map();

    void LoadMap(int arr[32][44]);
    void DrawMap();

private:

    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[32][44];

};
#pragma once
#include "Game.hpp"

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *filename, SDL_Renderer *ren);
};
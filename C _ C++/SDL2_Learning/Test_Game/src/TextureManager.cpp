#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* ren)
{
    SDL_Surface* bitmapSurf = SDL_LoadBMP(filename);
    SDL_Texture* bitmapTex = SDL_CreateTextureFromSurface(ren, bitmapSurf);
    SDL_FreeSurface(bitmapSurf);

    return bitmapTex;
}
#include "TextureManager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *filename)
{
    SDL_Surface *bitmapSurf = SDL_LoadBMP(filename);
    SDL_Texture *bitmapTex = SDL_CreateTextureFromSurface(Game::renderer, bitmapSurf);
    SDL_FreeSurface(bitmapSurf);

    return bitmapTex;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

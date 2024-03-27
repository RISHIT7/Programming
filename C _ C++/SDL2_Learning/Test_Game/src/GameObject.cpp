#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren, int x , int y)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);
    xpos = x;
    ypos = y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
    xpos++;

    srcRect.h = 128;
    srcRect.w = 128;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
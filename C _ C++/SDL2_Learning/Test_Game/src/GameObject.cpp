#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
    xpos = 0;
    ypos = 0;

    srcRect.h = 32;
    srcRect.w = 32;
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
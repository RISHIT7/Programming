#pragma once

#include "Components.hpp"
// #include "TextureManager.hpp"
#include "SDL.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    SpriteComponent(const char *path)
    {
        set_tex(path);
    }

    void set_tex(const char* path)
    {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override
    {
        position = &entity->getComponent<PositionComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 128;
        destRect.w = destRect.h = 128;
    }

    void update() override
    {
        destRect.x = position->x();
        destRect.y = position->y();
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }

private:
    PositionComponent *position;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
};
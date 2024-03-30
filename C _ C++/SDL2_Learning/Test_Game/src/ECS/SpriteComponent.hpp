#pragma once

#include "Components.hpp"
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
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 128;
        destRect.w = destRect.h = 128;
    }

    void update() override
    {
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }

private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
};
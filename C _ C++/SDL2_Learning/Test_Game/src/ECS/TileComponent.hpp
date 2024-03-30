#pragma once

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "SDL.h"

class TileComponent : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    char* path;

    SDL_Rect tileRect;
    int tile_id;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id)
    {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tile_id = id;

        switch (tile_id)
        {
        case 0:
            path = "../assets/Texture/water.bmp";
            break;
        case 1:
            path = "../assets/Texture/dirt.bmp";
            break;
        case 2:
            path = "../assets/Texture/grass.bmp";
            break;
        
        default:
            break;
        }
    }

    void init() override
    {
        entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};
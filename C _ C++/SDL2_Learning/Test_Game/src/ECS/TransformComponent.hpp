#pragma once
#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component
{
public:
    Vector2D position;
    Vector2D velocity;

    int height = 128;
    int width = 128;
    int scale = 1;

    int speed = 3;

    TransformComponent()
    {
        position.x = 0;
        position.y = 0;
    }

    TransformComponent(int sc)
    {
        position.x = 0;
        position.y = 0;
        scale = sc;
    }
    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    TransformComponent(float x, float y, int h, int w, int sc)
    {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    void init() override
    {
        velocity.x = 0;
        velocity.y = 0;
    }

    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};
#pragma once
#include "Components.hpp"

class PositionComponent : public Component
{
public:
    int x() { return xpos; }
    int y() { return ypos; }

    PositionComponent()
    {
        xpos = 0;
        ypos = 0;
    }

    PositionComponent(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    void update() override
    {
        xpos++;
        ypos++;
    }

    void set_pos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

private:
    int xpos;
    int ypos;
};
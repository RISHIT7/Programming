#pragma once
#include "ECS.hpp"

class PositionComponent : public Component
{
public:
    int x() { return xpos; }
    int y() { return ypos; }

    void init() override
    {
        xpos = 0;
        ypos = 0;
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
#pragma once

#include <raylib.h>
#include <raymath.h>
#include <rlPhysics.h>
#include "texture.hpp"
#define MAX_COLLECTIBLES 10

class Collectible
{
    Vector2 position;
    float radius;
    bool active;
    PhysicsBody body;
    int numCollectibles = 0;

public:
    void InitCollectible();
    void SpawnCollectible();
    void UpdateCollectible();
    void DrawCollectible();
};
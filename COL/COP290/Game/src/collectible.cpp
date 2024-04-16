#include "../include/collectible.hpp"

Collectible collectibles[MAX_COLLECTIBLES];
PhysicsBody floorBody;

void Collectible::InitCollectible()
{
    for (int i = 0; i < MAX_COLLECTIBLES; i++)
    {
        collectibles[i].active = false;
    }
}

void Collectible::SpawnCollectible()
{
    if (numCollectibles >= MAX_COLLECTIBLES)
        return;

    Collectible *c = &collectibles[numCollectibles];
    c->position = (Vector2){GetRandomValue(50, GetScreenWidth() - 50), -50};
    c->radius = 10;
    c->active = true;

    PhysicsBodyData data = InitPhysicsBodyData();
    data.shape = PHYSICS_CIRCLE;
    data.radius = c->radius;
    c->body = InitPhysicsBody(data, c->position);

    numCollectibles++;
}

void Collectible::UpdateCollectible()
{
    for (int i = 0; i < numCollectibles; i++)
    {
        Collectible *c = &collectibles[i];
        if (!c->active)
        {
            for (int j = i; j < numCollectibles - 1; j++)
            {
                collectibles[j] = collectibles[j + 1];
            }
            numCollectibles--;
            DestroyPhysicsBody(c->body);
            continue;
        }

        UpdatePhysics();

        PhysicsBodyCollision collision = GetPhsyicsBodyCollision(c->body, floorBody);
        if (collision.collided)
        {
            DestroyPhsycisBody(floorBody);
            floorBody = NULL;
            c->active = false;
        }

        if (c->position.y > GetScreenHeight() + c->radius)
        {
            c->active = false;
        }
    }
}

void Collectible::DrawCollectible()
{
    for (int i = 0; i < numCollectibles; i++)
    {
        Collectible *c = &collectibles[i];
        if (!c->active)
            continue;

        DrawPhysicsBody(c->body, RED);
    }
}

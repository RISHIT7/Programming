#include "../include/character.hpp"

Character::Character()
{
    texture = idle;
}

Character::Character(const char *path1, const char *path2)
{
    idle.load(path1);
    run.load(path2);
    texture = idle;

    width = static_cast<float>(texture.getTexture().width / 11.f);
    height = static_cast<float>(texture.getTexture().height);
}

Character::~Character()
{
    idle.unload();
    run.unload();
}

void Character::initchar(Vector2 pos, int frame, float updateTime, float runningTime)
{
    this->pos = pos;
    this->frame = frame;
    this->updateTime = updateTime;
    this->runningTime = runningTime;
}

void Character::updatechar(float dt, int level)
{
    lastframe = pos;
    if (IsKeyDown(KEY_A) and (level == 1 || level == 2))
    {
        vel.x = -1.0;
    }
    if (IsKeyDown(KEY_S) and (level == 1))
    {
        vel.y = 1.0;
    }
    if (IsKeyDown(KEY_D) and (level == 1 || level == 2))
    {
        vel.x = 1.0;
    }
    if (IsKeyDown(KEY_W) and (level == 1))
    {
        vel.y = -1.0;
    }
    if (IsKeyPressed(KEY_SPACE) and (level == 2))
    {
        vel.x = 0.707;
        vel.y = -0.707;
    }
    if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_S) || IsKeyReleased(KEY_D) || IsKeyReleased(KEY_W))
        vel = {};
    if (level == 2)
        vel.y += .05;

    if (Vector2Length(vel) != 0.0)
    {
        pos = Vector2Add(pos, Vector2Scale(Vector2Normalize(vel), speed));

        if (vel.x < 0.f) { right_left = -1.f; }
        else if (vel.x > 0.f) { right_left = 1.f; }

        texture = run;
        maxframes = 12;
    }
    else
    {
        texture = idle;
        maxframes = 11;
    }
    // vel = {};

    runningTime += dt;
    if (runningTime >= updateTime)
    {
        runningTime = 0.f;
        frame++;
        frame = frame % maxframes;
    }

    (pos.x >= 896.f and pos.x <= 2816.f) ? shouldstay.first = true : shouldstay.first = false;
    (pos.y >= 476.f and pos.y <= 3236.f) ? shouldstay.second = true : shouldstay.second = false;

    shouldstay.first ? xpos = 896.f : xpos = pos.x;
    shouldstay.second ? ypos = 476.f : ypos = pos.y;

    if (pos.x > 2816.f)
        xpos = pos.x - 1920;

    if (pos.y > 3236.f)
        ypos = pos.y - 2760;

    Rectangle source{frame * width, 0.f, right_left * width, height};
    Rectangle dest{xpos, ypos, scale * width, scale * height};
    DrawTexturePro(texture.getTexture(), source, dest, Vector2{}, 0.0, WHITE);
}

void Character::undomove()
{
    pos = lastframe;
}

Rectangle Character::getrec()
{
    return Rectangle{pos.x + 25.f, pos.y + 50.f, 78.f, 75.f};
}

Vector2 Character::getpos()
{
    return pos;
}

std::pair<bool, bool> Character::movecamera()
{
    return shouldstay;
}

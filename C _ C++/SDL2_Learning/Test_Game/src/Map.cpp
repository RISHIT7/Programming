#include "Map.hpp"
#include "TextureManager.hpp"

int lvl1[32][44] = {0};

Map::Map()
{
    dirt = TextureManager::LoadTexture("../assets/Texture/dirt.bmp"); // type 2
    grass = TextureManager::LoadTexture("../assets/Texture/grass.bmp"); // type 1
    water = TextureManager::LoadTexture("../assets/Texture/water.bmp"); // type 0

    LoadMap(lvl1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

Map::~Map()
{
}

void Map::LoadMap(int arr[32][44])
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 44; j++)
        {
            lvl1[i][j] = arr[i][j];
        }
    }
}

void Map::DrawMap()
{
    int type = 0;

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 44; j++)
        {
            type = map[i][j];

            dest.x = j * 32;
            dest.y = i * 32;

            switch (type)
            {
                case 0: // Water
                    TextureManager::Draw(water, src, dest);
                    break;
                case 1: // Grass
                    TextureManager::Draw(grass, src, dest);
                    break;
                case 2: // Dirt
                    TextureManager::Draw(dirt, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}
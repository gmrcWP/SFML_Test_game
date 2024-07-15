#include "Map.h"
#include <iostream>

Map::Map() : tileWidth(10), tileHeight(16), totalTilesX(0), totalTilesY(0), totalTiles(0), mapWidth(3), mapHeight(2), tiles(nullptr) {

}
Map::~Map()
{
    delete[] tiles;
    delete[] mapSprites;
}
void Map::Initialize()
{
}

void Map::Load()
{
    if (tileSheetTexture.loadFromFile("Assets/World/Prison/tilesheet.png")) {
        std::cout << "Map texture loaded" << std::endl;

        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        totalTiles = totalTilesX * totalTilesY;
        tiles = new Tile[totalTiles];

        for (size_t y = 0; y < totalTilesY; y++)
        {
            for (size_t x = 0; x < totalTilesX; x++)
            {
                int i = x + y * totalTilesX;
                tiles[i].id = i;
                tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
            }
        }     
    }
    else {
        std::cout << "Map texture failed to load" << std::endl;
    }

    for (size_t y = 0; y < mapHeight; y++)
    {
        for (size_t x = 0; x < mapWidth; x++)
        {
            int i = x + y * mapWidth;
            int index = mapNumbers[i];

            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(tiles[index].position.x, tiles[index].position.y, tileWidth, tileHeight));
            mapSprites[i].setScale(sf::Vector2f(4, 4));
            mapSprites[i].setPosition(sf::Vector2f(x * tileWidth * mapSprites[i].getScale().x, 100 + y * tileHeight * mapSprites[i].getScale().y));
        }
    }

    delete tiles;
}

void Map::Update(double deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < mapSize; i++) {
        window.draw(mapSprites[i]);
    }
}

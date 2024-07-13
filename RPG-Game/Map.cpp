#include "Map.h"
#include <iostream>

Map::Map() : tileWidth(10), tileHeight(16), totalTilesX(0), totalTilesY(0) {

}
void Map::Initialize()
{
}

void Map::Load()
{
    if (tileSheetTexture.loadFromFile("Assets/World/Prison/tilesheet.png")) {
        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        std::cout << "Map texture loaded" << std::endl;

        for (size_t i = 0; i < 10; i++) {
            sprite[i].setTexture(tileSheetTexture);
            sprite[i].setTextureRect(sf::IntRect(i * tileWidth, 0 * tileHeight, tileWidth, tileHeight));
            sprite[i].setScale(sf::Vector2f(4, 4));     
            sprite[i].setPosition(sf::Vector2f(100 + i * tileWidth * 4, 100));
        }
       
    }
    else {
        std::cout << "Map texture failed to load" << std::endl;
    }
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < 10; i++) {
        window.draw(sprite[i]);
    }
}

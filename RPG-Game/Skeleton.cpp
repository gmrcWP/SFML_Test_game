#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize() {
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Skeleton::Load() {
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        std::cout << "Skeleton texture loaded";
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1200, 600));

        int XIndex = 0;
        int YIndex = 2;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, size.x, size.y));

        boundingRectangle.setSize(sf::Vector2f(size.x, size.y));
    }
    else {
        std::cout << "Skeleton texture failed to load";
    }
}

void Skeleton::Update() {
    boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);
}

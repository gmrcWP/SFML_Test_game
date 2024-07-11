#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize() {

}

void Skeleton::Load() {
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        std::cout << "Skeleton texture loaded";
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1200, 600));

        int XIndex = 0;
        int YIndex = 2;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
    }
    else {
        std::cout << "Skeleton texture failed to load";
    }
}

void Skeleton::Update() {

}

void Skeleton::Draw(sf::RenderWindow& window) {

    window.draw(sprite);
}

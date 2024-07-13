#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : health(100) {

}

void Skeleton::ChangeHealth(int hp) {
    health += hp;
    healthText.setString(std::to_string(health));
}

void Skeleton::Initialize() {
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Skeleton::Load() {
    if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
        std::cout << "Font Loaded" << std::endl;
        healthText.setFont(font);
        healthText.setCharacterSize(15);
        healthText.setString(std::to_string(health));
    }
    else {
        std::cout << "Failed to load font" << std::endl;
    }

    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        std::cout << "Skeleton texture loaded" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1600, 700));

        int XIndex = 0;
        int YIndex = 2;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, size.x, size.y));

        boundingRectangle.setSize(sf::Vector2f(size.x, size.y));
    }
    else {
        std::cout << "Skeleton texture failed to load" << std::endl;
    }
}

void Skeleton::Update(float deltaTime) {
    if (health > 0) {
        boundingRectangle.setPosition(sprite.getPosition());
        healthText.setPosition(sprite.getPosition());
    }
}

void Skeleton::Draw(sf::RenderWindow& window) {
    if (health > 0) {
        window.draw(sprite);
        window.draw(boundingRectangle);
        window.draw(healthText);
    }
}

#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize() {

}

void Player::Load() {
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        std::cout << "Player texture loaded";
        sprite.setTexture(texture);

        int XIndex = 0;
        int YIndex = 0;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
    }
    else {
        std::cout << "Player texture failed to load";
    }
}

void Player::Update(Skeleton& skeleton) {
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.move(sf::Vector2f(1, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.move(sf::Vector2f(-1, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.move(sf::Vector2f(0, 1));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.move(sf::Vector2f(0, -1));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
        bullets[bullets.size() - 1].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}
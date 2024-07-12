#include "Player.h"
#include <iostream>
#include "Math.h"

Player::Player() : bulletSpeed(0.5f), playerSpeed(6.0f) {

}

void Player::Initialize() {
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Player::Load() {
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        std::cout << "Player texture loaded" << std::endl;
        sprite.setTexture(texture);

        int XIndex = 0;
        int YIndex = 0;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, size.x, size.y));

        boundingRectangle.setSize(sf::Vector2f(size.x, size.y));
    }
    else {
        std::cout << "Player texture failed to load" << std::endl;
    }
}

void Player::Update(float deltaTime,Skeleton& skeleton) {
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.move(sf::Vector2f(0.1, 0) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.move(sf::Vector2f(-0.1, 0) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.move(sf::Vector2f(0, 0.1) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.move(sf::Vector2f(0, -0.1) * playerSpeed * deltaTime);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
        bullets[bullets.size() - 1].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
    }

    boundingRectangle.setPosition(sprite.getPosition());

    if (Math::CheckRectCollision(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
        std::cout << "Collision \n";
    }
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);

    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}
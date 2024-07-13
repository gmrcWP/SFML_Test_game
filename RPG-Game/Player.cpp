#include "Player.h"
#include <iostream>
#include "Math.h"

Player::Player() : playerSpeed(6.0f), maxFireRate(150), fireRateTimer(0){

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

void Player::Update(float deltaTime,Skeleton& skeleton, sf::Vector2f& mousePosition) {
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.move(sf::Vector2f(0.1, 0) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.move(sf::Vector2f(-0.1, 0) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.move(sf::Vector2f(0, 0.1) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.move(sf::Vector2f(0, -0.1) * playerSpeed * deltaTime);

    fireRateTimer += deltaTime;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) {
        bullets.push_back(Bullet());
        int i = bullets.size() - 1;
        bullets[i].Initialize(sprite.getPosition(), mousePosition, 0.5f);

        fireRateTimer = 0;
    }

    
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].Update(deltaTime);

        if (skeleton.health > 0) {
            if (Math::CheckRectCollision(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
                skeleton.ChangeHealth(-10);
                bullets.erase(bullets.begin() + i);
                std::cout << "Skeleton Health: " << skeleton.health << std::endl;
            }
        }        
    }

    boundingRectangle.setPosition(sprite.getPosition());

    
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);

    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].Draw(window);
    }
}
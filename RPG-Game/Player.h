#pragma once
#include "Skeleton.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player
{
private:
	sf::Texture texture;

	std::vector<Bullet> bullets;
	
	float maxFireRate;
	float fireRateTimer;
	float playerSpeed;

	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;	
			   
public:
	sf::Sprite sprite;
public:
	Player();

	void Initialize();
	void Load();
	void Update(double deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
};


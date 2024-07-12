#pragma once
#include "Skeleton.h"
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;

	sf::RectangleShape boundingRectangle;

	sf::Vector2i size;
			   
public:
	sf::Sprite sprite;
public:
	void Initialize();
	void Load();
	void Update(Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};


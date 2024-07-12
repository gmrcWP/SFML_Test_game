#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
	sf::Text frameRateText;
	sf::Font font;

	float timer;
public:
	FrameRate();
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};


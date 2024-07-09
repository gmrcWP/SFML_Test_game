#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //---------------------------------------------INITIALIZE----------------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);
    
    //---------------------------------------------INITIALIZE----------------------------------------------------

    //---------------------------------------------LOAD----------------------------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        std::cout << "Player image loaded";

        int XIndex = 0;
        int YIndex = 0;
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
    }
    //---------------------------------------------LOAD----------------------------------------------------
    //main game loop
    while (window.isOpen())
    {
        //---------------------------------------------UPDATE----------------------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.move(sf::Vector2f(0.1, 0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.move(sf::Vector2f(-0.1, 0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.move(sf::Vector2f(0, 0.1));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.move(sf::Vector2f(0, -0.1));
        //---------------------------------------------UPDATE----------------------------------------------------


        //---------------------------------------------DRAW----------------------------------------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
        //---------------------------------------------DRAW----------------------------------------------------
    }

    return 0;
}
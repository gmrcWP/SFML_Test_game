#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Map.h"
#include "Skeleton.h"
#include "FrameRate.h"

int main()
{
    //---------------------------------------------INITIALIZE----------------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Default, settings);
    window.setFramerateLimit(360);
    
    //---------------------------------------------INITIALIZE---------------------------------------------------
    FrameRate frameRate;
    Map map;
    Player player;
    Skeleton skeleton;
    //---------------------------------------------INITIALIZE----------------------------------------------------
    map.Initialize();
    frameRate.Initialize();
    player.Initialize();
    skeleton.Initialize();
    //---------------------------------------------INITIALIZE----------------------------------------------------

     //---------------------------------------------LOAD----------------------------------------------------
    map.Load();
    frameRate.Load();
    player.Load();    
    skeleton.Load(); 
    //---------------------------------------------LOAD----------------------------------------------------
    
    sf::Clock clock;

    //main game loop
    while (window.isOpen())
    {
        sf::Time deltatimeTimer = clock.restart();
        float deltaTime = deltatimeTimer.asMicroseconds() / 1000.0;
        frameRate.Update(deltaTime);
        //---------------------------------------------UPDATE----------------------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        map.Update(deltaTime);
        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton, mousePosition);
        //---------------------------------------------DRAW----------------------------------------------------
        window.clear(sf::Color::Black);
        map.Draw(window);
        skeleton.Draw(window);
        player.Draw(window);
        frameRate.Draw(window);
        window.display();
        //---------------------------------------------DRAW----------------------------------------------------
    }

    return 0;
}
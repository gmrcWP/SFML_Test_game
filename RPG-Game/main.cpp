#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"

int main()
{
    //---------------------------------------------INITIALIZE----------------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Default, settings);
    
    //---------------------------------------------INITIALIZE---------------------------------------------------   
    Player player;
    Skeleton skeleton;
    //---------------------------------------------INITIALIZE----------------------------------------------------
    player.Initialize();
    skeleton.Initialize();
    //---------------------------------------------INITIALIZE----------------------------------------------------

     //---------------------------------------------LOAD----------------------------------------------------
    player.Load();    
    skeleton.Load(); 
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

        skeleton.Update();
        player.Update(skeleton);
        //---------------------------------------------DRAW----------------------------------------------------
        window.clear(sf::Color::Black);

        skeleton.Draw(window);
        player.Draw(window);

        window.display();
        //---------------------------------------------DRAW----------------------------------------------------
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"

int main()
{
    sf::RenderWindow mWindow(sf::VideoMode(640, 480), "Rock Scissor Paper");
    sf::Time timePerFrame = sf::seconds(1.f/60.f);
    sf::Time timeSinceLastFrame;
    
    sf::Clock frameClock;
    sf::Clock timerClock;
    
    Game game(mWindow);
    
    while (mWindow.isOpen())
    {
        sf::Event event;
        
        while (mWindow.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    mWindow.close();
                    break;
            }
        }
        
        timeSinceLastFrame += frameClock.restart();
        while (timeSinceLastFrame >= timePerFrame)
        {
            game.update(timePerFrame);
            timeSinceLastFrame -= timePerFrame;
        }
        
        game.processInput();
        
        mWindow.clear();
        game.render();
        mWindow.display();
    }
    
    return 0;
}
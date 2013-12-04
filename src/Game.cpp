#include "Game.h"

Game::Game(sf::RenderTarget& target)
: renderer(player1, player2, countdownTimer, target)
, target(target)
, countdownTimer(sf::seconds(10))
, winnerTimer(sf::seconds(0))
{
    player1.setWeapon("Rock");
    player2.setWeapon("Rock");
    
    player1.getSprite()->setPosition(45, 255);
    player2.getSprite()->setPosition(415, 255);
}

void Game::processInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
    {
        countdownTimer = sf::seconds(10.f);
        player1.setScore(0);
        player2.setScore(0);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
    {
        player1.setWeapon("Rock");
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
    {
        player1.setWeapon("Scissors");
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
    {
        player1.setWeapon("Paper");
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8))
    {
        player2.setWeapon("Rock");
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num9))
    {
        player2.setWeapon("Scissors");
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num0))
    {
        player2.setWeapon("Paper");
    }
}

void Game::update(sf::Time timePerFrame)
{
    swapModelTimer += timePerFrame;
    
    if (winnerTimer.asSeconds() <= 0)
    {
        if (countdownTimer.asSeconds() > 2.f && countdownTimer.asSeconds() <= 10 && swapModelTimer.asSeconds() >= 1.f)
        {
            player1.update(false, true);
            player2.update(false, true);
            
            swapModelTimer = sf::Time::Zero;
        }
        if (countdownTimer.asSeconds() > 0)
        {
            countdownTimer -= timePerFrame;
            player1.update(false);
            player2.update(false);
        }
        else
        {
            player1.update(true);
            player2.update(true);
            
            Duel duel(player1, player2);
            int winner = duel.winner();
            
            switch (winner)
            {
                case 1:
                    countdownTimer = sf::seconds(10.f);
                    player1.setScore(player1.getScore() + 1);
                    winnerTimer = sf::seconds(5.f);
                    break;
                case 2:
                    countdownTimer = sf::seconds(10.f);
                    player2.setScore(player2.getScore() + 1);
                    winnerTimer = sf::seconds(5.f);
                    break;
                case 3:
                    countdownTimer = sf::seconds(10.f);
                    break;
            }
        }
    }
    else
    {
       winnerTimer -= timePerFrame;
    }
}

void Game::render()
{
    GameRenderer renderer(player1, player2, countdownTimer, target);
    renderer.render();
}
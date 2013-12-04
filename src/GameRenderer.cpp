#include "GameRenderer.h"
#include <SFML/Graphics.hpp>

GameRenderer::GameRenderer(Player &n_player1, Player &n_player2, sf::Time &countdownTimer, sf::RenderTarget& target)
: target(target)
, player1(n_player1)
, player2(n_player2)
{
    player1 = n_player1;
    player2 = n_player2;
    
    if(!font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        std::cout << "Could not load Sansation.ttf" << std::endl;
    }
    
    countdownTime = countdownTimer;
    
    score.setFont(font);
    score.setCharacterSize(30);
    score.setColor(sf::Color::White);
    score.setPosition(285.f, 100.f);
    
    timer.setFont(font);
    timer.setCharacterSize(60);
    timer.setColor(sf::Color::White);
    timer.setPosition(305.f, 35.f);
    
    background.setSize(sf::Vector2f(640.f, 480.f));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color::Black);
}

void GameRenderer::update()
{
    timer.setString(convertInt(countdownTime.asSeconds()));
    score.setString(convertInt(player1.getScore()) + " - " +  convertInt(player2.getScore()));
    
    timer.setPosition(640/2-timer.getLocalBounds().width/2, 35.f);
    score.setPosition(640/2-score.getLocalBounds().width/2, 100.f);
}

void GameRenderer::render()
{
    update();
    
    draw(background);
    
    draw(*player1.getSprite());
    draw(*player2.getSprite());
    
    draw(timer);
    draw(score);
}

void GameRenderer::draw(const sf::Drawable& shape)
{
    target.draw(shape);
}

std::string GameRenderer::convertInt(int number)
{
    std::stringstream stringstr;
    stringstr << number;
    
    return stringstr.str();
}
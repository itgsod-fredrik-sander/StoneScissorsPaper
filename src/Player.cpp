#include "Player.h"

Player::Player()
: score(0)
, counter(1)
{
    if(!texture.loadFromFile(resourcePath() + "hand.png"))
    {
        std::cout << "Could not load texture: Hand.png" << std::endl;
    }
    
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 200, 225));
}

void Player::update(bool changeTexture, bool updateTexture)
{
    if (changeTexture == false && updateTexture == true)
    {
        switch (counter)
        {
            case 1:
                sprite.setTextureRect(sf::IntRect(0, 0, 200, 225));
                break;
            case 2:
                sprite.setTextureRect(sf::IntRect(200, 0, 180, 225));
                break;
            case 3:
                sprite.setTextureRect(sf::IntRect(380, 0, 360, 225));
                break;
        }
        
        if (counter > 2)
        {
            counter = 0;
        }
        
        counter++;
}
    
    if (changeTexture == true)
    {
        if (weapon == "Rock")
        {
            sprite.setTextureRect(sf::IntRect(0, 0, 200, 225));
        }
        else if (weapon == "Scissors")
        {
            sprite.setTextureRect(sf::IntRect(200, 0, 180, 225));
        }
        else if (weapon == "Paper")
        {
            sprite.setTextureRect(sf::IntRect(380, 0, 360, 225));
        }
    }
}

void Player::setScore(int new_score)
{
    score = new_score;
}

void Player::setWeapon(std::string new_weapon)
{
    weapon = new_weapon;
}

std::string Player::getWeapon()
{
    return weapon;
}

int Player::getScore()
{
    return score;
}

sf::Sprite* Player::getSprite()
{
    return &sprite;
}

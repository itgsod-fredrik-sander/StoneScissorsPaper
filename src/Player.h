#ifndef __Stensaxpa_se__Player__
#define __Stensaxpa_se__Player__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Player
{
    public:
                        Player();
        void            update(bool changeTexture, bool updateTexture = false);
    public:
        std::string     getName();
        std::string     getWeapon();
        int             getScore();
        sf::Sprite*     getSprite();
        void            setScore(int new_score);
        void            setWeapon(std::string new_weapon);
    private:
        std::string     weapon;
        int             score;
        sf::Sprite      sprite;
        sf::Texture     texture;
    private:
        int             counter;
};

#endif /* defined(__Stensaxpa_se__Player__) */

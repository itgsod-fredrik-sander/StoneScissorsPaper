#ifndef __Stensaxpa_se__BoardRenderer__
#define __Stensaxpa_se__BoardRenderer__

#include <iostream>
#include <sstream>

#include "Player.h"

class GameRenderer
{
    public:
                            GameRenderer(Player &n_player1, Player &n_player2, sf::Time &countdownTimer, sf::RenderTarget& target);
        void                update();
        void                render();
        void                draw(const sf::Drawable& target);
    private:
        std::string         convertInt(int number);
    private:
        sf::RenderTarget    &target;
        sf::RectangleShape  background;
    private:
        sf::Time            countdownTime;
        sf::Font            font;
        sf::Text            score;
        sf::Text            timer;
    private:
        Player              &player1;
        Player              &player2;
};

#endif

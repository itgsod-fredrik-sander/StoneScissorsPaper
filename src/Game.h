#ifndef __Stensaxpa_se__Board__
#define __Stensaxpa_se__Board__

#include <iostream>

#include "GameRenderer.h"
#include "Player.h"
#include "Duel.h"

class Game
{
    public:
                        Game(sf::RenderTarget& target);
        void            processInput();
        void            update(sf::Time timerPerFrame);
        void            render();
    private:
        sf::RenderTarget &target;
        Player          player1;
        Player          player2;
    private:
        GameRenderer    renderer;
        sf::Time        countdownTimer;
        sf::Time        swapModelTimer;
        sf::Time        winnerTimer;
};

#endif

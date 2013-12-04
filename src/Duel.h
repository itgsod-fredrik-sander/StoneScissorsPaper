#ifndef __Stensaxpa_se__Duel__
#define __Stensaxpa_se__Duel__

#include <iostream>
#include "Player.h"

class Duel
{
    public:
        Duel(Player &p1, Player &p2);
        int winner();
    private:
        Player player1;
        Player player2;
};

#endif
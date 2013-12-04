#include "Duel.h"

Duel::Duel(Player &p1, Player &p2)
{
    player1 = p1;
    player2 = p2;
}

int Duel::winner()
{
    if (player1.getWeapon() == "Rock" && player2.getWeapon() == "Scissors")
    {
        return 1;
    }
    else if (player1.getWeapon() == "Scissors" && player2.getWeapon() == "Paper")
    {
        return 1;
    }
    else if (player1.getWeapon() == "Paper" && player2.getWeapon() == "Rock")
    {
        return 1;
    }
    else if (player2.getWeapon() == "Rock" && player1.getWeapon() == "Scissors")
    {
        return 2;
    }
    else if (player2.getWeapon() == "Scissors" && player1.getWeapon() == "Paper")
    {
        return 2;
    }
    else if (player2.getWeapon() == "Paper" && player1.getWeapon() == "Rock")
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
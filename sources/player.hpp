#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <stack>
#include "card.hpp"
#include <iostream>
#include <type_traits>

namespace ariel
{
}
using namespace ariel;
using namespace std;

class Player
{

 private:
    string name;
    stack<Card> num_of_card;
    int cards_gained;

 public:
    Player();

    Player(string name);

    int stacksize();

    string getPlayerName();

    void setPlayerName(string name);

    int cardesTaken();
    };

#endif
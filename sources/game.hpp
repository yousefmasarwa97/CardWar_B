#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include <iostream>

class Game{
    private:
        Player player1;
        Player player2;


    public:
        Game();
        Game(Player pl1,Player pl2);

        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();


    
};
#endif
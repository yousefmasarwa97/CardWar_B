#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <stack>
#include "card.hpp"
#include <iostream>
#include <type_traits>
#include <vector>



using namespace std;

namespace ariel
{

   class Player
   {

      private:
      string name;
      vector<Card> cards_owned;//the cards the player have
      vector<Card> cards_won;//all the cards that the player won
      int cards_gained;//the amount of cards the player won
      double win_rate;
      bool turned;//tell us if the card is turned in case of draw or not

      public:
      Player();

      Player(const char* name);

      

      int stacksize();//how much cards the player have on hand

      string getPlayerName();

      int cardesTaken();//how much cards the player won

      double get_winRate(Player &player,int rounds);

      void add_To_Owned_Cards(Card &card); // add card to the vector of cards that the player have
      void addWonCard(Card &card);
      string get_cards_won();
    
      Card playcard();
      Card playturnedcard();
   };
}
#endif
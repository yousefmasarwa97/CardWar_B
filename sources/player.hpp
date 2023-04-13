#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <stack>
#include "card.hpp"
#include <iostream>
#include <type_traits>
#include <vector>



//using namespace std;

namespace ariel
{

   class Player
   {

      private:
      string name;
      vector<Card> Collection_of_cards;//thecards the player have
      vector<Card> cards_won;
      int cards_gained;//the amount of cards the player won
      int wins;//the times the player won
      double win_rate;
      bool turned;//tell us if the card is turned in case of draw or not

      public:
      Player();

      Player(const char* name);

      //Player(const Player &player);

      int stacksize();//how much cards the player have

      string getPlayerName();

      void setPlayerName(string name);

      int cardesTaken();//how much cards the player won

      int get_wins();//how much times the player won

      double get_winRate();

      void addCardToCollection(Card &card); // add card to the vector of cards that the player have
      void addWonCard(Card &card);
      vector<Card> get_cards_won();
    
      Card playcard();
      Card playturnedcard();
   };
}
#endif

#include "card.hpp"
#include <string>
#include <vector>
#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include <iostream>

namespace ariel {


    class Game{
        private:


        Player &player1;
        Player &player2;
        int draws;//the amount of draws happend in the game
        int rounds;//the amount of rounds played
        int player1_wins;
        int player2_wins;
        bool isdraw;
        
        vector<Card> deck;
        vector<Card> cards_on_table_that_belongto_player1;//vector that have all the cards that in the table that player1 throw
        vector<Card> cards_on_table_that_belongto_player2;//vector that have all the cards that in the table that player2 throw
        vector<Card> cards_gained_from_other_player;//just the cards that gaind from the other player
        string lastTurn;//the state of the last turn
        string log;//the state of all turns
        string first_player_log;
        string second_player_log;


        public:
        Game(Player &player1,Player &player2);

        void playTurn();//play 1 turn

        void printLastTurn();
        void playAll();

        void printWiner();

        void printLog();//prints all the turns played one line per turn (same format as game.printLastTurn())


        void printStats();//for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
        int chekwinner(Card card1,Card card2);
        vector<Card> createDeck(); // create a new deck of cards
        void shuffleDeck(vector<Card>& deck);//  shuffle the deck of cards
        void divideDeck(vector<Card>& deck);  // divide the deck of cards between two players
        string get_player_log(Player& player);//return the states of player
    
    };
}
#endif
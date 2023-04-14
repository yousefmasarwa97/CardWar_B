#include "player.hpp"
#include "card.hpp"
#include <string>
#include <vector>

using namespace std;

namespace ariel {


    Player::Player():name("yousef"){}
    Player::Player(const char* name):name(name),turned(false),cards_won({}){
        
    }

    string Player::getPlayerName(){
        return this->name;
    }

    int Player::cardesTaken() {
        return this->cards_won.size();
    }
    int Player::stacksize() {
        return this->cards_owned.size();
    }

    void Player::add_To_Owned_Cards(Card &card){
        this->cards_owned.push_back(card);
    }
    
    void Player::addWonCard(Card &card){
        this->cards_won.push_back(card);
    }



    double Player::get_winRate(Player &player,int rounds){
        int wins=player.cardesTaken()/2;//the amount of cards the player take from the other player is the amount of rounds he won
        double rate=(double)wins/rounds;
        return rate*100.0;
    }


    string Player::get_cards_won(){
        string result="";
         for(Card x:this->cards_won){
            result+=" {"+x.get_data()+"} ,";
         }
     return result;
    }

    Card Player::playcard(){
        Card card=this->cards_owned.back();
        this->cards_owned.pop_back();
        turned=false;
        return card;
    }

    Card Player::playturnedcard(){
        Card card=this->cards_owned.back();
        this->cards_owned.pop_back();
        turned=true;
        return card;
    }
}
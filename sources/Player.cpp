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

    void Player::setPlayerName(string name){
        this->name=name; 

    }

    int Player::cardesTaken() {
        return this->cards_won.size();
    }
    int Player::stacksize() {
        return this->Collection_of_cards.size();
    }

    void Player::addCardToCollection(Card &card){
        this->Collection_of_cards.push_back(card);
    }
    
    void Player::addWonCard(Card &card){
        this->cards_won.push_back(card);
    }



    double Player::get_winRate(){
        int wins=cardesTaken()/2;//the amount of cards the player take from the other player is the amount of rounds he won
        double rate=(double)wins/26;
        return rate*100;
    }


    string Player::get_cards_won(){
        string result="";
         for(Card x:this->cards_won){
            result+=", {"+x.get_data()+","+x.get_type()+"} ,";
         }
     return result;
    }

    Card Player::playcard(){
        Card card=this->Collection_of_cards.back();
        this->Collection_of_cards.pop_back();
        turned=false;
        return card;
    }

    Card Player::playturnedcard(){
        Card card=this->Collection_of_cards.back();
        this->Collection_of_cards.pop_back();
        turned=true;
        return card;
    }
}
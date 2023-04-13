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

    int Player::get_wins(){
        return this->wins;
    }

    double Player::get_winRate(){
        double rate=(double)this->wins/52;
        return rate/100;
    }


    vector<Card> Player::get_cards_won(){
        return this->cards_won;
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
#include "player.hpp"
#include <string>

using namespace std;
using namespace ariel;

Player::Player(){}
Player::Player(string name){
    this->name=name;
}

string Player::getPlayerName(){
    return this->name;
}

void Player::setPlayerName(string name){
   this->name=name; 
}

int Player::cardesTaken() {
    return 0;
}
int Player::stacksize() {
    return 0;
}
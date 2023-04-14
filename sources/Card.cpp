#include "card.hpp"
#include <string>


using namespace std;
namespace ariel {


    Card::Card(string type, string value){
        this->type=type;
        this->value=value;
    }

    int Card::get_value(){
        if (this->value=="ACE") {
        return 1;
        }
        else if (this->value=="TWO") {
        return 2;
        }
        else if (this->value=="THREE") {
        return 3;
        }
        else if (this->value=="FOUR") {
        return 4;
        }
        else if (this->value=="FIVE") {
        return 5;
        }
        else if (this->value=="SIX") {
        return 6;
        }
        else if (this->value=="SEVEN") {
        return 7;
        }
        else if (this->value=="EIGHT") {
        return 8;
        }
        else if (this->value=="NINE") {
        return 9;
        }
        else if (this->value=="TEN") {
        return 10;
        }
        else if (this->value=="JACK") {
        return 11;
        }
        else if (this->value=="QUEN") {
        return 12;
        }
        else if (this->value=="KING") {
        return 13;
        }
        else {
        throw "error:invalid value";
        }
    }

    string Card::get_type(){
        return this->type;
    }

    string Card::get_data(){
        return this->value;
    }






}

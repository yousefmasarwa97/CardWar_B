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
        else if (this->value=="SEX") {
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
// string Card::suitName (Type suit) {
//     switch(suit) {
//         case clubs: return "Clubs";
//         case diamonds: return "Diamonds";
//         case hearts: return "Hearts";
//         case spades: return "Spades";
//         default: throw std::out_of_range("Type value out of range");
//     }
// }

// string Card::valueName (Value value) {
//     switch(value) {
//     case ace: return "Ace";
//     case two: return "2";
//     case three: return "3";
//     case four: return "4";
//     case five: return "5";
//     case six:  return "6";
//     case seven: return "7";
//     case eight: return "8";
//     case nine: return "9";
//     case ten: return "10";
//     case jack: return "Jack";
//     case queen: return "Queen";
//     case king: return "King";
//     default: throw std::out_of_range("Face value out of range");
//     }

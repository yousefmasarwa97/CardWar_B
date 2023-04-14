#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <stdio.h>
#include <stack>
#include <iostream>
#include <type_traits>


//using namespace ariel;
using namespace std;

namespace ariel {


    class Card{

        private:
        string type;
        int value;


        public:
        Card(string type,int value);
        int get_value();
        string get_type();
        string get_data();//return the value of the card and the type in string



   


    };
}
#endif






















//      public:
//         enum Suit {clubs, diamonds, hearts, spades};
//         enum Value {two = 2, three, four, five, six, seven, eight, nine, 
//         ten, jack, queen, king, ace};

//         Card (Value faceValue=two, Suit suit = clubs):
//             suit (suit), faceValue(faceValue) {}

//             // Getters
//         Suit getSuit()  { return suit; }
//         Value getValue()  { return faceValue; }


//         static string suitName (Suit suitName);
//         static string valueName (Value valueName);

//         string to_string() { return valueName (faceValue) +
//          " of " + suitName(suit);}

           
//     private:
//         Suit suit;
//         Value faceValue;

// };





//     private:
//     string type;
//     int value;
//     string name;

//     public:
//     Card(string type,string name,int value);

//     int get_Cardvalue();
//     string get_Cardname();
//     string get_Cardtype();

     
// };




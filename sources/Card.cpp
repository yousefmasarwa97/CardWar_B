#include "card.hpp"
#include <string>




using namespace std;
namespace ariel {


   Card::Card(string type, int value){
      this->type=type;
      this->value=value;
   }

   int Card::get_value(){
     return this->value;
   }

   string Card::get_type(){
      return this->type;
   }

   string Card::get_data(){
      if (this->get_value()==14) {
         return "ACE OF "+ this->get_type();
      }
      else if (this->get_value()==2) {
         return "TWO OF "+ this->get_type();
      }
      else if (this->get_value()==3) {
         return "THREE OF "+ this->get_type();
      }
      else if (this->get_value()==4) {
         return "FOUR OF "+ this->get_type();
      }
      else if (this->get_value()==5) {
         return "FIVE OF "+ this->get_type();
      }
      else if (this->get_value()==6) {
         return "SIX OF "+ this->get_type();
      }
      else if (this->get_value()==7) {
         return "SEVEN OF "+ this->get_type();
      }
      else if (this->get_value()==8) {
         return "EIGHT OF "+ this->get_type();
      }
      else if (this->get_value()==9) {
         return "NINE OF "+ this->get_type();
      }
      else if (this->get_value()==10) {
         return "TEN OF "+ this->get_type();
      }
      else if (this->get_value()==11) {
         return "JACK OF "+ this->get_type();
      }
      else if (this->get_value()==12) {
         return "QUEN OF "+ this->get_type();
      }
      else if (this->get_value()==13) {
         return "KING OF "+ this->get_type();
      }
      throw "invalid value!";
   }
}

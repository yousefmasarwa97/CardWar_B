#include "game.hpp"
#include "card.hpp"
#include "player.hpp"
#include <algorithm>
#include <random>
#include <chrono>
#include <string>



using namespace std;
using namespace ariel;



namespace ariel {
 
   Game::Game(Player &player1,Player &player2):player1(player1),player2(player2){



      this->deck = createDeck();
      shuffleDeck(this->deck);
      divideDeck(this->deck);
   
      rounds=0;
      player1_wins=0;
      player2_wins=0;
      lastTurn="";
      log="";
      first_player_log="";
      second_player_log="";
      cards_on_table_that_belongto_player1={};
      cards_on_table_that_belongto_player2={}; 
      
      
      
      
      
    
   }

   

   void Game::printLastTurn(){
      cout<<this->lastTurn<<endl;
   }

   string Game::get_player_log(Player &player){
      string result="";
      result+=player.getPlayerName() + "{\n"
      + "\tamout of rounds : " + to_string(rounds) + "\n"
      + "\twins : " + to_string(player.cardesTaken()/2) + "\n"
      + "\tamount of draws : " + to_string(this->draws) + "\n"
      + "\tdraw rate : " + to_string((double)this->draws/rounds*100.0) + "%\n" 
      + "\twinRates : " + to_string(player.get_winRate()) + "%\n"
      + "\tCards [ \n" 
      + player.get_cards_won() + "\n"
      + "\t]\n"
      + "}\n\n";
      return result;

   }

   void Game::playAll(){
      while (player1.stacksize()!=0 && player2.stacksize()!=0) {
         playTurn();
      }


     

   }

   void Game::printWiner(){
      if(player1.cardesTaken()>player2.cardesTaken()){
         cout<<"the winner is: "<<player1.getPlayerName()<<endl;
      }
      else if(player2.cardesTaken()>player1.cardesTaken()) {
      cout<<"the winner is: "<<player2.getPlayerName()<<endl;
      }
      else {
      cout<<"DRAW:NO WINER"<<endl;
      }
   }

   void Game::printLog(){
      cout<<this->log<<endl;
   }

   void Game::printStats(){
      first_player_log=get_player_log(player1);
      cout<<player1.getPlayerName()<<first_player_log<<endl;
      second_player_log=get_player_log(player2);
      cout<<player2.getPlayerName()<<second_player_log<<endl;
   }

   void Game::playTurn(){
      if (rounds==26) {
         throw ("game is over!");
         return;
      }


      if(player1.getPlayerName()==player2.getPlayerName()){
         throw ("error: the same player are playing againts his self");
         return;
      }

      if (player1.stacksize()==0 || player2.stacksize()==0) {
        throw ("game is over!");
         return;
      }

      else {
         rounds++;
         Card card1=player1.playcard();
         cards_on_table_that_belongto_player1.push_back(card1);
         Card card2=player2.playcard();
         cards_on_table_that_belongto_player2.push_back(card2);
         lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " " +card1.get_type()+" "+
         player2.getPlayerName() + " played " + card2.get_data()+" "+card2.get_type() + ". ";
         int static result=chekwinner(card1, card2);
         while (result==0) {
            rounds+=2;
            draws++;
            lastTurn+="DRAW."; 
            log+=lastTurn;
            Card c1=player1.playturnedcard();
            cards_on_table_that_belongto_player1.push_back(c1);

            Card c2=player2.playturnedcard();
            cards_on_table_that_belongto_player2.push_back(c2);

            Card c11=player1.playcard();
            cards_on_table_that_belongto_player1.push_back(c11);

            Card c22=player2.playcard();
            cards_on_table_that_belongto_player2.push_back(c22);
            
            

            result=chekwinner(c11,c22);
    
        
         }

         if (result==1) {
            lastTurn+=player1.getPlayerName()+" "+"WON.";
            log+=lastTurn;
            for (Card x:cards_on_table_that_belongto_player2) {
               player1.addWonCard(x);
            }
            for(Card y:cards_on_table_that_belongto_player1){
               player1.addWonCard(y);
            }
            

            cards_on_table_that_belongto_player1.clear();
            cards_on_table_that_belongto_player2.clear();
         }

         else if (result==2) {
            lastTurn+=player2.getPlayerName()+" "+"WON.";
            log+=lastTurn;
            for (Card x:cards_on_table_that_belongto_player1) {
               player2.addWonCard(x);
            }
            for(Card y:cards_on_table_that_belongto_player2){
               player2.addWonCard(y);
            }
              
          cards_on_table_that_belongto_player1.clear();
          cards_on_table_that_belongto_player2.clear();
         }
      }
      
   }

   int Game::chekwinner(Card card1,Card card2){
      if (card1.get_value()==card2.get_value()) {
      return 0;
      }
      else if (card1.get_value()>card2.get_value()) {
      return 1;
      }
      else if (card1.get_value()<card2.get_value()){
      return 2;
      }
      return -1;
   }

   vector<Card> Game::createDeck(){
      vector<Card> deck;
      for (string type:{"DIAMONDS","HEARTS","SPADES","CLUBS"}){
         for (string value:{"ACE","TWO","THREE","FOUR","FIVE","SEX","SEVEN",
            "EIGHT","NINE","TEN","JACK","QUEEN","KING"}){
            deck.push_back(Card(type,value));
         }
      }
      return deck;
   }

   void Game::shuffleDeck(vector<Card> &deck){
      random_device rd;
      mt19937 g(rd());
      shuffle(deck.begin(), deck.end(), g);
   }

   void Game::divideDeck(vector<Card> &deck){
      int counter = 0;
      for (Card card : deck){
         if (counter % 2 == 0){
            this->player1.addCardToCollection(card);
            counter++;
            }
         else{
            this->player2.addCardToCollection(card);
            counter++;
         }
      }
   }

  




}

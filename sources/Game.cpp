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
      draws=0;
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
      cout<<lastTurn<<endl;
   }

   string Game::get_player_log(Player &player){
      string result="";
      result+=player.getPlayerName() + "{\n"
      + "\tamout of rounds : " + to_string(rounds) + "\n"
      + "\twins : " + to_string(player.cardesTaken()/2) + "\n"
      + "\tamount of draws : " + to_string(this->draws) + "\n"
      + "\tdraw rate : " + to_string((double)this->draws/rounds*100.0) + "%\n" 
      + "\twinRates : " + to_string((player.cardesTaken()/2)/rounds*100) + "%\n"
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
         throw ("error: the same player are playing againts him self");
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
         int static result=chekwinner(card1, card2);

         if (result==1) {
            for (Card x:cards_on_table_that_belongto_player2) {
               player1.addWonCard(x);
            }

            for(Card y:cards_on_table_that_belongto_player1){
               player1.addWonCard(y);
            }

            lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " of " +card1.get_type()+" "+
            player2.getPlayerName() + " played " + card2.get_data()+" of "
            +card2.get_type() + ". "+player1.getPlayerName()+" "+ "WON.";
            //log+=lastTurn;
            player1_wins++;
            
            

            cards_on_table_that_belongto_player1.clear();
            cards_on_table_that_belongto_player2.clear();
         }


         if (result==2) {
            for (Card x:cards_on_table_that_belongto_player1) {
               player2.addWonCard(x);
            }
            for(Card y:cards_on_table_that_belongto_player2){
               player2.addWonCard(y);
            }
            lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " of " +card1.get_type()+" "+
            player2.getPlayerName() + " played " + card2.get_data()+" of "
            +card2.get_type() + ". "+player2.getPlayerName()+" "+ "WON.";
            //log+=lastTurn;
            result=2;
              
          cards_on_table_that_belongto_player1.clear();
          cards_on_table_that_belongto_player2.clear();
          
         }


         else if (result==0) {
            rounds+=2;
            draws++;
            lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " of " +card1.get_type()
            +" "+player2.getPlayerName() + " played " + card2.get_data()+" of "
            +card2.get_type() + ". "+ "DRAW.";
            //log+=lastTurn;

            bool flag=false;
            int static result1;

            while (!flag) {
               Card c1=player1.playturnedcard();
               cards_on_table_that_belongto_player1.push_back(c1);

               Card c2=player2.playturnedcard();
               cards_on_table_that_belongto_player2.push_back(c2);

               Card c11=player1.playcard();
               cards_on_table_that_belongto_player1.push_back(c11);

               Card c22=player2.playcard();
               cards_on_table_that_belongto_player2.push_back(c22);
               result1=chekwinner(c11, c22);

               if (result1==1) {
                  for (Card x:cards_on_table_that_belongto_player2) {
                     player1.addWonCard(x);
                  }

                  for(Card y:cards_on_table_that_belongto_player1){
                     player1.addWonCard(y);
                  }

                  lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " of " +card1.get_type()+" "+
                  player2.getPlayerName() + " played " + card2.get_data()+" of "
                  +card2.get_type() + ". "+player1.getPlayerName()+" "+ "WON.";
                  //log+=lastTurn;
                  result=1;
               
            

                  cards_on_table_that_belongto_player1.clear();
                  cards_on_table_that_belongto_player2.clear();
                  flag=true;
                  break;
               }

      
               else if (result1==2) {
                  for (Card x:cards_on_table_that_belongto_player1) {
                     player2.addWonCard(x);
                  }

                  for(Card y:cards_on_table_that_belongto_player2){
                     player2.addWonCard(y);
                  }

                  lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " of " +card1.get_type()+" "+
                  player2.getPlayerName() + " played " + card2.get_data()+" of "
                  +card2.get_type() + ". "+player2.getPlayerName()+" "+ "WON.";
                  //log+=lastTurn;
                  result=2;
              
                  cards_on_table_that_belongto_player1.clear();
                  cards_on_table_that_belongto_player2.clear();
                  flag=true;
                  break;
                  
               }
               else {
                  draws++;
                  lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " of " +card1.get_type()
                  +" "+player2.getPlayerName() + " played " + card2.get_data()+" of "
                  +card2.get_type() + ". "+ "DRAW.";
                  //log+=lastTurn;
                  flag=false;
               }

            }
            
         }
         
      }
      
   }

   int Game::chekwinner(Card card1,Card card2){
      int res;
      if (card1.get_value()==card2.get_value()) {
         res=0;
      }

      else if (card1.get_value()>card2.get_value()) {
         res=1;
      }

      else if (card1.get_value()<card2.get_value()){
         res=2;
      }
      return res;
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

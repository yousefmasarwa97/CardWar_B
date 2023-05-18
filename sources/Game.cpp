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
      shuffle_and_divide(this->deck);
      
   
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
   
   
   
   void Game::printStats(){
      first_player_log=get_player_log(player1);
      cout<<first_player_log<<endl;
      second_player_log=get_player_log(player2);
      cout<<second_player_log<<endl;
   }

   string Game::get_player_log(Player &player){
      string result="";
      result+=player.getPlayerName() + "{\n"
      + "\tamout of rounds : " + to_string(rounds) + "\n"
      + "\twins : " + to_string(player.cardesTaken()/2) + "\n"
      + "\tamount of draws : " + to_string(this->draws) + "\n"
      + "\tdraw rate : " + to_string((double)this->draws/rounds*100.0) + "%\n" 
      + "\twinRates : " + to_string(player.get_winRate(player, rounds)) + "%\n"
      + "\tCards [ " 
      + player.get_cards_won() +
      + "\t]\n";
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
      else if(player2.cardesTaken()<player1.cardesTaken()) {
         cout<<"the winner is: "<<player2.getPlayerName()<<endl;
      }
      else {
         cout<<"DRAW:NO WINER"<<endl;
      }
   }

   void Game::printLog(){
      cout<<this->log<<endl;
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

         if(card1.get_value() == 2 && card2.get_value() == 14){
            this->lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " "+
            player2.getPlayerName() + " played " + card2.get_data()+". "
            +player1.getPlayerName()+" "+ "WON.";
            log+=lastTurn;
            player1_wins++;

            
            for (Card x:cards_on_table_that_belongto_player2) {
               player1.addWonCard(x);
            }

            for(Card y:cards_on_table_that_belongto_player1){
               player1.addWonCard(y);
            }
            

            cards_on_table_that_belongto_player1.clear();
            cards_on_table_that_belongto_player2.clear();
         }


         else if(card1.get_value() == 14 && card2.get_value() == 2){
            this->lastTurn = player1.getPlayerName() + " played " + card1.get_data() +" "+
            player2.getPlayerName() + " played " + card2.get_data()+ ". "+player2.getPlayerName()+" "+ "WON.";
            log+=lastTurn;
            player2_wins++;


            for (Card x:cards_on_table_that_belongto_player1) {
               player2.addWonCard(x);
            }
            for(Card y:cards_on_table_that_belongto_player2){
               player2.addWonCard(y);
            }
            
              
            cards_on_table_that_belongto_player1.clear();
            cards_on_table_that_belongto_player2.clear();
          
         }

        

         else if (card1.get_value()>card2.get_value()) {
           this->lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " "+
            player2.getPlayerName() + " played " + card2.get_data()+". "
            +player1.getPlayerName()+" "+ "WON.";
            log+=lastTurn;
            player1_wins++;

            
            for (Card x:cards_on_table_that_belongto_player2) {
               player1.addWonCard(x);
            }

            for(Card y:cards_on_table_that_belongto_player1){
               player1.addWonCard(y);
            }
            

            cards_on_table_that_belongto_player1.clear();
            cards_on_table_that_belongto_player2.clear();
         }


         else if (card1.get_value()<card2.get_value()) {
            this->lastTurn = player1.getPlayerName() + " played " + card1.get_data() +" "+
            player2.getPlayerName() + " played " + card2.get_data()+ ". "+player2.getPlayerName()+" "+ "WON.";
            log+=lastTurn;
            player2_wins++;


            for (Card x:cards_on_table_that_belongto_player1) {
               player2.addWonCard(x);
            }
            for(Card y:cards_on_table_that_belongto_player2){
               player2.addWonCard(y);
            }
            
              
            cards_on_table_that_belongto_player1.clear();
            cards_on_table_that_belongto_player2.clear();
          
         }


         else if (card1.get_value()==card2.get_value()) {
            rounds+=2;
            draws++;
            this->lastTurn = player1.getPlayerName() + " played " + card1.get_data() + 
            " "+player2.getPlayerName() + " played " + card2.get_data()+ ". " + "DRAW.";
            log+=lastTurn;

            bool flag=false;
        

            while (flag==false) {
               if(player1.stacksize()>=2 && player2.stacksize()>=2){
                  Card c1=player1.playturnedcard();
                  cards_on_table_that_belongto_player1.push_back(c1);

                  Card c2=player2.playturnedcard();
                  cards_on_table_that_belongto_player2.push_back(c2);

                  Card c11=player1.playcard();
                  cards_on_table_that_belongto_player1.push_back(c11);

                  Card c22=player2.playcard();
                  cards_on_table_that_belongto_player2.push_back(c22);

                  if(card1.get_value() == 2 && card2.get_value() == 14){
                     this->lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " "+
                     player2.getPlayerName() + " played " + card2.get_data()+". "
                     +player1.getPlayerName()+" "+ "WON.";
                     log+=lastTurn;
                     player1_wins++;

            
                     for (Card x:cards_on_table_that_belongto_player2) {
                        player1.addWonCard(x);
                     }

                     for(Card y:cards_on_table_that_belongto_player1){
                        player1.addWonCard(y);
                     }
            

                     cards_on_table_that_belongto_player1.clear();
                     cards_on_table_that_belongto_player2.clear();
                  }


                  else if(card1.get_value() == 14 && card2.get_value() == 2){
                     this->lastTurn = player1.getPlayerName() + " played " + card1.get_data() +" "+
                     player2.getPlayerName() + " played " + card2.get_data()+ ". "+player2.getPlayerName()+" "+ "WON.";
                     log+=lastTurn;
                     player2_wins++;


                     for (Card x:cards_on_table_that_belongto_player1) {
                        player2.addWonCard(x);
                     }
                     for(Card y:cards_on_table_that_belongto_player2){
                        player2.addWonCard(y);
                     }
            
              
                     cards_on_table_that_belongto_player1.clear();
                     cards_on_table_that_belongto_player2.clear();
          
                  }
              
               
                  if (c11.get_value()>c22.get_value()) {
                     this->lastTurn = player1.getPlayerName() + " played " + card1.get_data() + " "+
                     player2.getPlayerName() + " played " + card2.get_data()+". "
                     +player1.getPlayerName()+" "+ "WON.";
                     log+=lastTurn;
                     player1_wins++;

            
                     for (Card x:cards_on_table_that_belongto_player2) {
                        player1.addWonCard(x);
                     }

                     for(Card y:cards_on_table_that_belongto_player1){
                        player1.addWonCard(y);
                     }
            

                     cards_on_table_that_belongto_player1.clear();
                     cards_on_table_that_belongto_player2.clear();
              
                     flag=true;
                     break;
                  }

      
                  else if (c11.get_value()<c22.get_value()) {
                     this->lastTurn = player1.getPlayerName() + " played " + card1.get_data() +" "+
                     player2.getPlayerName() + " played " + card2.get_data()+ ". "+player2.getPlayerName()+" "+ "WON.";
                     log+=lastTurn;
                     player2_wins++;


                     for (Card x:cards_on_table_that_belongto_player1) {
                        player2.addWonCard(x);
                     }
                     for(Card y:cards_on_table_that_belongto_player2){
                        player2.addWonCard(y);
                     }
            
              
                     cards_on_table_that_belongto_player1.clear();
                     cards_on_table_that_belongto_player2.clear();
          
                  
                     flag=true;
                     break;
                  
                  }

                  else {
                     draws++;
                     lastTurn = player1.getPlayerName() + " played " + card1.get_data() + 
                     " "+player2.getPlayerName() + " played " + card2.get_data()+ ". "+ "DRAW.";
                     log+=lastTurn;
                     flag=false;
                  }
               }

            
               else{

                  for (Card x:cards_on_table_that_belongto_player1) {
                     player1.addWonCard(x);
                  }

                  for(Card y:cards_on_table_that_belongto_player2){
                     player2.addWonCard(y);
                  }
            

                  cards_on_table_that_belongto_player1.clear();
                  cards_on_table_that_belongto_player2.clear();
                     
                  if (player1.stacksize() == 1) {
                     // assert(player2.stacksize()==1)
                     Card c1=player1.playcard();
                     Card c2=player2.playcard();
                   
                     player1.addWonCard(c1);
                     player2.addWonCard(c2);
                     flag=true;
                     break;
                  }
               }
                    
            }
         }
            
      }
         
   }


   vector<Card> Game::createDeck(){
      vector<Card> deck;
      for (string type:{"DIAMONDS","HEARTS","SPADES","CLUBS"}){
         for(int i=2;i<=14;i++){
            deck.push_back(Card(type,i));
         }
      }
      return deck;
   }

   void Game::shuffle_and_divide(vector<Card> &deck){
      int counter = 0;
      random_device rd;
      mt19937 g(rd());
      shuffle(deck.begin(), deck.end(), g);
      //dividing the cards
      for (Card card : deck){
         if (counter % 2 == 0){
            this->player1.add_To_Owned_Cards(card);
            counter++;
            }
         else{
            this->player2.add_To_Owned_Cards(card);
            counter++;
         }
      }
   }
}
 



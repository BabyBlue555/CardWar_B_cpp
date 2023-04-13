#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
//#include <algorithm>
#include <random>
using namespace std;
using namespace ariel;



// inline constructor
Game::Game(Player& plr1, Player& plr2)
: p1(plr1), p2(plr2),log(""),lastTurnStats(""),num_turns(0), num_draws(0), num_wins_p1(0), num_wins_p2(0)
{   
    // this->p1=&plr1;
    // this->p2=&plr2;
    

    /// QUESTION - is it okay that two players have the same name?
        if(plr1.getName().empty()){
            throw invalid_argument("player one has no name!");
        }
        if(plr2.getName().empty()){
            throw invalid_argument("player two has no name!");
        }
        if(plr1.isPlaying() || plr2.isPlaying()){
            throw invalid_argument("one of the players are playing in another game!");
        }
        // this->p1 = plr1;
        // this->p2 = plr2;
        // vector<Card>& vector_game={};
        // vector<Card>& vector_p1={};
        // vector<Card>& vector_p2={};



        initializeCards();
        
     }


void Game::initializeCards(){
    //1.initialize the game card deck
     
        //std:: vector<Card> vector_game;
        
        // auto rng = std::default_random_engine {};
        // std::shuffle(std::begin(vector_game), std::end(vector_game), rng);

        for(unsigned long i=0;i<vector_suit.size();i++){
            for(size_t j=2;j<=10;j++){
                vector_game.push_back(Card(j,vector_suit[i]));
            }
            vector_game.push_back(Card('A',vector_suit[i])); // ace
             vector_game.push_back(Card('J',vector_suit[i]));// prince
             vector_game.push_back(Card('Q',vector_suit[i]));// queen
             vector_game.push_back(Card('K',vector_suit[i]));// king
        }
    // 2.shuffle cards
        // using built-in random generator from algorithm and random class:
        // i got it from the  first answer - https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector 
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(vector_game), std::end(vector_game), rng);
            // print out content:
        int counter=0;
      //  std::cout << "myvector contains:";
        //for (std::vector<Card>::iterator it=vector_game.begin(); it!=vector_game.end(); ++it){
      //  std::cout << *it <<endl;
        // counter++;
        //std::cout << counter<<endl;
      //  }
        //std::cout << counter<<endl;
        //std::cout << '\n';
    
    //3. give 26 cards to p1 and 26 cards to p2
       // std::vector<Card> vect1;  // player 1's deck
        //std::vector<Card>  vect2;  // player 2's deck
        vector<Card> vector_p1=(p1).getDeck();
        vector<Card> vector_p2=(p2).getDeck();

        for(int i=0;i<26;i++){
            vector_p1.push_back(vector_game.back()); // puts the last element in the game deck in player 1's deck
            if(!vector_game.empty()){
            vector_game.pop_back();
            }
            vector_p2.push_back(vector_game.back()); // puts the last element in the game deck in player 1's deck
            if(!vector_game.empty()){
            vector_game.pop_back();
            }
           // printf(vector_p1.front());
        
        }
        p1.setDeck(vector_p1);
        p2.setDeck(vector_p2);
        
        // printf("printing................");
        // printf("size of vector in game: %lu" ,vector_p1.size());
        // printf("size of vector in player: %lu", p1.getDeck().size());
        // printf("stacksize: %lu " , p1.stacksize());

        // free from memory
        // vector_game.clear();
        // vector_suit.shrink_to_fit();
        // vector_suit.clear();
        // vector_game.shrink_to_fit();

        // cout<<"printing deck of p1!!!!!11"<<endl;
        //  for(size_t i=0;i<26;i++){
        //     cout<<p2.getDeck()[i].toString()<<endl;
    
        //  }


        // set players in game
        p1.setPlaying(1);
        p2.setPlaying(1);
        
}

// "outline" method implementation:
void Game::printLastTurn(){
    cout<<"Last Turn results:"<<endl;
    cout<<this->lastTurnStats<<endl;
    //Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
    //this->lastTurnStats = "Turn " + to_string(this->turn) + ":\n" + p1.getName() + " played " + p1Card.toString() + " " + p2.getName() + " played " + p2Card.toString() + ". ";
};

void Game::playTurn(){
   size_t size_before_p1=p1.stacksize();
   size_t size_before_p2=p2.stacksize();
   
   int draw=0;
   int num_draws_in_turn = 0; // for stats and lastTurn
   this->lastTurnStats = "";
   
   num_turns++;

   cout<<"printing winning so far:"<<endl;
   cout<<"P1:"<<to_string(p1.cardesTaken())<<endl;
   cout<<"P2:"<<to_string(p2.cardesTaken())<<endl;
    
    if(&p1==&p2){
        throw logic_error("one player cannot play the game alone!");
    }

    if(p1.isPlaying() && p2.isPlaying()&& (!p1.getDeck().empty() && !p2.getDeck().empty())){

     //edge case - each player has one card left - i took care of it by 
     // removing the if before the < , >

    //  if(p1.stacksize()==1 && p2.stacksize()==1){

    //  }
     
     
        // remove cards from deck

        cout<<"remove cards from deck..."<<endl;
        Card p1_curr_card=p1.getCurrCard();
        Card p2_curr_card=p2.getCurrCard();
        p1.popCard(p1.getDeck());
        p2.popCard(p2.getDeck());
        cout<<p1.stacksize()<<endl;
        cout<<p2.stacksize()<<endl;


        cout<<"card of p1: "<<p1_curr_card.toString()<<endl;
        cout<<"card of p2: "<<p2_curr_card.toString()<<endl;
        
//Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
        this->lastTurnStats+=p1.getName()+" played "+p1_curr_card.toString()+" and "+p2.getName()+" played "+p2_curr_card.toString()+"\n";

        //option 1 - draw 
        while(p1_curr_card==p2_curr_card){
            draw=1;
            num_draws++;
            cout<<"PRINTING NUM DRAWS//////////////////////////////////";
            cout<<to_string(num_draws)<<endl;
            num_draws_in_turn++;
            if(!p1.getDeck().empty() && !p2.getDeck().empty()){
            // close card
                 p1_curr_card= p1.getCurrCard();
                p2_curr_card=p2.getCurrCard();
                p1.popCard(p1.getDeck());
                p2.popCard(p2.getDeck());

            // open card
                p1_curr_card= p1.getCurrCard();
                p2_curr_card=p2.getCurrCard();
                p1.popCard(p1.getDeck());
                p2.popCard(p2.getDeck());

                cout<<"card of p1: "<<p1_curr_card.toString()<<endl;
        cout<<"card of p2: "<<p2_curr_card.toString()<<endl;
 
            }
            else{
                cout<<"stack size is empty!"<<endl;
                p1.addCardsTaken(size_before_p1,draw);
                p2.addCardsTaken(size_before_p2,draw);
                break;
            }
        if(p1_curr_card >p2_curr_card || p1_curr_card < p2_curr_card){
                draw=0;
            }
        
        // adds the draw/s to the turn's statistics
        this->lastTurnStats+=p1.getName()+" played "+p1_curr_card.toString()+" and "+p2.getName()+" played "+p2_curr_card.toString();        
        
        } // end-of-while

        
        // option 2- one of the players won the turn 
       // if(!p1.getDeck().empty() && !p2.getDeck().empty()){
        if(p1_curr_card >p2_curr_card){
            p1.addCardsTaken(size_before_p1,draw);
            num_wins_p1++;
            this->lastTurnStats+="the winner in the last turn is: "+p1.getName()+"the number of draws in this turn is: "+to_string(num_draws_in_turn)+ "number of cards overall: "+to_string(p1.cardesTaken());
        }

        else if(p1_curr_card <p2_curr_card){
            p2.addCardsTaken(size_before_p2,draw);
            num_wins_p2++;
            this->lastTurnStats+="the winner in the last turn is: "+p2.getName()+"the number of draws in this turn is: "+to_string(num_draws_in_turn)+ "number of cards overall: "+to_string(p2.cardesTaken());
        }
      //  }
     

    }

    else{
        throw logic_error("the game is over! can't do another turn...");
    }



    // printf("entering pop...........");
    // printf("stacksize after pop: %lu", p1.stacksize());
    
    // add the last turn stats to the existing stats of the whole game.
    this->log+=(this->lastTurnStats)+'\n';
    //  printLastTurn();
    //   printLog();
    printStats();
};


void Game::playAll(){
    cout<<"playAll"<<endl;
    while(!p1.getDeck().empty() && !p1.getDeck().empty()) {
        this->playTurn();
    }
    p1.setPlaying(0);
    p2.setPlaying(0);

};

void Game::printWiner(){
    cout<<"printWiner:"<<endl;
    if(p1.isPlaying()|| p2.isPlaying()){ //shouln't return an error, but can't print a winner when at least one of the players are still playing
        cout<<"at least one of the players is still playing...";
        return;
    }
    if(p1.cardesTaken()>p2.cardesTaken()){
        cout<<"player 1 is the winner"<<endl;
    }
    else if(p1.cardesTaken()<p2.cardesTaken()){
        cout<<"player 2 is the winner"<<endl;
    }
    else if (p1.stacksize()==0 && p2.stacksize()==0){
       // throw logic_error("the game ended in tie - there is no winner!"); 
       cout<<"the game has ended in a tie between the players"<<endl;
    }
    // else{
    //     throw logic_error("the game hasn't finished yet!");
    // }
   
};

void Game::printLog(){
    
    cout<<"printLog-printing all the turns played one line per turn:"<<endl;
    cout<<this->log<<endl;
};

void Game::printStats(){
    cout<<"printStats"<<endl;
   // size_t draw_rate=0;
    //amount of draws that happand -this->num_draws
    //size_t win_rate=(num_wins_p1/num_turns)*100;
   // size_t cards_won=p1.cardesTaken();
   cout<<"number of turns:"+to_string(num_turns)<<endl;
    cout<<"player1- "+p1.getName()+ " stats:"<<endl;
    cout<<"number of winning turns: "+to_string(num_wins_p1)<<endl;
    cout<<"win rate:"+to_string(int(((float)num_wins_p1/num_turns)*100))+"%"<<endl;
    cout<<"cards won:"+to_string(p1.cardesTaken())<<endl;
    cout<<"draw_rate:"+to_string(int(((float)num_draws/num_turns)*100))+"%"<<endl;
    cout<<"number of draws:"+to_string(this->num_draws)<<endl;

    cout<<"player1- "+p2.getName()+ " stats:"<<endl;
    cout<<"number of winning turns: "+to_string(num_wins_p2)<<endl;
    cout<<"win rate:"+to_string(int(((float)num_wins_p2/num_turns)*100))+"%"<<endl;
    cout<<"cards won:"+to_string(p2.cardesTaken())<<endl;
    cout<<"draw_rate:"+to_string(int(((float)num_draws/num_turns)*100))+"%"<<endl;
    cout<<"number of draws:"+to_string(this->num_draws)<<endl;
    

};



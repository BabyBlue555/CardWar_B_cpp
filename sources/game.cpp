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
: p1(plr1), p2(plr2) 
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
            for(int j=2;j<=10;j++){
                vector_game.push_back(Card(j,vector_suit[i]));
            }
            vector_game.push_back(Card('A',vector_suit[i])); // ace
             vector_game.push_back(Card('J',vector_suit[i]));// prince
             vector_game.push_back(Card('Q',vector_suit[i]));// queen
             vector_game.push_back(Card('K',vector_suit[i]));// king
        }
    // 2.shuffle cards
        // using built-in random generator:
        //  std::random_shuffle ( vector_game.begin(), vector_game.end() );
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

        // set players in game
        p1.setPlaying(1);
        p2.setPlaying(1);
        
}

// "outline" method implementation:
void Game::printLastTurn(){
    cout<<"printLastTurn"<<endl;
};

void Game::playTurn(){
   size_t size_before=p1.stacksize();
   int draw=0;
    
    if(&p1==&p2){
        throw logic_error("one player cannot play the game alone!");
    }

    if(p1.isPlaying() && p2.isPlaying()&& (!p1.getDeck().empty() && !p2.getDeck().empty())){
        
        // remove cards from deck
        Card p1_curr_card= p1.popCard(p1.getDeck());
        Card p2_curr_card=p2.popCard(p2.getDeck()); 
        
        while(&p1_curr_card==&p2_curr_card){
            draw=1;
            if(!p1.getDeck().empty() && !p2.getDeck().empty()){
            // close card
                p1.popCard(p1.getDeck()); 
                p2.popCard(p2.getDeck());

            p1_curr_card= p1.popCard(p1.getDeck());
            p2_curr_card=p2.popCard(p2.getDeck()); 
            }
            else{
                cout<<"stack size is empty!"<<endl;
            }
        if(&p1_curr_card >&p2_curr_card || &p1_curr_card < &p2_curr_card){
                draw=0;
            }
            
        
        
        }

        
        if(&p1_curr_card > &p2_curr_card){
            p1.addCardsTaken(size_before,draw);
        }

        else{
            p2.addCardsTaken(size_before,draw);
        }
    }	
    else{
        throw logic_error("empty!");
    }

    // printf("entering pop...........");
    // printf("stacksize after pop: %lu", p1.stacksize());

};


void Game::playAll(){
    cout<<"playAll"<<endl;
    while(!p1.getDeck().empty() && !p1.getDeck().empty()) {
        this->playTurn();
    }

};

void Game::printWiner(){
    cout<<"printWiner"<<endl;
    if(p1.cardesTaken()>p2.cardesTaken()){
        cout<<"player 1 is the winner"<<endl;
    }
    else if(p1.cardesTaken()<p2.cardesTaken()){
        cout<<"player 2 is the winner"<<endl;
    }
    // QUESTION - is it a logic error?
    else if (p1.stacksize()==0 && p2.stacksize()==0){
       // throw logic_error("the game ended in tie - there is no winner!"); 
       cout<<"the game has ended in a tie between the players"<<endl;
    }
    // else{
    //     throw logic_error("the game hasn't finished yet!");
    // }
};

void Game::printLog(){
    cout<<"printLog"<<endl;
};

void Game::printStats(){
    cout<<"printStats"<<endl;
};




#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include <iostream>
using namespace std;

//#include "namespace.hpp"
namespace ariel{

};



class Game{
    private:
        Player& p1;
        Player& p2;

        /* The cards in the game. */
        std:: vector<string> vector_suit= {"diamonds","spades","clubs","hearts"};
        vector<Card> vector_game;
        // for stats and log
        size_t num_wins_p1;
        size_t num_wins_p2;
        size_t num_draws;
        size_t num_turns;
        string lastTurnStats; // for lastTurnStats and log 
        string log;// for lastTurnStats and log

        // vector<Card>& vector_p1;
        // vector<Card>& vector_p2;

       
            /* The last turn stats. */
            // string lastTurnStats;

            /* The log of all the turns played. */
            //string log; 
   
    public: // in order to access it in Demo.cpp 
    //inline 
    Game(Player& plr1,Player& plr2);
    
    void initializeCards(); // in the constructor

    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    void playTurn();


};
#endif
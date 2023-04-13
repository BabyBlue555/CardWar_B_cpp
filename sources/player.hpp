#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <vector>
#include "card.hpp"
using namespace std;



namespace ariel{

};

class Player{
    // it is recommended that the fields of a class would be private
    private:
    string name;
   // int stackSize; // according to function stacksize()
    size_t takenCards;
   // int cardsTaken;// according to function cardesTaken()
      // since each player can only play one game at a time , there should be an indicator to tell us 
     // if the he/she is playing right now , in order to throw exceptions in response
    bool _isPlaying; // to indicate if the player is in a game or not 
    std::vector<Card> vector_player;// the player's deck
    size_t num_wins;


    // according to Demo.cpp, these are the functions that should be public:
    public:
    Player(string); // OUTLINE
    std::string getName(); // "outline" method
    size_t stacksize() const ;
  //  size_t getNumWins() const; // for stats
    //const size_t& cardesTaken() const; // "outline" method - get
    size_t cardesTaken() const;
    void addCardsTaken(size_t size_before, bool draw); // set
    //void setStackSize(int draw); // set
    bool isPlaying(); // check the status of the player 
    void setPlaying(bool playerStatus);
    const Card& getCurrCard() const;
    //const Card&
    void popCard(std::vector<Card>& player_deck) const; // delete the card from the deck and return it
    std::vector<Card>& getDeck();
    void setDeck(std::vector<Card>& player_deck); // for the initialize of the game
    


};

#endif
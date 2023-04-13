#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"
#include "card.hpp"
using namespace std;
using namespace ariel;

// "outline" constructor implementation:

Player:: Player(string str):takenCards(0){
    this->name=str;
    this->_isPlaying=0; // initialize to not playing
  //  this->vector_player=&vector_player;
  //  this->vector_player;


}

// Player:: Player(string str,std::vector<Card>& vec):vector_player(vec){
// }


// "outline" method implementation:
//const Card& getCard() const
size_t Player::stacksize() const {
//const size_t& Player::stacksize() const{
    //return 1;
    return this->vector_player.size();
}
size_t Player::cardesTaken() const{
    return this->takenCards;
}

//  size_t Player::getNumWins() const{
//     return this->num_wins;
//  }

// getter
string Player::getName(){
    return this->name;
}

// returns state of player
bool Player::isPlaying(){
    //return 0; // default - not playing
    if(_isPlaying){
        return 1;
    }
    return 0;
}


// setters
void Player::setPlaying(bool playerStatus){
    this->_isPlaying=playerStatus;
}

// size_before is from type size_t because the size of a vector is from this type
void Player::addCardsTaken(size_t size_before, bool draw){
    if(this->stacksize()<=1 && draw){
         this->takenCards+=size_before;
    }
    else if(this->stacksize()>1 && draw){
        cout<<"no player should take cards while there is a draw and there are still cards in the deck";
        return;
    }
    else{ // no draw
        this->takenCards+=(2*(size_before-(this->vector_player.size())));
    }

    // if((this->stacksize()!= 0 && this->stacksize()!= 1)  && draw){
    //  throw logic_error("no player should take cards while there is a draw and there are still cards in the deck");
    // }
    // else if(!draw){
    //     this->takenCards+=(2*(size_before-(this->vector_player.size())));
    // }
    // else if(this->stacksize()<=1 && draw){ // if the cards are over and it's during a draw, split what's left between the two players (during draw)
    //     this->takenCards+=size_before;
    // }

}

// each regular turn, a player loses one card. in a draw, he loses at least 3 cards (the function is called a couple of times if needed)
// the third card is open, that's why after two cards there can be another draw
// void Player::setStackSize(int draw){
//     if (draw==0 && this->stackSize !=0){
//     this->stackSize-=1;
//     }
//     else if(this->stackSize !=0 && this->stackSize !=1 ){ // in a draw 
//         this->stackSize-=2;
//     }
//     else{
//          throw logic_error("no more cards in the deck!");
//     }
// }

//returns the current card the player has in the deck
const Card& Player::getCurrCard() const{
    return this->vector_player.back();
}

//const Card&
void Player::popCard(std::vector<Card>& player_deck) const{
  //  const Card currCard=player_deck.back();
    if(!player_deck.empty()){
       // player_deck.erase(player_deck.begin());
       player_deck.pop_back();
    }
    // printf("entering pop...........");
    // printf("stacksize after pop: %lu", this->stacksize());
    //return currCard;

}

std::vector<Card>& Player::getDeck(){
    return (this->vector_player);
}

void Player::setDeck(std::vector<Card>& player_deck){
    if(this->vector_player.empty()){
      (this->vector_player)=player_deck;
    }
}
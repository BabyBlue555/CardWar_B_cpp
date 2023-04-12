#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
using namespace std;
namespace ariel{

};



class Card{
 
// shape, number,color
private:
    int value;
    std::string suit; // 4 posible values i.e ,diamonds,spades,hearts or clubs

public:
    Card(int value, std::string suit);
    // write getters - you shouldn't have setters, cards value and suit can't be changed
    //getshape, getnumber, getcolor
    int getValue(); //outline
    std::string getSuit();//outline

// operators in order to compare between two cards
// needed for example in playTurn() , to determine if its a draw or one of the player's won the turn
bool operator == (const Card& rhs) const { return value == rhs.value and suit == rhs.suit;} 

// bool operator <  
// ace beats everthing but 2 
bool operator<(const Card& rhs) const { return value < rhs.value or (value == rhs.value and suit < rhs.suit) or ((value != 1 and value !=2) and rhs.value == 1); }

bool operator>(const Card& rhs) const { return value > rhs.value or (value == rhs.value and suit > rhs.suit) or (value == 1 and (rhs.value != 1 and rhs.value !=2)); }
// bool operator >

};

#endif
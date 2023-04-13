#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
using namespace std;
namespace ariel{

};



class Card{
 
// shape, number,color
private:
    size_t value;
    std::string suit; // 4 posible values i.e ,diamonds,spades,hearts or clubs

public:
    Card(size_t value, std::string suit);
    // write getters - you shouldn't have setters, cards value and suit can't be changed
    //getshape, getnumber, getcolor
    size_t getValue(); //outline
    std::string getSuit();//outline

//operators in order to compare between two cards
//needed for example in playTurn() , to determine if its a draw or one of the player's won the turn
bool operator==(const Card& other) const 
// operations:
 {
    return value==other.value;

}
//{ return value == rhs.value ;} 

// // bool operator <  
// // ace beats everthing but 2 
// // bool operator >
bool operator<(const Card &other) const
{
    return (value<other.value) or ((value!=1 and value!=2) and other.value==1);
}


 bool operator>(const Card &other) const {
    return (value>other.value) or (value==1 and (other.value!=1 and other.value!=2));
 }

string toString();

};

#endif
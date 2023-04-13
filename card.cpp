#include <iostream>
#include <fstream>
#include <sstream>
//#include <stdexcept>
#include "card.hpp"
//#include "player.hpp"
using namespace std;
using namespace ariel;

Card::Card(size_t value, std::string suit) {
    this->value = value;
    this->suit = suit;
}

size_t Card::getValue(){
    return this->value;
}

std::string Card::getSuit(){
    return this->suit;
}




// in order to display the card in stats of player
string Card::toString(){
    return to_string(this->value)+" of "+(this->suit)+"\n";
}
#include <iostream>
#include <fstream>
#include <sstream>
//#include <stdexcept>
#include "card.hpp"
//#include "player.hpp"
using namespace std;
using namespace ariel;

Card::Card(int value, std::string suit) {
    this->value = value;
    this->suit = suit;
}

int Card::getValue(){
    return this->value;
}

std::string Card::getSuit(){
    return this->suit;
}


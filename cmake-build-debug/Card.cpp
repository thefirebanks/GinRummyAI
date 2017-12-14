//
// Created by Daniel Firebanks  on 11/29/17.
//

#include <iostream>
#include "Card.h"

Card::Card(int val, string st, int sc){
    value = val;
    suit = st;
    score = sc;
}

int Card::get_value() {
    return value;
}

string Card::get_suit() {
    return suit;
}

int Card::get_score() {
    return score;
}


void Card::print_card() {
    cout<<value<<" of "<<suit<<endl;
}
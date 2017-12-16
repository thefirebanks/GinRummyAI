//
// Created by Daniel Firebanks  on 11/29/17.
//
#include <stdlib.h>
#include <string>

#ifndef GINRUMMY_CARD_H
#define GINRUMMY_CARD_H

using namespace std;

class Card {
    int value;
    int score;
    string suit;

public:
    Card(int val, string st, int score );
    int get_value();
    string get_suit();
    int get_score();
    void print_card();
};


#endif //GINRUMMY_CARD_H

//
// Created by Daniel Firebanks  on 11/29/17.
//
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "card.h"

#ifndef GINRUMMY_MELD_H
#define GINRUMMY_MELD_H

class Meld {


public:
    vector<Card> meld;
    int score;
    //Constructor for sets and runs
    Meld(Card c1, Card c2, Card c3);

    //Constructor for add-ons
    Meld(Card c1);

    int calculate_score(vector<Card> meld);
    void add_card(Card card);
    int get_score();
    vector<Card> get_meld();
    void print_meld();
};


#endif //GINRUMMY_MELD_H

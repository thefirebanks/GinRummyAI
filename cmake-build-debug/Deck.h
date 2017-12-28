//
// Created by Daniel Firebanks  on 11/29/17.
//
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

#ifndef GINRUMMY_DECK_H
#define GINRUMMY_DECK_H

using namespace std;

class Deck {

public:

    /* Variables */
    int total_cards = 52;
    int curr_size = total_cards;

    string suits[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
    vector<Card*> deck;

    vector<Card*> discard_pile;

    /* Methods */
    Deck();
    void shuffle();
    int get_size();
    vector<Card*> get_deck();
    Card* draw();
    Card* draw_discard();
    void discard(Card *card);
    void print_deck();

};


#endif //GINRUMMY_DECK_H

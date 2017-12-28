//
// Created by Daniel Firebanks  on 11/29/17.
//

#include <vector>
#include <iostream>
#include <set>
#include "Deck.h"
#include "Card.h"
#include "Meld.h"

#ifndef GINRUMMY_PLAYER_H
#define GINRUMMY_PLAYER_H

using namespace std;

//TODO MAKE SURE A MELD IS APPROPRIATE

class Player {
public:
    //1 Draw from deck
    //2 Draw from discard
    //3 Evaluate hand (AI)
    //4 New Meld
    //5 Addon Meld

    /* Variables */
    vector<Card*> hand;
    vector<Meld*> meld_list;
    bool is_dealer;
    string name;
    int score;

    //TODO Check in table if the cards are being deleted from here
    vector<Card*> possible_melds;
    vector<Card*> useless_cards;
    set<Meld*, Meld::meld_compare> possible_new_melds;

    string draw_from;
    vector<int> discard_index;
    vector<int> no_discard_index;

    /*Functions*/

    Player(string name);
    void deal(Player* p2, Deck* d);
    void draw(string place, Deck* deck);
    void discard(Card *card, Deck* deck);
    void remove_card(Card *card);
    Meld* new_meld(Card *c1, Card *c2, Card *c3);
    Meld* addon_meld(Card *c1);
    void put_card(Card *card, Meld *meld, int index);
    int get_score() const;
    void print_hand() const;

};


#endif //GINRUMMY_PLAYER_H

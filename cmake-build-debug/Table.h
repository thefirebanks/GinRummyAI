//
// Created by Daniel Firebanks  on 11/29/17.
//
#include <vector>
#include <iostream>
#include <set>
#include <stdlib.h>
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Meld.h"


#ifndef GINRUMMY_TABLE_H
#define GINRUMMY_TABLE_H


class Table {
public:
    //Tested!!!!!
    Deck* current_deck;
    set<Player*> players;
    set<Meld> melds;
    Table(Player* p1, Player* p2, Deck* deck);
    void updateMeld();
    void play_meld(Player* p);

    void evaluate_draw(Player* p) const;
    void evaluate_hand(Player* p) const;
    bool evaluate_melds(Player* p) const;
    void evaluate_discard(Player* p) const;



    static bool compare_value(Card c1, Card c2);
    static bool compare_suit(Card c1, Card c2);
};



#endif //GINRUMMY_TABLE_H

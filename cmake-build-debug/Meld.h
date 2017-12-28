//
// Created by Daniel Firebanks  on 11/29/17.
//
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Card.h"

#ifndef GINRUMMY_MELD_H
#define GINRUMMY_MELD_H


//TODO Make a method for checking if the human player tries to make an invalid meld.. here?

class Meld {

public:
    vector<Card*> meld;
    int score;

    //Constructor for sets and runs
    Meld(Card *c1, Card *c2, Card *c3);

    //Constructor for add-ons
    Meld(Card *c1);

    struct meld_compare{
        bool operator() (const Meld* m1, const Meld* m2) const{

            int count = 0;

            for (int i = 0; i < m1->meld.size(); i++){
                for (int j = 0; j < m2->meld.size(); j++){
                    if ((m1->meld.at(i)->get_suit() == m2->meld.at(j)->get_suit())
                        && (m1->meld.at(i)->get_value() == m2->meld.at(j)->get_value())){
                        count += 1;
                    }
                }
                if (count == 0)
                    return true;
            }
            return count != 3;
        }
    };

    int calculate_score();
    void add_card(Card *card);
    vector<Card*> get_meld();
    void print_meld();


};


#endif //GINRUMMY_MELD_H

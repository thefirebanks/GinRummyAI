//
// Created by Daniel Firebanks  on 11/29/17.
//

#include "Meld.h"

/* Construtor for Sets and Runs */
Meld::Meld(Card *c1, Card *c2, Card *c3){
    meld.push_back(c1);
    meld.push_back(c2);
    meld.push_back(c3);

    score = calculate_score();
}

/* Construtor for Add ons */
Meld::Meld(Card *c1){
    meld.push_back(c1);

    score = calculate_score();
}

/* Calculates the total score of the current meld */
int Meld::calculate_score(){
    int card_score = 0, sum = 0;

    for (int i = 0; i < meld.size(); i++){
        card_score = meld.at(i)->get_score();
        //cout<<"Card score is "<<card_score<<endl;
        sum += card_score;
    }

    return sum;
};

/* Add a card to the current meld */
void Meld::add_card(Card *card){
    meld.push_back(card);
    score += card->get_score();
}

// Overwrite != operator for find function
bool operator== (const Meld &m1, const Meld &m2){

    int count = 0;

    for (int i = 0; i < m1.meld.size(); i++){
        for (int j = 0; j < m2.meld.size(); j++){
            if ((m1.meld.at(i)->get_suit() == m2.meld.at(j)->get_suit())
            && (m1.meld.at(i)->get_value() == m2.meld.at(j)->get_value())){
                count += 1;
            }
        }
        if (count == 0)
            return false;
    }
    return count == 3;
}

bool operator< (const Meld &m1, const Meld &m2){
    return m1.meld < m2.meld;
}

//TODO eventually remove these functions because the variables they return are public!!!

vector<Card*> Meld::get_meld(){
    return meld;
}

void Meld::print_meld(){
    cout<<"Meld contains:"<<endl;
    for (Card *c : meld){
        c->print_card();
    }
}
//
// Created by Daniel Firebanks  on 11/29/17.
//

#include "meld.h"

//Sets and Runs
Meld::Meld(Card c1, Card c2, Card c3){
    meld.push_back(c1);
    meld.push_back(c2);
    meld.push_back(c3);

    score = calculate_score(meld);
}

//Add ons
Meld::Meld(Card c1){
    meld.push_back(c1);
    score = calculate_score(meld);
}

int Meld::calculate_score(vector<Card> meld){
    int card_score = 0, sum = 0;

    for (int i = 0; i < (int) meld.size(); i++){
        card_score = meld.at(i).get_score();
        //cout<<"Card score is "<<card_score<<endl;
        sum += card_score;
    }

    return sum;
};

// Overwrite != operator for find function
bool operator== (const Meld &m1, const Meld &m2){
    return m1.meld == m2.meld;
}
bool operator< (const Meld &m1, const Meld &m2){
    return m1.meld < m2.meld;
}


void Meld::add_card(Card card){
    meld.push_back(card);
    score = calculate_score(meld);
}

int Meld::get_score() {
    score = calculate_score(meld);
    return score;
}

vector<Card> Meld::get_meld(){
    return meld;
}

void Meld::print_meld(){
    cout<<"Meld contains:"<<endl;
    for (Card c : meld){
        c.print_card();
    }
}

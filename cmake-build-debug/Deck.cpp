//
// Created by Daniel Firebanks  on 11/29/17.
//
#include "Deck.h"

/*Constructor for deck, adds 52 cards and shuffles the deck*/
Deck::Deck(){

    //To reference suits
    int index_s = 0;
    //To reference values
    int card_num = 1;

    int score = 0;

    for (int i = 1; i <= total_cards; i++){

        //Create a new card
        Card card(card_num, suits[index_s], score);

        //Add the card to the deck
        deck.push_back(card);

        //Increase value and score
        card_num += 1;
        score += 1;

        //Create only 13 cards per suit
        if (i % 13 == 0) {
            //Card card(card_num, suits[index_s], score);
            //deck.push_back(card);
            index_s += 1;
            card_num = 1;
            score = 1;
        }
    }

    //shuffle();
};

/*Shuffles the deck*/
void Deck::shuffle() {
    random_shuffle(deck.begin(), deck.end());
}

/*Gets size of the deck, or index of reference*/
int Deck::get_size() {
    return curr_size;
}

vector<Card> Deck::get_deck(){
    return deck;
}

/*Gets the top card of the deck*/
Card Deck::draw() {
    Card card = deck.back();
    curr_size -= 1;
    deck.pop_back();
    return card;
}

Card Deck::draw_discard() {
    Card card = discard_pile.back();
    //curr_size -= 1;
    discard_pile.pop_back();
    return card;
}

void Deck::discard(Card card){
    discard_pile.push_back(card);
}

/*Prints deck to standard output*/
void Deck::print_deck() {
    for (int i = 0; i < curr_size; i++){
        Card card = deck.at(i);
        cout << "Card at position " << i << " has value " << card.get_value() << " and suit " << card.get_suit() << endl;
    }
}

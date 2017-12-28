//
// Created by Daniel Firebanks  on 11/29/17.
//

#include "Player.h"

Player::Player(string n) {
    name = n;
}

/*Given the number of players, returns a vector representing a hand of cards*/
void Player::deal(Player* p2, Deck* deck) {

    //Determine the amount of cards to be dealt per player
    int card_num = 10;

    //Deal first card_num cards per player and delete them from the deck
    for (int i = 0; i < card_num; i++)
    {
        //Get one card for every player
        Card *card1 = deck->draw();
        hand.push_back(card1);

        Card *card2 = deck->draw();
        p2->hand.push_back(card2);
    }
}

/* Makes the player draw from either the discard pile or the deck */
void Player::draw(string place, Deck* deck) {

    Card *card;

    if (place == "Deck")
    {
        card = deck->draw();
        hand.push_back(card);
    }
    else
    {
        card = deck->draw_discard();
        hand.push_back(card);
    }
}

/* Removes the card from hand */
void Player::remove_card(Card *card) {

    //Gets card from hand by getting its index
    int i = 0;
    Card *c = hand.at(i);

    //Finds the index of the card
    while ((c->get_value() != card->get_value()) || (c->get_suit() != card->get_suit()))
    {
        if (i == hand.size()){
            break;
        }
        i++;
        c = hand.at(i);
    }

    //Removes card from hand
    hand.erase(hand.begin() + i);

}

/* Puts card on top of discard pile */
//TODO If this function doesn't work, make remove_card return a card
void Player::discard(Card *card, Deck* deck){

    //Removes card from hand
    remove_card(card);

    //Puts into discard pile
    deck->discard(card);

}

/* Create a new meld given 3 cards */
Meld* Player::new_meld(Card *c1, Card *c2, Card *c3) {

    Meld *meld = new Meld(c1, c2, c3);
    meld_list.push_back(meld);
    score += meld->score;

    remove_card(c1);
    remove_card(c2);
    remove_card(c3);

    return meld;
}

/* Create a new addon meld given 1 card and an already existing meld */
Meld* Player::addon_meld(Card *c1){

    Meld *meld = new Meld(c1);
    meld_list.push_back(meld);
    score += meld->score;

    remove_card(c1);

    return meld;
}

/* Adds a new card to a current meld */
void Player::put_card(Card *card, Meld *meld, int index) {

    meld->add_card(card);

    meld_list[index] = meld;

    //meld.print_meld();
    //meld_list[index].print_meld();

    score += card->get_score();

    remove_card(card);
}

int Player::get_score() const {
    return score;
}

void Player::print_hand() const{
    //cout<<"Hand size is "<<hand.size()<<endl;
    cout<<name<<"'s hand is:"<<endl;
    for (int i = 0; i < hand.size(); i++){
        Card *c = hand.at(i);
        c->print_card();
    }
}



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
    for (int i = 0; i < card_num; i++){
        //Get one card for every player

        Card card1 = deck->draw();
        hand.push_back(card1);

        Card card2 = deck->draw();

        p2->hand.push_back(card2);
    }
}

void Player::draw(string place, Deck* deck) {

    if (place == "Deck"){
        Card card = deck->draw();
        hand.push_back(card);
    }
    else{
        Card card = deck->draw_discard();
        hand.push_back(card);
    }
}

void Player::remove_card(Card card) {

    //Gets hard from hand by getting its index
    int i = 0;
    Card car = hand.at(i);
    while ((car.get_value() != card.get_value()) || (car.get_suit() != card.get_suit())){
        if (i == hand.size()){
            break;
        }
        i++;
        car = hand.at(i);
    }

    //Removes card from hand
    hand.erase(hand.begin() + i);
}

void Player::discard(Card card, Deck* deck){

    //Removes card from hand
    remove_card(card);

    //Puts into discard pile
    deck->discard(card);

}


Meld Player::new_meld(Card c1, Card c2, Card c3) {
    Meld meld(c1, c2, c3);
    meld_list.push_back(meld);
    score += meld.get_score();

    remove_card(c1);
    remove_card(c2);
    remove_card(c3);

    return meld;
}

Meld Player::addon_meld(Card c1){
    Meld meld(c1);
    meld_list.push_back(meld);
    score += meld.get_score();
    remove_card(c1);
    return meld;
}


void Player::put_card(Card card, Meld meld, int index) {
    meld.add_card(card);

    meld_list[index] = meld;

    //meld.print_meld();
    //meld_list[index].print_meld();

    score += card.get_score();

    remove_card(card);
}

int Player::get_score() {
    return score;
}

void Player::print_hand() {
    //cout<<"Hand size is "<<hand.size()<<endl;
    cout<<name<<"'s hand is:"<<endl;
    for (int i = 0; i < hand.size(); i++){
        Card card = hand.at(i);
        card.print_card();
    }
}



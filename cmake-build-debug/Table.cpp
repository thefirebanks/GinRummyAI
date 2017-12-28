//
// Created by Daniel Firebanks  on 11/29/17.
//

#include "Table.h"

/* Initialize a new table with 2 player and a new deck */
Table::Table(Player *p1, Player *p2, Deck *deck) {
    players.insert(p1);
    players.insert(p2);
    current_deck = deck;
}


/* Given the current state, get the melds of all the players
 * and add them to the set of melds of the table */
void Table::updateMeld() {

    //Clear current set of melds
    //melds.clear();

    //Iterate through the players

    Player *p = *next(players.begin(), 0);

    for (Meld *meld : p->meld_list){
        melds.insert(meld);
    }

    Player *p1 = *next(players.begin(), 1);

    for (Meld *meld : p1->meld_list){
        melds.insert(meld);
    }

}

/* Updates the player's draw_from variable,
 * taking in account the top card of the discard pile,
 * and evaluates the hand for possible_melds and possible_new_melds */
void Table::evaluate_draw(Player* p) const{

    p->draw_from = "Deck";

    //Check for possible_melds and possible_new_melds within the hand------------
    if (p->possible_melds.empty()){
        //cout << "Possible melds is empty in evaluate_draw" << endl;
        evaluate_hand(p);
    }

    //Check for possible melds in the discard pile ------------------------------
    if (!(p->possible_melds.empty() || current_deck->discard_pile.empty())){

        //Reference the top card of the discard_pile
        vector<Card*> discard = current_deck->discard_pile;
        Card *eval_card = discard.back();

        //Update player's draw_from
        if (evaluate_melds(p, eval_card))
            p->draw_from = "Discard";
    }

}


/* Checks and updates possible_melds for player's current hand when possible_melds is empty
 * Calls evaluate_melds and updates possible_new_melds if possible_melds is not empty */
void Table::evaluate_hand(Player* p) const {
    //p->possible_new_melds[0]->print_meld();

    //cout << "Size of hand before checking by value is " << p->hand.size() << endl;
    //Check for melds in the format 6D, 6S, 6H
    sort(p->hand.begin(), p->hand.end(), compare_value);

    //For every two cards in the hand, check if they are of the same value
    for (int i = 0; i < p->hand.size() - 1; i++){
        Card *c1 = p->hand.at(i);
        Card *c2 = p->hand.at(i+1);
        if (c1->get_value() == c2->get_value()){
            p->possible_melds.push_back(c1);
            p->possible_melds.push_back(c2);
        }
    }

    //cout << "-- Checked for melds by value --" << endl;

    //cout << "Size of hand before checking by suit is " << p->hand.size() << endl;

    //Check for melds in the format 6S,7S,8S
    sort(p->hand.begin(), p->hand.end(), compare_suit);


    //For every two cards in the hand, if they are the same suit, check if their values coincide with the format 6S,7S,8S
    for (int i = 0; i < p->hand.size() - 1; i++){
        Card *c1 = p->hand.at(i);
        Card *c2 = p->hand.at(i+1);

        if (c1->get_suit() == c2->get_suit()){
            if ((c1->get_value() + 1 == c2->get_value()) || (c1->get_value() + 2 == c2->get_value())){
                p->possible_melds.push_back(c1);
                p->possible_melds.push_back(c2);
            }
        }
    }

    //cout << "-- Checked for melds by suit --" << endl;

    //cout << "Size of hand before checking possible new melds is " << p->hand.size() << endl;

    //Evaluate if there are any possible new melds within the current hand and update variable
    if (!p->possible_melds.empty()){

        //cout << "There are possible melds, checking if they can be completed in the hand now" << endl;
        for (int i = 0; i < p->hand.size(); i++){
            bool not_relevant = evaluate_melds(p, p->hand.at(i));
        }

        //cout << "-- Checked possible new melds within the hand --" << endl;
    }
}

/* Updates possible_new_melds given player's current hand and possible_melds
 * returns true if it is better to draw from discard pile */
bool Table::evaluate_melds(Player* p, Card* eval_card) const{

    bool added = false;

    vector<Card*> copy = p->possible_melds;

    for (int i = 0; i <= copy.size() - 2; i += 2){
        //cout<<"GOT HERE BRO"<<endl;

        Card *first = copy.at(i);
        Card *second = copy.at(i+1);

        //---------------Melds by suit---------------------------------------
        // Case where we have 6D, 7D, and we are missing a 8D
        bool case1 = (eval_card->get_suit() == first->get_suit()
                      && (eval_card->get_value() + 1 == first->get_value())
                      && (eval_card->get_value() == second->get_value() - 2));

        // Case where we have 6D, 7D, and we are missing a 5D
        bool case2 = (eval_card->get_suit() == second->get_suit()
                      && (eval_card->get_value() - 1 == second->get_value())
                      && (eval_card->get_value() == first->get_value() + 2));

        // Case where we have 5D, 7D, and we are missing a 6D
        bool case3 = (eval_card->get_suit() == first->get_suit()
                      && (eval_card->get_value() == first->get_value() + 1)
                      && (eval_card->get_value() == second->get_value() - 1));

        //---------------Meld by value---------------------------------------
        // Case where we have 6D, 6H, and we see 6S or 6C
        bool case4 = ((first->get_value() == second->get_value())
                     && (eval_card->get_value() == second->get_value())
                      && ((eval_card->get_suit() != first->get_suit())
                          && eval_card->get_suit() != second->get_suit()));

        //cout << "-- Checked for all the cases if there is a possible meld --" << endl;

        // If any of the cases is true
        if (case1 || case2 || case3 || case4) {

            //Create the meld
            Meld *new_meld = new Meld(first, second, eval_card);

            //cout << "-- Created a new meld --" << endl;
            //Delete it from possible melds
            copy.erase(copy.begin() + i);
            copy.erase(copy.begin() + i);

            //cout << "-- Deleted the cards from the possible_melds --" << endl;

            //Add it to possible NEW melds
            p->possible_new_melds.insert(new_meld);

            //cout << "-- Added meld to possible_new_meld --" << endl;

            added = true;
        }
    }

    //cout << "Finished loop of evaluate melds" << endl;
    return added;
}
/*
void Table::evaluate_discard(Player* p) const{
    //clear useless cards
    p->useless_cards.clear();

    //fill useless_cards in order
    sort(p->hand.begin(), p->hand.end(), compare_value);

    //cout<<"Size of hand is "<<p->hand.size()<<endl;

    for (int j = 0; j < p->hand.size(); j++) {
        bool contains = false;
        Card c = p->hand[j];
        //Card hold = Card(c.get_value(), c.get_suit(), c.get_score());
        //cout<<p->possible_new_melds.size()<<endl;
        //p->possible_new_melds[0]->print_meld();

        //If there are not cards that could be made melds
        if (p->possible_new_melds.size() == 0)
        {
            for (int i = 0; i < p->hand.size(); i++) {
                p->discard_index.push_back(i);
            }
            //cout<<"TEST BRO"<<endl;
        }

        else
        {
            for (int i = 0; i < p->possible_new_melds.size(); i++) {
                //p->possible_new_melds[i]->print_meld();
                //cout << "Size of card is" << endl;

                //cout<<"Size of meld is "<<p->possible_new_melds.size()<<endl;

                //p->possible_new_melds[i]->print_meld();
                for (Card k : p->possible_new_melds[i]->get_meld()) {
                    //cout<<"Size of card is"<<endl;

                    //TODO CHANGE TO STRCMP!!!!!!!
                    if (k.get_value() == c.get_value() && k.get_suit() == c.get_suit()) { //if possible melds contains c
                        //cout<<"GOT HERE BRO"<<endl;
                        contains = true;
                        p->no_discard_index.push_back(j);
                    }
                }
            }
            if (!contains) {

                //hold->print_card();

                //cout<<"Size of vector is "<<p->useless_cards.size()<<endl;
                p->useless_cards.push_back(c);

                p->useless_cards.pop_back();
                //Add index to reference later and discard
                p->discard_index.push_back(j);
            }
        }
    }
}
*/
void Table::print_players() {
    Player *p1 = *std::next(players.begin(), 0);
    cout<<"Player 1 is "<<p1->name<<endl;

    Player *p2 = *std::next(players.begin(), 1);
    cout<<"Player 2 is "<<p2->name<<endl;
}

bool Table::compare_suit(Card *c1, Card *c2) {
    if (c1->get_suit() == c2->get_suit())
        return c1->get_value() < c2->get_value();
    else
        return c1->get_suit() < c2->get_suit();
}

bool Table::compare_value(Card *c1, Card *c2) {
    return c1->get_value() < c2->get_value();
}

/*
void Table::play_meld(Player *p) {
    if (p->possible_new_melds.size() != 0){ // If melds to play is not size zero
        for (Meld* m : p->possible_new_melds){ //play melds to table
            melds.insert(*m);
            p->meld_list.push_back(*m);

            for (int j = 0; j < m->meld.size(); j++) { // erase from hand
                for (int i = 0; i < p->hand.size(); i++){
                    if (p->hand[i].get_value() == m->meld[j].get_value() && p->hand[i].get_suit() == m->meld[j].get_suit()) {
                        p->hand.erase(p->hand.begin()+i);
                        i--;
                    }
                }
            }
            p->possible_new_melds.erase(p->possible_new_melds.begin());
        }
    }
}

*/
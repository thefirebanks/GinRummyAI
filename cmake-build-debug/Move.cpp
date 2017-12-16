//
// Created by Jacob Arons on 12/11/17.
//

#include "Move.h"

Move::Move(string draw_from, vector<Meld*> melds, int discard_card) {

    //Check where to draw from (1 for Deck, 2 for Discard)
    if (draw_from == "Deck"){
        move_sequence.push_back(1);
    }

    else if (draw_from == "Discard"){
        move_sequence.push_back(2);
    }


    //Check if new melds are available (i for i number of melds from 0 <= i <= 3)
    if (melds.size() == 0) {
        move_sequence.push_back(0);
    } else if (melds.size() == 1) {
        move_sequence.push_back(1);
    } else if (melds.size() == 2) {
        move_sequence.push_back(2);
    } else if (melds.size() == 3) {
        move_sequence.push_back(3);
    }

    //Check which card to discard from (Index of card in useless_cards vector)

    move_sequence.push_back(discard_card);

}

bool operator!= (Move &m1, Move &m2){
    int count = 0;

    for (int i = 0; i < 3; i++){
        if (m1.move_sequence[i] == m2.move_sequence[i])
            count += 1;
    }

    return count != 3;
}


bool operator< (const Move &m1, const Move &m2){
        int count = 0;

    for (int i = 0; i < 3; i++){
        if (m1.move_sequence[i] == m2.move_sequence[i])
            count += 1;
    }

    return count < 3;
}

void Move::print_move() {
    cout<<"Move sequence is [";

    cout<<move_sequence[0];
    for (int i = 1; i < move_sequence.size(); i++){
        cout<<", "<<move_sequence[i];
    }
    cout<<"]"<<endl;
}

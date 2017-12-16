//
// Created by Jacob Arons on 12/11/17.
//

#include "Table.h"
#include "Player.h"
#include "Meld.h"
#ifndef GINRUMMY_MOVE_H
#define GINRUMMY_MOVE_H


class Move {
public:
    vector<int> move_sequence;

    Move(){

    }
    Move(string draw_from, vector<Meld*> melds, int discard_card);

    void print_move();
};


#endif //GINRUMMY_MOVE_H

//
// Created by Daniel Firebanks  on 12/10/17.
//

#include <algorithm>
#include <iostream>
#include "Table.h"
#include "Move.h"
#include "mcts.h"

//CHECK WHATS WRONG WITH THE MELD SCORE?!?!!?!? Maybe when creating the card


class GinState
{
public:

    typedef Move Move;

    static Card c1;
    static Card c2;
    static Card c3;

    static Meld bro;

    static Meld* pointbro;

    static vector<Meld*> brolist;

    static const Move no_move;

    static const int game_score = 500;

    static const int player_markers[3];

    Deck *deck;

    Player *p1;
    Player *p2;

    Table *table;

    GinState()
        : player_to_move(1)
    {
        deck = new Deck();
        p1 = new Player("Scout");
        p2 = new Player("Cowboy");

        deck->shuffle();

        //Player 1 starts as the dealer, gives cards to p1 and p2
        p1->deal(p2, deck);

        table = new Table(p1, p2, deck);

        table->print_players();
    }

    void do_move(Move move)
    {

        //Modify this at some point
        //attest(0 <= move && move < num_cols);
        //attest(board[0][move] == player_markers[0]);
        check_invariant();

        Player *p;

        if (player_markers[player_to_move] == 1){
            p = p1;
        }
        else if (player_markers[player_to_move] == 2){
            p = p2;
        }

        //Drawing
        if (move.move_sequence[0] == 1)
            p->draw("Deck", deck);
        else if (move.move_sequence[1] == 2)
            p->draw("Discard", deck);

        //Melding
        if (!(move.move_sequence[1] == 0)){
            for (int i = 0; i < p->possible_new_melds.size(); i++){
                Card c1 = p->possible_new_melds[i]->meld[0];
                Card c2 = p->possible_new_melds[i]->meld[1];
                Card c3 = p->possible_new_melds[i]->meld[2];

                /*
                cout<<"Cards in possible new melds are: "<<endl;
                c1.print_card();
                c2.print_card();
                c3.print_card();
                */

                p->new_meld(c1, c2, c3);
            }
        }

        //Discard
        p->discard(p->hand[move.move_sequence[2]], deck);

        //Update melds on table
        table->updateMeld();

        /* ---------------------------------------------- */

        //Switch players/turns
        player_to_move = 3 - player_to_move;

    }


    template<typename RandomEngine>
    void do_random_move(RandomEngine* engine)
    {
        dattest(has_moves());
        check_invariant();
        std::uniform_int_distribution<int> moves(0, 3);

        vector<Move> r_moves = get_moves();

        while (true) {
            auto move = moves(*engine);
            if (has_moves()) {
                Move bro = r_moves[move];
                do_move(bro);
                return;
            }
        }
    }

    bool has_moves() const // is the round over?
    {
        check_invariant();

        for (Player *p : table->players){
            if (p->hand.size() == 0 || p->get_score() == game_score){
                return false;
            }
        }
        return true;
    }

    /* Returns a vector of all possible move sequences given current state */
    vector<Move> get_moves() const {
        //table->print_players();

        //Makes the deck to be a discard pile
        if (table->current_deck->get_deck().size() == 0){
            vector<Card> d = table->current_deck->deck;
            d = table->current_deck->discard_pile;
            table->current_deck->discard_pile.clear();
        }

        Player *p;
        if (player_markers[player_to_move] == 1){
            p = p1;
        }
        else if (player_markers[player_to_move] == 2){
            p = p2;
        }

        //table->print_players();

        vector<Move> moves;

        //Evaluate the place to draw
        table->evaluate_draw(p);

        //Evaluate which cards are useful or not
        table->evaluate_melds(p);

        //Evaluate which card to discard
        table->evaluate_discard(p);

        //If we can discard from useless cards
        if (p->useless_cards.size() != 0) {
            //cout<<"BRO1!!!!!"<<endl;
            if (p->discard_index.size() != 0){
                for (int i_disc : p->discard_index) {
                    Move move = Move(p->draw_from, p->possible_new_melds, i_disc);
                    //move.print_move();
                    moves.push_back(move);
                    //cout<<"BRO2!!!!!"<<endl;
                    //indices_useless_cards.pop_back();
                }
            }
            else{
                //cout<<"BRO1.1!!!!!"<<endl;
                Move move = Move(p->draw_from, p->possible_new_melds, 0);
                moves.push_back(move);
            }
        }
        else{
            cout<<"BRO3!!!!!"<<endl;
            //Careful when we remove a card that could be a meld but did not get to.
            for (int i_ndisc: p->no_discard_index) {

                Move move = Move(p->draw_from, p->possible_new_melds, i_ndisc);

                //move.print_move();
                moves.push_back(move);
                cout<<"BRO4!!!!!"<<endl;
            }
        }

        /*
        for (Move m : moves){
            m.print_move();
        }*/

        //cout<<"Number of moves is "<<moves.size()<<endl;

        return moves;
    }

    int get_winner() const
    {
        int p1_score = p1->score;
        int p2_score = p2->score;

        if (p1->hand.size() != 0){
            for (Card c : p1->hand){
                p1_score += c.get_score();
            }
        }

        if (p2->hand.size() != 0){
            for (Card c : p2->hand){
                p2_score += c.get_score();
            }
        }

        if (p1_score < p2_score){
            return 2;
        }

        else if (p1_score > p2_score){
            return 1;
        }

        return player_markers[0];
    }

    double get_result(int current_player_to_move) const
    {
        dattest(!has_moves());
        check_invariant();

        auto winner = get_winner();

        if (winner == player_markers[0]) {
            return 0.5;
        }

        if (winner == player_markers[current_player_to_move]) {
            return 0.0;
        }
        else {
            return 1.0;
        }
    }

    void print(ostream& out) const
    {
        const Player *p;
        if (player_markers[player_to_move] == 1){
            p = p1;
        }
        else if (player_markers[player_to_move] == 2){
            p = p2;
        }

        out<<"Player is "<<p->name<<endl;
        p->print_hand();

        out<< "Melds in table are:"<<endl;

        for (Meld m : table->melds){
            m.print_meld();
        }

        out<< "Cards in discard pile are:"<<endl;

        for (Card c : table->current_deck->discard_pile){
            c.print_card();
        }

        out<<"Current score is "<<p->get_score()<<endl;

        out << player_markers[player_to_move] << " to move " << endl << endl;
    }

    int player_to_move;
private:

    void check_invariant() const
    {
        attest(player_to_move == 1 || player_to_move == 2);
    }

};

ostream& operator << (ostream& out, const GinState& state)
{
    state.print(out);
    return out;
}

const int GinState::player_markers[3] = {0, 1, 2};

Card GinState::c1 = Card(20, "Bro", 20);
Card GinState::c2 = Card(21, "Bro1", 21);
Card GinState::c3 = Card(22, "Bro2", 22);

Meld GinState::bro = Meld(c1, c2, c3);

Meld* GinState::pointbro = &bro;

vector<Meld*> GinState::brolist = {pointbro};

const Move GinState::no_move = Move("FromBro", brolist, -1);
/*
GinState::GinState() {
    deck = new Deck();
    p1 = new Player("Cowboy");
    p2 = new Player("Scout");
    table = new Table(p1, p2, deck);
}*/

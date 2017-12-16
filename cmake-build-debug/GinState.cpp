//
// Created by Daniel Firebanks  on 12/10/17.
//



#include "GinState.h"
#include <iostream>
#include "mcts.h"

using namespace std;

void main_program()
{
    using namespace std;

    bool human_player = false;

    MCTS::ComputeOptions player1_options, player2_options;
    player1_options.max_iterations = 100000;
    player1_options.verbose = true;
    player2_options.max_iterations =  10000;
    player2_options.verbose = true;

    GinState state;

    while (state.has_moves()) {
        cout << endl << "State: " << state << endl;

        GinState::Move move = GinState::no_move;
        if (state.player_to_move == 1) {
            //draw move
            move = MCTS::compute_move(state, player1_options);
            state.do_move(move);

            //play move
            //discard move
        }
            //6 Diamonds
        else {
            if (human_player) {
                cout<<"Human not found"<<endl;
                /*
                while (true) {
                    cout << "Input your move: ";
                    move = GinState::no_move;

                    string draw_f;
                    vector<Meld*> pnm;
                    int di;

                    int value;
                    string suit;
                    int score;

                    cin >> draw;

                    cin >> value >> suit;

                    Card c1 = Card(value1, suit1, value1);

                    try {
                        state.do_move(move);
                        break;
                    }
                    catch (std::exception& ) {
                        cout << "Invalid move." << endl;
                    }
                }*/
            }
            else {
                move = MCTS::compute_move(state, player2_options);
                state.do_move(move);
            }
        }
    }

    cout << endl << "Final state: " << state << endl;

    if (state.get_result(2) == 1.0) {
        cout << "Player 1 wins!" << endl;
    }
    else if (state.get_result(1) == 1.0) {
        cout << "Player 2 wins!" << endl;
    }
    else {
        cout << "Nobody wins!" << endl;
    }
}



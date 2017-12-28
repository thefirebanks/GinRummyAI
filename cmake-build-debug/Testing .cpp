//
// Created by Daniel Firebanks  on 12/13/17.
//

#include <iostream>
#include "Card.cpp"
#include "Deck.cpp"
#include "Meld.cpp"
#include "Player.cpp"
#include "Table.cpp"
//#include "Move.cpp"

/*
void test_Deck(){
    //Test ordered deck
    Deck deck = Deck();
    deck.print_deck();

    //Test drawing
    Card top = deck.draw();
    Card top2 = deck.draw();
    Card top3 = deck.draw();
    cout << "Card drawn is ";
    top.print_card();
    cout << "Card drawn is ";
    top2.print_card();
    cout << "Card drawn is ";
    top3.print_card();

    cout<<""<<endl;

    //Test that we are removing the cards after drawing them
    cout<<"Deck after drawing is:"<<endl;
    deck.print_deck();

    cout<<""<<endl;

    //Test shuffling
    deck.shuffle();
    deck.print_deck();
}

void test_Meld(){
    //Creating deck
    Deck deck = Deck();
    deck.print_deck();

    //Drawing
    Card top = deck.draw();
    Card top2 = deck.draw();
    Card top3 = deck.draw();
    cout << "Card drawn is ";
    top.print_card();
    cout << "Card drawn is ";
    top2.print_card();
    cout << "Card drawn is ";
    top3.print_card();

    //Test melding
    Meld meld = Meld(top, top2, top3);
    cout<<"Total score in meld is: "<<meld.get_score()<<endl;
    meld.print_meld();

    Card extra_card = deck.draw();
    meld.add_card(extra_card);
    cout<<"Total score in new meld is: "<<meld.get_score()<<endl;
    meld.print_meld();
}

void test_Discard(){
    //Creating deck
    Deck deck = Deck();
    deck.print_deck();

    //Drawing
    Card top = deck.draw();
    Card top2 = deck.draw();
    Card top3 = deck.draw();
    cout << "Card drawn is ";
    top.print_card();
    cout << "Card drawn is ";
    top2.print_card();
    cout << "Card drawn is ";
    top3.print_card();

    //Test discarding
    deck.discard(top);
    deck.discard(top2);
    deck.discard(top3);
    cout<<"Discard pile is:"<<endl;

    for (Card c : deck.discard_pile){
        c.print_card();
    }

    cout<<""<<endl;

    //Draw from discard
    Card discard = deck.draw_discard();
    cout<<"Card drawn from discard pile is:"<<endl;
    discard.print_card();
}
*/

/*
void test_Player(){

    //Creating and dealing ------------------------------------

    //Creating deck
    Deck deck = Deck();

    //Initialize players
    Player* p1 = new Player("Cowboy");
    Player* p2 = new Player("Scout");

    cout<<"Players are "<<p1->name<<" and "<<p2->name<<endl;

    p1->deal(p2, &deck);

    //Check if they were dealt
    p1->print_hand();
    p2->print_hand();

    //Check if a card has been drawn
    p1->draw("Deck", &deck);
    cout << "P1 drew a card!" << endl;
    p1->print_hand();

    //Discarding ------------------------------------

    //Check if discard works
    p1->discard(p1->hand.back(), &deck);
    cout << "P1 discarded a card!" << endl;
    p1->print_hand();

    //Check if the discarded card was added to the discarded pile
    p2->draw("Disc", &deck);
    cout << "P2 drew a card!" << endl;
    p2->print_hand();

    //Melding ------------------------------------ MUST CORRECT POINTERS TO MELD SO WE DONT INITIALIZE THEM CONSTANTLY

    //Print hand before putting melds
    cout<<"Hand of player 1 before meld is:"<<endl;
    p1->print_hand();

    //Check if player can make new melds
    Card *c1 = p1->hand.at(0);
    Card *c2 = p1->hand.at(1);
    Card *c3 = p1->hand.at(2);
    p1->new_meld(c1, c2, c3);

    cout<<"Melds of player 1 are:"<<endl;
    for (Meld* m1 : p1->meld_list){
        m1->print_meld();
    }

    //Print hand after putting melds
    cout<<"Hand of player 1 after meld is:"<<endl;
    p1->print_hand();

    //Print hand before putting melds
    cout<<"Hand of player 2 before meld is:"<<endl;
    p2->print_hand();

    //Check if player can make an addon meld
    p2->addon_meld(p2->hand.front());
    p2->addon_meld(p2->hand.front());
    p2->addon_meld(p2->hand.front());

    cout<<"Melds of player 2 are:"<<endl;
    for (Meld *m2 : p2->meld_list){
        m2->print_meld();
    }

    //Print hand after putting melds
    cout<<"Hand of player 2 after meld is:"<<endl;
    p2->print_hand();

    //Add a card to an existing meld
    p1->put_card(p1->hand.at(0), p1->meld_list.at(0), 0);
    cout << "Adding a card to a meld from P1" << endl;

    p2->put_card(p2->hand.at(0), p2->meld_list[1], 1);
    cout << "Adding a card to a meld from P2" << endl;

    cout<<"Melds of player 1 are:"<<endl;
    for (Meld *m1 : p1->meld_list){
        m1->print_meld();
    }

    cout<<"Melds of player 2 are:"<<endl;
    for (Meld *m2 : p2->meld_list){
        m2->print_meld();
    }

}
*/

void test_Table(){

    //Initialize shit
    Player Cowboy = Player("Cowboy");
    Player Scout = Player("Scout");
    Deck deck = Deck();

    deck.shuffle();
    deck.shuffle();

    Table table = Table(&Cowboy, &Scout, &deck);

    for (Player *p : table.players){
        cout<<p->name<<endl;
    }

    //Deal
    Cowboy.deal(&Scout, &deck);

    //Scout.hand.front().print_card();
    Scout.discard(Scout.hand.front(), &deck);

    cout<<"Discarded card is ";
    table.current_deck->discard_pile.at(0)->print_card();

    Cowboy.print_hand();

    table.evaluate_draw(&Cowboy);
    //Cowboy.print_hand();

    cout << "After evaluating draw, place is " << Cowboy.draw_from << endl;
    cout << "Possible melds are:" << endl;

    for (int i = 0; i < Cowboy.possible_melds.size(); i++){
        Cowboy.possible_melds.at(i)->print_card();
    }

    cout << "Possible NEW melds are:" << endl;

    for (Meld* m : Cowboy.possible_new_melds){
        m->print_meld();
    }

    Cowboy.draw(Cowboy.draw_from, &deck);

    Cowboy.print_hand();

    /*
    //table.evaluate_hand(&Cowboy); // add if doesn't contain
    cout<<"Possible NEW melds are:"<<endl;
    for (int i = 0; i < Cowboy.possible_new_melds.size(); i++){
        cout<<"Meld "<<i<<" is:"<<endl;
        Cowboy.possible_new_melds.back()->print_meld();
    }
    table.play_meld(&Cowboy);
    table.updateMeld();

    cout<<"Meld updated\n"<<endl;
    cout<<"TABLE MELDS:"<<endl;
    for (Meld m : table.melds){
        m.print_meld();
    }


    table.evaluate_discard(&Cowboy);
    Cowboy.print_hand();

    cout<<"PRINTING\n"<<endl;

    Cowboy.discard(Cowboy.useless_cards.at(Cowboy.useless_cards.size()-1), table.current_deck);

    for (int i = 0; i < Cowboy.useless_cards.size(); i++){
        Cowboy.useless_cards[i].print_card();

    }

    Cowboy.print_hand();

    cout<<"Printing Cowboy's melds: "<<endl;
    for (int i = 0; i < Cowboy.meld_list.size(); i++){
        Cowboy.meld_list[i].print_meld();
    }
    */
}



//void test_Move(){

    /* Form possible moves ---------------------------------------- */

    /*
    Deck deck = Deck();

    Player p1 = Player("Cowboy");
    Player p2 = Player("Scout");

    deck.shuffle();

    //Player 1 starts as the dealer, gives cards to p1 and p2
    p1.deal(&p2, &deck);

    p2.discard(*p2.hand.begin(), &deck);

    Table table = Table(&p1, &p2, &deck);

    vector<Move> moves;

    //Evaluate the place to draw
    table.evaluate_draw(&p1);

    //Evaluate which cards are useful or not
    table.evaluate_melds(&p1);

    //Evaluate which card to discard
    table.evaluate_discard(&p1);

    for (int num : p1.discard_index){
        Move move = Move(p1.draw_from, p1.possible_new_melds, num);
        //move.print_move();
        moves.push_back(move);
        //temp_useless_cards.pop_back();

    }

    for (Move m : moves){
        //cout<<m.move_sequence.size()<<endl;
        m.print_move();
    }

    /* Do move ------------------------------------------ */
    /*
    Player *p;

    if (player_markers[player_to_move] == 1){
        p = &p1;
    }
    else if (player_markers[player_to_move] == 2){
        p = &p2;
    }


    Player *p;
    p = &p1;

    //Nice move
    Move move = moves[2];

    cout<<"ELECTED MOVE BRO IS:"<<endl;
    move.print_move();

    cout<<"Hand before drawing is:"<<endl;
    p->print_hand();

    //Drawing
    if (move.move_sequence[0] == 1) {
        p->draw("Deck", &deck);
    }
    else if (move.move_sequence[0] == 2)
        p->draw("Discard", &deck);

    cout<<"Hand after drawing is:"<<endl;
    p->print_hand();

    //Melding
    if (!(move.move_sequence[1] == 0)){
        for (int i = 0; i < p->possible_new_melds.size(); i++){

            Card c1 = p->possible_new_melds[i]->meld[0];
            Card c2 = p->possible_new_melds[i]->meld[1];
            Card c3 = p->possible_new_melds[i]->meld[2];
            p->new_meld(c1, c2, c3);
        }
    }
    table.updateMeld();
    p->meld_list[0].print_meld();

    cout<<"Card at "<<move.move_sequence[2]<<" is ";
    p->hand[move.move_sequence[2]].print_card();

    //Discard
    p->discard(p->hand[move.move_sequence[2]], &deck);
    cout<<"Hand after discarding is:"<<endl;
    p->print_hand();


    cout<<"Discarded card is:"<<endl;

    cout<<table.current_deck->discard_pile.size()<<endl;
    table.current_deck->discard_pile[1].print_card();

    //BROVE!!!!!

    cout<<"TIME FOR THE BROVE!"<<endl;

    vector<Move> broves;


    p1.possible_new_melds.clear();
    p1.useless_cards.clear();
    p1.possible_melds.clear();

    p2.possible_new_melds.clear();
    p2.useless_cards.clear();
    p2.possible_melds.clear();

    p2.print_hand();

    //Evaluate the place to draw
    table.evaluate_draw(&p2);

//    p2.possible_new_melds[0]->print_meld();
    //Evaluate which cards are useful or not
    table.evaluate_melds(&p2);

    //p2.possible_new_melds[0]->print_meld();
    //Evaluate which card to discard
    table.evaluate_discard(&p2);


    for (int num : p2.discard_index){
        Move move = Move(p2.draw_from, p2.possible_new_melds, num);
        //move.print_move();
        broves.push_back(move);
        //temp_useless_cards.pop_back();
    }

    for (Move m : broves){
        //cout<<m.move_sequence.size()<<endl;
        m.print_move();
    }

    Player *pro;
    pro = &p2;

    Move brove = broves[2];

    //Drawing
    if (brove.move_sequence[0] == 1) {
        pro->draw("Deck", &deck);
    }
    else if (brove.move_sequence[0] == 2)
        pro->draw("Discard", &deck);

    cout<<"Hand after drawing is:"<<endl;
    pro->print_hand();

    //Melding
    if (!(brove.move_sequence[1] == 0)){
        for (int i = 0; i < pro->possible_new_melds.size(); i++){

            Card c1 = pro->possible_new_melds[i]->meld[0];
            Card c2 = pro->possible_new_melds[i]->meld[1];
            Card c3 = pro->possible_new_melds[i]->meld[2];
            pro->new_meld(c1, c2, c3);
        }
    }
    table.updateMeld();
    //pro->meld_list[0].print_meld();

    cout<<"Card at "<<brove.move_sequence[2]<<" is ";
    pro->hand[brove.move_sequence[2]].print_card();

    //Discard
    pro->discard(pro->hand[brove.move_sequence[2]], &deck);
    cout<<"Hand after discarding is:"<<endl;
    pro->print_hand();


    cout<<"Discarded card is:"<<endl;

    cout<<table.current_deck->discard_pile.size()<<endl;
    table.current_deck->discard_pile[2].print_card();

}


*/
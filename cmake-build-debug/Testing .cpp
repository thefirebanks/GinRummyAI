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

void test_Player(){
    Deck deck = Deck();

    /* Creating and dealing ------------------------------------*/

    //Initialize players
    Player p1 = Player("Cowboy");
    Player p2 = Player("Scout");

    cout<<"Players are "<<p1.name<<" and "<<p2.name<<endl;

    p1.deal(&p2, &deck);

    //Check if they were dealt
    //p1.print_hand();
    //p2.print_hand();

    //Check if a card has been drawn
    p1.draw("Deck", &deck);
    //p1.print_hand();

    /* Discarding ------------------------------------*/

    //Check if discard works
    p1.discard(p1.hand.back(), &deck);
    //p1.print_hand();

    //Check if the discarded card was added to the discarded pile
    p2.draw("Disc", &deck);
    //p2.print_hand();

    /* Melding ------------------------------------*/ // MUST CORRECT POINTERS TO MELD SO WE DONT INITIALIZE THEM CONSTANTLY

    //Print hand before putting melds
    cout<<"Hand of player 1 before meld is:"<<endl;
    p1.print_hand();

    //Check if player can make new melds
    Card c1 = p1.hand.at(0);
    Card c2 = p1.hand.at(1);
    Card c3 = p1.hand.at(2);
    p1.new_meld(c1, c2, c3);

    cout<<"Melds of player 1 are:"<<endl;
    for (Meld m1 : p1.meld_list){
        m1.print_meld();
    }

    //Print hand after putting melds
    cout<<"Hand of player 1 after meld is:"<<endl;
    p1.print_hand();

    //Print hand before putting melds
    cout<<"Hand of player 2 before meld is:"<<endl;
    p2.print_hand();

    // MUST CORRECT POINTERS TO MELD SO WE DONT INITIALIZE THEM CONSTANTLY

    //Check if player can make an addon meld
    p2.addon_meld(p2.hand.front());
    p2.addon_meld(p2.hand.front());
    p2.addon_meld(p2.hand.front());

    cout<<"Melds of player 2 are:"<<endl;
    for (Meld m2 : p2.meld_list){
        m2.print_meld();
    }

    //Print hand after putting melds
    cout<<"Hand of player 2 after meld is:"<<endl;
    p2.print_hand();

    //Add a card to an existing meld
    p1.put_card(p1.hand.at(0), p1.meld_list.at(0), 0);
    p2.put_card(p2.hand[0], p2.meld_list[1], 1);

    /*
    p1_melds = p1.meld_list;
    p2_melds = p2.meld_list;
    */

    cout<<"Melds of player 1 are:"<<endl;
    for (Meld m1 : p1.meld_list){
        m1.print_meld();
    }

    cout<<"Melds of player 2 are:"<<endl;
    for (Meld m2 : p2.meld_list){
        m2.print_meld();
    }

    /* ------------------------------------*/


}

void test_Table(){
    //Initialize shit
    Player Cowboy = Player("Cowboy");
    Player Scout = Player("Scout");
    Deck deck = Deck();

    deck.shuffle();
    deck.shuffle();
    Table table = Table(&Cowboy, &Scout, &deck);

    for (Player* p : table.players){
        cout<<p->name<<endl;
    }

    //Deal
    Cowboy.deal(&Scout, &deck);
    //Scout.hand.front().print_card();
    Scout.discard(*Scout.hand.begin(), &deck);

    Cowboy.print_hand();

    table.evaluate_draw(&Cowboy);
    //Cowboy.print_hand();
    /*
    cout<<"Possible melds are:"<<endl;

    for (int i = 0; i < Cowboy.possible_melds.size(); i++){
        Cowboy.possible_melds[i].print_card();
    }
    */
    cout<<"Possible NEW melds are:"<<endl;
    for (int i = 0; i < Cowboy.possible_new_melds.size(); i++){
        cout<<"Meld "<<i<<" is:"<<endl;
        Cowboy.possible_new_melds.back()->print_meld();
    }

    //cout<<Cowboy.draw_from<<endl;
    //table.evaluate_hand(&Cowboy);

    /*
    cout<<"Cards to compare are"<<endl;
    Cowboy.hand[0].print_card();
    Cowboy.hand[1].print_card();
    */

}




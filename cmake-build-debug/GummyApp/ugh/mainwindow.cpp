#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "deck.h"
#include "meld.h"
#include "player.h"
#include "table.h"
#include <string>
#include <qstring.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    Player computer = Player("Computer");
    Player user = Player("You");
    Deck deck = Deck();
    Table table = Table(&computer, &user, &deck);
    */
    QString cHandSize;
    QString deckSize;
    computer.deal(&user, &deck);
    cHandSize.setNum(computer.hand.size());
    deckSize.setNum(deck.get_size());
    ui->cHandCount->setText(cHandSize);
    ui->deckCount->setText(deckSize);
    QString userHand = QString::fromStdString(user.handToString());
    //Set_Card_Buttons(user);
    ui->userHandList->setText(userHand);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::Set_Card_Buttons(Player* user) {
    QPushButton cards[11] = {*ui->Card0, *ui->Card1, *ui->Card2, *ui->Card3, *ui->Card4, *ui->Card5, *ui->Card6, *ui->Card7, *ui->Card8, *ui->Card9, *ui->Card10};
    for (int i = 0; i < 11; i++ ) {
        cards[i].setText("");
    }
    int handPos = 0;
    for (Card card : user->hand) {
        QString cardText;
        cardText.setNum(card.get_value());
        //cardText.append(card.get_suit());
        cards[handPos].setText(cardText);
    }
}
*/


void MainWindow::on_Card0_clicked()
{
    string str = "";
    str += to_string(user.hand[0].get_value());
    str += " ";
    str += user.hand[0].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}




void MainWindow::on_Card1_clicked()
{
    string str = "";
    str += to_string(user.hand[1].get_value());
    str += " ";
    str += user.hand[1].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

void MainWindow::on_Card2_clicked()
{
    string str = "";
    str += to_string(user.hand[2].get_value());
    str += " ";
    str += user.hand[2].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

void MainWindow::on_Card3_clicked()
{
    string str = "";
    str += to_string(user.hand[3].get_value());
    str += " ";
    str += user.hand[3].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

void MainWindow::on_Card4_clicked()
{
    string str = "";
    str += to_string(user.hand[4].get_value());
    str += " ";
    str += user.hand[4].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

void MainWindow::on_Card5_clicked()
{
    string str = "";
    str += to_string(user.hand[5].get_value());
    str += " ";
    str += user.hand[5].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

void MainWindow::on_Card6_clicked()
{
    string str = "";
    str += to_string(user.hand[6].get_value());
    str += " ";
    str += user.hand[6].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

void MainWindow::on_Card7_clicked()
{
    string str = "";
    str += to_string(user.hand[7].get_value());
    str += " ";
    str += user.hand[7].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

void MainWindow::on_Card8_clicked()
{
    string str = "";
    str += to_string(user.hand[8].get_value());
    str += " ";
    str += user.hand[8].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

void MainWindow::on_Card9_clicked()
{
    string str = "";
    str += to_string(user.hand[9].get_value());
    str += " ";
    str += user.hand[9].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

void MainWindow::on_Card10_clicked()
{
    string str = "";
    str += to_string(user.hand[10].get_value());
    str += " ";
    str += user.hand[10].get_suit();
    QString qstr = QString::fromStdString(str);
    ui->message->setText(qstr);
}

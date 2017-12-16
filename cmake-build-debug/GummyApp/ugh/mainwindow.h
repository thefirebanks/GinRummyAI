#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "card.h"
#include "deck.h"
#include "meld.h"
#include "player.h"
#include "table.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Player computer = Player("Computer");
    Player user = Player("You");
    Deck deck = Deck();
    Table table = Table(&computer, &user, &deck);

private slots:
    void on_Card0_clicked();

    void on_Card1_clicked();

    void on_Card2_clicked();

    void on_Card3_clicked();

    void on_Card4_clicked();

    void on_Card5_clicked();

    void on_Card6_clicked();

    void on_Card7_clicked();

    void on_Card8_clicked();

    void on_Card9_clicked();

    void on_Card10_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

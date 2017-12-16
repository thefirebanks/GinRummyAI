#include "mainwindow.h"
#include <QApplication>
#include "card.h"
#include "deck.h"
#include "meld.h"
#include "player.h"
#include "table.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Gin Rummy");
    w.show();

    return a.exec();
}

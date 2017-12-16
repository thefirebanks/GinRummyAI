/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *endTurnButton;
    QLabel *cHandLabel;
    QLabel *cHandCount;
    QLabel *DeckLabel;
    QLabel *deckCount;
    QLabel *discoLabel;
    QLabel *discoCard;
    QLabel *cMeldLabel;
    QLabel *userMeldsLabel;
    QLabel *cMeldsList;
    QLabel *userMeldsList;
    QLabel *label_6;
    QPushButton *Card0;
    QPushButton *Card1;
    QPushButton *Card2;
    QPushButton *Card3;
    QPushButton *Card4;
    QPushButton *Card6;
    QPushButton *Card8;
    QPushButton *Card9;
    QPushButton *Card5;
    QPushButton *Card7;
    QPushButton *Card10;
    QLabel *message;
    QPushButton *makeMeldButton;
    QLabel *userHandList;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(969, 502);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        endTurnButton = new QPushButton(centralWidget);
        endTurnButton->setObjectName(QStringLiteral("endTurnButton"));
        endTurnButton->setGeometry(QRect(90, 10, 113, 32));
        cHandLabel = new QLabel(centralWidget);
        cHandLabel->setObjectName(QStringLiteral("cHandLabel"));
        cHandLabel->setGeometry(QRect(480, 20, 101, 16));
        cHandCount = new QLabel(centralWidget);
        cHandCount->setObjectName(QStringLiteral("cHandCount"));
        cHandCount->setGeometry(QRect(500, 40, 61, 21));
        cHandCount->setAlignment(Qt::AlignCenter);
        DeckLabel = new QLabel(centralWidget);
        DeckLabel->setObjectName(QStringLiteral("DeckLabel"));
        DeckLabel->setGeometry(QRect(850, 10, 41, 16));
        deckCount = new QLabel(centralWidget);
        deckCount->setObjectName(QStringLiteral("deckCount"));
        deckCount->setGeometry(QRect(840, 30, 60, 21));
        deckCount->setAlignment(Qt::AlignCenter);
        discoLabel = new QLabel(centralWidget);
        discoLabel->setObjectName(QStringLiteral("discoLabel"));
        discoLabel->setGeometry(QRect(830, 70, 81, 16));
        discoCard = new QLabel(centralWidget);
        discoCard->setObjectName(QStringLiteral("discoCard"));
        discoCard->setGeometry(QRect(810, 100, 101, 31));
        discoCard->setAlignment(Qt::AlignCenter);
        cMeldLabel = new QLabel(centralWidget);
        cMeldLabel->setObjectName(QStringLiteral("cMeldLabel"));
        cMeldLabel->setGeometry(QRect(100, 60, 101, 21));
        userMeldsLabel = new QLabel(centralWidget);
        userMeldsLabel->setObjectName(QStringLiteral("userMeldsLabel"));
        userMeldsLabel->setGeometry(QRect(110, 240, 71, 16));
        cMeldsList = new QLabel(centralWidget);
        cMeldsList->setObjectName(QStringLiteral("cMeldsList"));
        cMeldsList->setGeometry(QRect(10, 80, 441, 131));
        userMeldsList = new QLabel(centralWidget);
        userMeldsList->setObjectName(QStringLiteral("userMeldsList"));
        userMeldsList->setGeometry(QRect(10, 260, 481, 161));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(630, 150, 71, 16));
        Card0 = new QPushButton(centralWidget);
        Card0->setObjectName(QStringLiteral("Card0"));
        Card0->setGeometry(QRect(520, 250, 61, 32));
        Card1 = new QPushButton(centralWidget);
        Card1->setObjectName(QStringLiteral("Card1"));
        Card1->setGeometry(QRect(580, 250, 61, 32));
        Card2 = new QPushButton(centralWidget);
        Card2->setObjectName(QStringLiteral("Card2"));
        Card2->setGeometry(QRect(640, 250, 61, 32));
        Card3 = new QPushButton(centralWidget);
        Card3->setObjectName(QStringLiteral("Card3"));
        Card3->setGeometry(QRect(700, 250, 61, 32));
        Card4 = new QPushButton(centralWidget);
        Card4->setObjectName(QStringLiteral("Card4"));
        Card4->setGeometry(QRect(760, 250, 61, 32));
        Card6 = new QPushButton(centralWidget);
        Card6->setObjectName(QStringLiteral("Card6"));
        Card6->setGeometry(QRect(580, 290, 61, 32));
        Card8 = new QPushButton(centralWidget);
        Card8->setObjectName(QStringLiteral("Card8"));
        Card8->setGeometry(QRect(700, 290, 61, 32));
        Card9 = new QPushButton(centralWidget);
        Card9->setObjectName(QStringLiteral("Card9"));
        Card9->setGeometry(QRect(760, 290, 61, 32));
        Card5 = new QPushButton(centralWidget);
        Card5->setObjectName(QStringLiteral("Card5"));
        Card5->setGeometry(QRect(520, 290, 61, 32));
        Card7 = new QPushButton(centralWidget);
        Card7->setObjectName(QStringLiteral("Card7"));
        Card7->setGeometry(QRect(640, 290, 61, 32));
        Card10 = new QPushButton(centralWidget);
        Card10->setObjectName(QStringLiteral("Card10"));
        Card10->setGeometry(QRect(630, 320, 71, 32));
        message = new QLabel(centralWidget);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(560, 370, 231, 41));
        message->setAlignment(Qt::AlignCenter);
        makeMeldButton = new QPushButton(centralWidget);
        makeMeldButton->setObjectName(QStringLiteral("makeMeldButton"));
        makeMeldButton->setGeometry(QRect(480, 100, 91, 32));
        userHandList = new QLabel(centralWidget);
        userHandList->setObjectName(QStringLiteral("userHandList"));
        userHandList->setGeometry(QRect(380, 180, 561, 61));
        userHandList->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(660, 10, 131, 32));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(640, 60, 171, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 969, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        endTurnButton->setText(QApplication::translate("MainWindow", "End Turn", nullptr));
        cHandLabel->setText(QApplication::translate("MainWindow", "Computer Hand", nullptr));
        cHandCount->setText(QString());
        DeckLabel->setText(QApplication::translate("MainWindow", "Deck", nullptr));
        deckCount->setText(QString());
        discoLabel->setText(QApplication::translate("MainWindow", "Discard Pile", nullptr));
        discoCard->setText(QString());
        cMeldLabel->setText(QApplication::translate("MainWindow", "Computer Melds", nullptr));
        userMeldsLabel->setText(QApplication::translate("MainWindow", "Your Melds", nullptr));
        cMeldsList->setText(QString());
        userMeldsList->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Your Hand", nullptr));
        Card0->setText(QApplication::translate("MainWindow", "Card0", nullptr));
        Card1->setText(QApplication::translate("MainWindow", "Card1", nullptr));
        Card2->setText(QApplication::translate("MainWindow", "Card2", nullptr));
        Card3->setText(QApplication::translate("MainWindow", "Card3", nullptr));
        Card4->setText(QApplication::translate("MainWindow", "Card4", nullptr));
        Card6->setText(QApplication::translate("MainWindow", "Card6", nullptr));
        Card8->setText(QApplication::translate("MainWindow", "Card8", nullptr));
        Card9->setText(QApplication::translate("MainWindow", "Card9", nullptr));
        Card5->setText(QApplication::translate("MainWindow", "Card5", nullptr));
        Card7->setText(QApplication::translate("MainWindow", "Card7", nullptr));
        Card10->setText(QApplication::translate("MainWindow", "Card10", nullptr));
        message->setText(QString());
        makeMeldButton->setText(QApplication::translate("MainWindow", "Make Meld", nullptr));
        userHandList->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", " Draw From Deck", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Draw From Discard Pile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

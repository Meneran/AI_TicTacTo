#include "fenetre.h"
#include "ui_mainwindow.h"
#include <QDebug>

Fenetre::Fenetre() {

    QPushButton *commencer = new QPushButton("Commencer", this);
    connect(commencer, &QPushButton::clicked, this, &Fenetre::debutDePartie);
}

void Fenetre::signalaemettre() {
    QPushButton *send = qobject_cast<QPushButton*>(sender());
    for(int i = 0; i < 9; ++i) {
        if(send == mTabButton[i])
            casej = i;
    }
    emit(casejouee(casej));
    for(int i = 0; i < 9; ++i) {
        if(mMorpion.getMorpion()[i] == 1)
            mTabButton[i]->setText("X");
        else if(mMorpion.getMorpion()[i] == 2)
            mTabButton[i]->setText("O");
    }
}

void Fenetre::finDePartie(std::string vaiqueur) {
    if(vaiqueur == "egalite")
        qDebug() << "La partie est finie";
    else if(vaiqueur == "joueur1")
        qDebug() << "Le joueur 1 a gagné la partie";
    else if(vaiqueur == "joueur2")
        qDebug() << "Le joueur 2 a gagné la partie";
    signalaemettre();
    for(int i = 0; i < 9; ++i)
    disconnect(this, &Fenetre::casejouee, &this->mMorpion, &Morpion::jouer);
    disconnect(&this->mMorpion, &Morpion::partieFinie, this, &Fenetre::finDePartie);
}

void Fenetre::debutDePartie() {

    QWidget *jeu = new QWidget;
    joueur = 1;
    QGridLayout *layout = new QGridLayout;
    std::vector<QPushButton*> *TabButton = new std::vector<QPushButton*>;
    mTabButton = *TabButton;

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            QPushButton *button = new QPushButton;
            button->setMaximumWidth(50);
            layout->addWidget(button, i, j);
            mTabButton.push_back(button);
            connect(button, &QPushButton::clicked, this, &Fenetre::signalaemettre);
        }
    }
    jeu->setLayout(layout);
   jeu->show();
    connect(this, &Fenetre::casejouee, &this->mMorpion, &Morpion::jouer);
    connect(&this->mMorpion, &Morpion::partieFinie, this, &Fenetre::finDePartie);
    mMorpion.setDebut();
}

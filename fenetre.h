#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "morpion.h"

class Fenetre : public QWidget
{
    Q_OBJECT

public:
    Fenetre();

signals:
    void casejouee(int casejouee);

public slots:
    void signalaemettre();
    void finDePartie(std::string vaiqueur);
    void debutDePartie();

private:
    std::vector<QPushButton*> mTabButton;
    int casej;
    int joueur;
    Morpion mMorpion;
};

#endif // MAINWINDOW_H

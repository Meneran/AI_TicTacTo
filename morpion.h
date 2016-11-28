#ifndef MORPION_H
#define MORPION_H
#include <vector>
#include <QtWidgets>
#include "ia.h"

class Morpion : public QObject
{
    Q_OBJECT
public:
    Morpion();
    void finDePartie();
    void setDebut();

signals:
    void partieFinie(std::string vainqueur);

public slots:
    void jouer(int index);
    std::vector<int> getMorpion();
private:
    std::vector<int> mMorpion;
    bool mPartieFinie = false;
    bool mJoueur1Gagne = false;
    bool mJoueur2Gagne = false;
    int mjoueur;
    IA m_IA;
};

#endif // MORPION_H

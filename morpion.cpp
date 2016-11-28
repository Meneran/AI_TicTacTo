#include "morpion.h"

Morpion::Morpion()
{
    for(int i = 0; i < 9; ++i)
        mMorpion.push_back(0);
}

void Morpion::finDePartie() {
    bool fin = true;
    for(int i = 0; i < 9; ++i) {
        if(mMorpion[i] == 0)
            fin = false;
    }
    if(fin == true)
        mPartieFinie = true;

    for(int i = 0; i < 3; ++i) {
        if(mMorpion[0 + i] == 1 && mMorpion[3 + i] == 1 && mMorpion[6 + i] == 1)
            mJoueur1Gagne = true;
        if(mMorpion[0 + i] == 2 && mMorpion[3 + i] == 2 && mMorpion[6 + i] == 2)
            mJoueur2Gagne = true;
        if(mMorpion[0 + 3 * i] == 1 && mMorpion[1 + 3 * i] == 1 && mMorpion[2 + 3 * i] == 1)
            mJoueur1Gagne = true;
        if(mMorpion[0 + 3 * i] == 2 && mMorpion[1 + 3 * i] == 2 && mMorpion[2 + 3 * i] == 2)
            mJoueur2Gagne = true;
    }
    if(mMorpion[0] == 1 && mMorpion[4] == 1 && mMorpion[8] == 1)
        mJoueur1Gagne = true;
    if(mMorpion[0] == 2 && mMorpion[4] == 2 && mMorpion[8] == 2)
        mJoueur2Gagne = true;
    if(mMorpion[2] == 1 && mMorpion[4] == 1 && mMorpion[6] == 1)
        mJoueur1Gagne = true;
    if(mMorpion[2] == 2 && mMorpion[4] == 2 && mMorpion[6] == 2)
        mJoueur2Gagne = true;

    if(mPartieFinie)
        emit(partieFinie("egalite"));
    else if(mJoueur1Gagne)
        emit(partieFinie("joueur1"));
    else if(mJoueur2Gagne)
        emit(partieFinie("joueur2"));
}

void Morpion::setDebut() {
    for(int i = 0; i < 9; ++i)
        mMorpion[i] = 0;
    mPartieFinie = mJoueur1Gagne = mJoueur2Gagne = false;
}

void Morpion::jouer(int index) {
    if(mMorpion[index] == 0) {
        mMorpion[index] = 1;
        finDePartie();
        if(!mPartieFinie) {
            mMorpion[m_IA.calIA(mMorpion, 15)] = 2;
        qDebug() << "1";
        }
        finDePartie();
    }
}

std::vector<int> Morpion::getMorpion() {
    return mMorpion;
}


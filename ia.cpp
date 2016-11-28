#include "ia.h"
#include <QDebug>
IA::IA()
{

}


int IA::calIA(std::vector<int> jeuActuel, int profondeur) {
    jeu = jeuActuel;
    int max = m_min;
    int tmp;
    int caseajouer;

    for(int i = 0; i < 9; ++i) {
        if(jeu[i] == 0) {
            jeu[i] = 2;
            tmp = calMin(profondeur - 1);
            if(tmp > max) {
                max = tmp;
                caseajouer = i;
            }
            jeu[i] = 0;
        }
    }
    return caseajouer;
}

int IA::calMax(int profondeur) {
    int max = m_min;
    int tmp;

    if(profondeur == 0 || partieFinie() != -1)
        return evaluation();
    else {
        for(int i = 0; i < 9; ++i) {
            if(jeu[i] == 0) {
                jeu[i] = 2;
                tmp = calMin(profondeur - 1);
                if(tmp > max)
                    max = tmp;
                jeu[i] = 0;
            }
        }
        return max;
    }
}

int IA::calMin(int profondeur) {
    int min = m_max;
    int tmp;

    if(profondeur == 0 || partieFinie() != -1)
        return evaluation();
    else {
         for(int i = 0; i < 9; ++i) {
            if(jeu[i] == 0) {
                jeu[i] = 1;
                tmp = calMax(profondeur - 1);
                if(tmp < min)
                    min = tmp;
                jeu[i] = 0;
            }
        }
        return min;
    }
}

int IA::evaluation() {
    if(partieFinie() != -1) {
        if(partieFinie() == 2)
            return 1000 - comptePions();
        else if(partieFinie() == 0)
            return 0;
        else
            return -1000 + comptePions();
    }
}

int IA::comptePions() {
    int pions = 0;
    for(int i = 0; i < 9; ++i)
        if(jeu[i] != 0)
            pions++;
    return pions;
}

int IA::partieFinie() {
    bool fin = true;

    for(int i = 0; i < 3; ++i) {
        if(jeu[0 + i] == 1 && jeu[3 + i] == 1 && jeu[6 + i] == 1)
            return 1;
        if(jeu[0 + i] == 2 && jeu[3 + i] == 2 && jeu[6 + i] == 2)
            return 2;
        if(jeu[0 + 3 * i] == 1 && jeu[1 + 3 * i] == 1 && jeu[2 + 3 * i] == 1)
            return 1;
        if(jeu[0 + 3 * i] == 2 && jeu[1 + 3 * i] == 2 && jeu[2 + 3 * i] == 2)
            return 2;
    }
    if(jeu[0] == 1 && jeu[4] == 1 && jeu[8] == 1)
        return 1;
    if(jeu[0] == 2 && jeu[4] == 2 && jeu[8] == 2)
        return 2;
    if(jeu[2] == 1 && jeu[4] == 1 && jeu[6] == 1)
        return 1;
    if(jeu[2] == 2 && jeu[4] == 2 && jeu[6] == 2)
        return 2;

    for(int i = 0; i < 9; ++i) {
        if(jeu[i] == 0)
            fin = false;
    }
    if(fin == true)
        return 0;
    else return -1;
}




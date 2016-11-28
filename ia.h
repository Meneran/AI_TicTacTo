#ifndef IA_H
#define IA_H
#include <vector>

class IA
{
public:
    IA();
    int calIA(std::vector<int> jeuActuel, int profondeur);
    int calMax(int profondeur);
    int calMin(int profondeur);
    int evaluation();
    int partieFinie();
    int comptePions();

private:
    std::vector<int> jeu;
    int m_min = -2000;
    int m_max = 2000;
};

#endif // IA_H

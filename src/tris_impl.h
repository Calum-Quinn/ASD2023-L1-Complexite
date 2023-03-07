/* -----------------------------------------------------------------------------------
Nom du fichier : tris_impl.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.02.2023
Description    : Algorithme triant des vecteurs selon le tri demandé
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L1_COMPLEXITE_TRIS_IMPL_H
#define ASD2022_L1_COMPLEXITE_TRIS_IMPL_H

#include <vector>       //Utilisation des vecteurs
#include <algorithm>    //Utilisation du is_sorted

using namespace std;

// Basé sur les exemples de tris du Git PRG1 de M Breguet

// Fonction de tri par bubble
template <class Iterator>
bool bubbleSort(Iterator begin, Iterator end){
    if (begin != end){
        long long cpt = 0;
        for (Iterator i = begin; i != end - 1; ++i){
            for (Iterator j = begin + 1; j != end - cpt; ++j){
                if (*(j-1) > *j) {
                    swap(*(j-1), *j);
                }
            }
            ++cpt;
        }
    }
    return is_sorted(begin, end);
}

// Fonction de tri par insertion
template <class Iterator, typename Number>
bool insertSort(Iterator begin, Iterator end) {
    Number tmp;
    Iterator j;
    for (Iterator i = begin + 1; i != end; ++i) {
        tmp = Number(*i);
        j   = i;
        while (j != begin and *(j - 1) > tmp) {
            *j = *(j-1);
            --j;
        }
        *j = tmp;
    }
    return is_sorted(begin, end);
}

//Fonction de tri par sélection
template <class Iterator>
bool selectionSort(Iterator begin, Iterator end) {
    if (begin != end) {
        Iterator iMin;
        for (Iterator i = begin; i != end - 1; ++i) {
            iMin = i;
            for (Iterator j = i + 1; j != end; ++j) {
                if (*j < *iMin)
                    iMin = j;
            }
            swap(*i, *iMin);
        }
    }
    return is_sorted(begin, end);
}

#endif //ASD2022_L1_COMPLEXITE_TRIS_IMPL_H
#ifndef ASD2022_L1_COMPLEXITE_TRIS_IMPL_H
#define ASD2022_L1_COMPLEXITE_TRIS_IMPL_H


#include "test.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Basé sur les exemples de tris du Git PRG1 de M Breguet

template <class Iterator>
bool bubbleSort(Iterator begin, Iterator end){
    if (begin != end){
        long long cpt = 0;
        for (Iterator i = begin; i != end - 1; ++i){
            for (Iterator j = begin + 1; j != end - cpt; ++j){ // TODO : la comparaison avec end - i était incorrecte
                if (*(j-1) > *j) {
                    swap(*(j-1), *j);
                }
            }
            ++cpt;
        }
    }
    return is_sorted(begin, end);
}

//---------------------------------------------------------
// Fonction de tri par insertion

template <class Iterator, typename Number>
bool insertSort(Iterator begin, Iterator end) {
    Number tmp;
    Iterator j;
    for (Iterator i = begin + 1; i != end; ++i) {
        tmp = *i;
        j   = i;
        while (j != begin and *(j - 1) > tmp) {
            *j = *(j-1);
            --j;
        }
        *j = tmp;
    }
    return is_sorted(begin, end);
}


//--------------------------------------------------------
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

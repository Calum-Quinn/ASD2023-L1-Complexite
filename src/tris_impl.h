#ifndef ASD2022_L1_COMPLEXITE_TRIS_IMPL_H
#define ASD2022_L1_COMPLEXITE_TRIS_IMPL_H


#include "test.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Basé sur les exemples de tris du Git PRG1 de M Breguet

template <class T>
bool bubbleSort(T begin, T end){
    if (begin != end){
        for (T i = begin; i != end - 1; ++i){
            for (T j = begin + 1; *(j) != end - i; ++j){ // TODO : la comparaison avec end - i était incorrecte
                if (*(j-1) > *j) {
                    swap(*(j-1), *j);
                }
            }
        }
    }
    return estTrie(begin, end);
}

//---------------------------------------------------------
// Fonction de tri par insertion

template <class T>
bool insertSort(T begin, T end){
    T tmp;
    T j;
    for (T i = begin + 1; i != end; ++i) {
        *tmp = *i;
        j   = i;
        while (j != begin and *(j - 1) > *tmp) {
            *j = *(j-1);
            --j;
        }
        *j = *tmp;
    }
    return estTrie(begin, end);
}


//--------------------------------------------------------
//Fonction de tri par sélection
template <class T>
bool selectionSort(T begin, T end) {
    if (begin != end) {
        T iMin;
        for (T i = begin; i != end - 1; ++i) {
            iMin = i;
            for (T j = i + 1; j != end; ++j) {
                if (*j < *iMin)
                    iMin = j;
            }
            swap(*i, *iMin);
        }
    }
    return estTrie(begin, end);
}


#endif //ASD2022_L1_COMPLEXITE_TRIS_IMPL_H

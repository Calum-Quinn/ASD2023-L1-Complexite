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
    return is_sorted(begin, end);
}

//---------------------------------------------------------
// Fonction de tri par insertion

template <class T>
bool insertSort(T begin, T end){
    int tmp;
    T j;
    for (T i = begin; i != end; ++i) {
        tmp = *i;
        j   = i;
        while (j >= begin and *(j-1) > tmp) {
            *j = *j-1;
            --j;
        }
        *j = *tmp;
    }
    return is_sorted(begin. end);
}


//--------------------------------------------------------
//Fonction de tri par sélection
/*template <typename T>
bool selectionSort(T begin, T end) {
    if (v.size() > 0) {
        size_t iMin;
        for (size_t i = 0; i < v.size() - 1; ++i) {
            iMin = i;
            for (size_t j = i + 1; j < v.size(); ++j) {
                if (v[j] < v[iMin])
                    iMin = j;
            }
            swap(v[i], v[iMin]);
        }
    }
    return estTrie(v);
}*/

template <typename T>
bool selectionSort(T begin, T end) {
    //if (v.size() > 0) {
        T iMin;
        for (T i = 0; i != end - 1; ++i) {
            iMin = i;
            for (T j = i + 1; j != end; ++j) {
                if (*j < *iMin)
                    iMin = j;
            }
            swap(*i, *iMin);
        }
    //}
    return is_sorted(begin, end);
}


#endif //ASD2022_L1_COMPLEXITE_TRIS_IMPL_H

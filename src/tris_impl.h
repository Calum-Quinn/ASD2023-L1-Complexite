#ifndef ASD2022_L1_COMPLEXITE_TRIS_IMPL_H
#define ASD2022_L1_COMPLEXITE_TRIS_IMPL_H


#include "test.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Basé sur les exemples de tris du Git PRG1 de M Breguet

//---------------------------------------------------------
// Fonction de tri à bulles
/*
template <typename T>
bool bubbleSort(vector<T> v){
    if (v.size() > 0){
        for (size_t i = 0; i < v.size() - 1; ++i){
            for (size_t j = 1; j < v.size() - i; ++j){
                if (v[j - 1] > v[j]) {
                    swap(v[j - 1], v[j]);
                }
            }
        }
    }
    return estTrie(v);
}*/

template <class T>
bool bubbleSort(T begin, T end){
    if (begin != end){
        for (T i = 0; i != end - 1; ++i){
            for (T j = 1; j != end - i; ++j){
                if (*(j-1) > *j) {
                    swap(*(j-1), *j);
                }
            }
        }
    }
    return 1;//estTrie(v);
}


//---------------------------------------------------------
// Fonction de tri par insertion
template <class T>
bool insertSort(T begin, T end){
    int tmp;
    size_t j;
    for (size_t i = 1; i < v.size(); ++i) {
        tmp = v[i];
        j   = i;
        while (j >= 1 and v[j - 1] > tmp) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = tmp;
    }
    return estTrie(v);
}


//--------------------------------------------------------
//Fonction de tri par sélection
template <typename T>
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
}


#endif //ASD2022_L1_COMPLEXITE_TRIS_IMPL_H

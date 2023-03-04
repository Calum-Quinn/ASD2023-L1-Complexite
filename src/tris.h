/* -----------------------------------------------------------------------------------
Nom du fichier : tris.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.02.2023
Description    : Programme triant des vecteurs selon le tri demandé
Remarque(s)    : <à compléter>
Compilateur    : Apple clang version 14.0.0 (clang-1400.0.29.102)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L1_COMPLEXITE_TRIS_H
#define ASD2022_L1_COMPLEXITE_TRIS_H

#include <vector>

    /**
     * @name 	            : bubbleSort
     *
     * @but 	            : tri un vecteur selon l'algorithme bubblesort
     * @param begin         : iterateur de début du vecteur
     * @param end           : iterateur de fin du vecteur
     * @return              : si le vecteur est trié
     * @throws              : NIL
     */
template <class T>
bool bubbleSort(T begin, T end);

    /**
     * @name 	            : insertSort
     *
     * @but 	            : tri un vecteur selon l'algorithme d'insertion
     * @param begin         : iterateur de début du vecteur
     * @param end           : iterateur de fin du vecteur
     * @return              : si le vecteur est trié
     * @throws              : NIL
     */
template <class Iterator, typename Number>
bool insertSort(Iterator begin, Iterator end);

    /**
     * @name 	            : selectionSort
     *
     * @but 	            : tri un vecteur selon l'algorithme de sélection
     * @param begin         : iterateur de début du vecteur
     * @param end           : iterateur de fin du vecteur
     * @return              : si le vecteur est trié
     * @throws              : NIL
     */
template <class T>
bool selectionSort(T begin, T end);

#include "tris_impl.h"

#endif //ASD2022_L1_COMPLEXITE_TRIS_H
/* -----------------------------------------------------------------------------------
Nom du fichier : generateVector.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.02.2023
Description    : Programme de génération des vecteurs correspondant au type de tri
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L1_COMPLEXITE_GENERATEVECTOR_H
#define ASD2022_L1_COMPLEXITE_GENERATEVECTOR_H

enum class typeTri {CROISSANT, DECROISSANT, ALEATOIRE, PRESQUETRIE};

    /**
     * @name 	               : generateVector
     *
     * @but 	               : genère les vecteurs devant être triés
     * @param n	            : taille du vecteur
     * @param const seed      : seed pour la génération de nombres aléatoires
     * @param tri             : type de vecteur à produire
     * @return                : vecteur généré
     * @throws                : NIL
     */
template <typename T>
std::vector<T> generateVector(size_t n, unsigned seed, typeTri tri);

#include "generateVector_impl.h"

#endif //ASD2022_L1_COMPLEXITE_GENERATEVECTOR_H
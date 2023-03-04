/* -----------------------------------------------------------------------------------
Nom du fichier : mesure.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.02.2023
Description    : Programme pour mesurer le temps pour un tri
Remarque(s)    : <à compléter>
Compilateur    : Apple clang version 14.0.0 (clang-1400.0.29.102)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L1_COMPLEXITE_MESURE_H
#define ASD2022_L1_COMPLEXITE_MESURE_H

    /**
     * @name 	            : mesure_temps
     *
     * @but 	            : mesure le temps que prends une fonction pour trier un vecteur
     * @param v1            : vecteur à trier
     * @param f             : fonction de tri à évaluer
     * @return              : temps de tri
     * @throws              : NIL
     */
template<typename T, typename Fn>
double mesure_temps(std::vector<T> v1, Fn f);

#include "mesure_impl.h"

#endif //ASD2022_L1_COMPLEXITE_MESURE_H
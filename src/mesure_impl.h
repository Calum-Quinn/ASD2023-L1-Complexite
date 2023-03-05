/* -----------------------------------------------------------------------------------
Nom du fichier : mesure_impl.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.02.2023
Description    : Programme pour mesurer le temps pour un tri
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L1_COMPLEXITE_MESURE_IMPL_H
#define ASD2022_L1_COMPLEXITE_MESURE_IMPL_H

#include <chrono>
#include <iostream>

template<typename T, typename Fn>
double mesure_temps(std::vector<T> v1, Fn f) {
    //Temps avant tri
    auto t1 = std::chrono::high_resolution_clock::now();
    //Tri
    f(v1.begin(), v1.end());
    //Temps après tri
    auto t2 = std::chrono::high_resolution_clock::now();
    //Différence entre les deux temps
    std::chrono::duration<double, std::milli> time_ms = t2 - t1;

    //Test si le vecteur est bien trié
    std::cout << std::boolalpha << std::is_sorted(v1.begin(), v1.end()) << std::endl;

    return (double)time_ms.count();
}

#endif //ASD2022_L1_COMPLEXITE_MESURE_IMPL_H

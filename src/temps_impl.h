//
// Created by calum on 23.02.2023.
//

#ifndef ASD2022_L1_COMPLEXITE_TEMPS_IMPL_H
#define ASD2022_L1_COMPLEXITE_TEMPS_IMPL_H

#include <chrono>
#include <iostream>
//#include "tris.h"

template<typename T, typename Fn>
double mesure_temps(std::vector<T> v1, Fn f) {
    auto t1 = std::chrono::high_resolution_clock::now();
    f(v1.begin(), v1.end());
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_ms = t2 - t1;

    return (double)time_ms.count();
}


#endif //ASD2022_L1_COMPLEXITE_TEMPS_IMPL_H

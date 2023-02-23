//
// Created by calum on 23.02.2023.
//

#ifndef ASD2022_L1_COMPLEXITE_TEMPS_IMPL_H
#define ASD2022_L1_COMPLEXITE_TEMPS_IMPL_H

#include <chrono>
#include <iostream>
#include "tris.h"


using namespace std;

template<typename Fn>
void mesure_temps(Fn f) {
    auto t1 = std::chrono::high_resolution_clock::now();
    auto r = f();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_ms = t2 - t1;
    cout << "f(" << "v" << ") = " << r
         << " en " << time_ms.count() << " ms "
         << endl;

}


#endif //ASD2022_L1_COMPLEXITE_TEMPS_IMPL_H

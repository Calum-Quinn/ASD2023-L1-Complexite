#ifndef ASD2022_L1_COMPLEXITE_TEMPS_IMPL_H
#define ASD2022_L1_COMPLEXITE_TEMPS_IMPL_H

#include <chrono>
#include <iostream>

template<typename T, typename Fn>
double mesure_temps(std::vector<T> v1, Fn f) {
    auto t1 = std::chrono::high_resolution_clock::now();
    f(v1.begin(), v1.end());
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_ms = t2 - t1;

    std::cout << std::boolalpha << std::is_sorted(v1.begin(), v1.end()) << std::endl;

    return (double)time_ms.count();
}

template<typename T, typename Fn>
double mesure_op(std::vector<T> v1, Fn f) {
    f(v1.begin(), v1.end());
}

#endif //ASD2022_L1_COMPLEXITE_TEMPS_IMPL_H

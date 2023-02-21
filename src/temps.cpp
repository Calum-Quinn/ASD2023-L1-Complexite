
#include <chrono>
#include <iostream>
#include "tris.cpp"

using namespace std;

template<typename Fn>
void mesure_temps(Fn f) {
   for (unsigned i = 10; i < 40; ++i) {
      auto t1 = std::chrono::high_resolution_clock::now();
      auto r = f(i);
      auto t2 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> time_ms = t2 - t1;
      cout << "f(" << i << ") = " << r
           << " en " << time_ms.count() << " ms "
           << endl;
   }
}


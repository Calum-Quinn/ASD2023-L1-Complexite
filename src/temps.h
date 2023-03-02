#ifndef ASD2022_L1_COMPLEXITE_TEMPS_H
#define ASD2022_L1_COMPLEXITE_TEMPS_H

template<typename T, typename Fn>
double mesure_temps(std::vector<T> v1, Fn f);

#include "temps_impl.h" // TODO: ne pas oublier l'import !

#endif //ASD2022_L1_COMPLEXITE_TEMPS_H
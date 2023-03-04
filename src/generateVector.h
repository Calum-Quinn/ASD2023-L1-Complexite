#ifndef ASD2022_L1_COMPLEXITE_GENERATEVECTOR_H
#define ASD2022_L1_COMPLEXITE_GENERATEVECTOR_H

#include <vector>

enum class typeTri {CROISSANT, DECROISSANT, ALEATOIRE, PRESQUETRIE};

template <typename T>
std::vector<T> generateVector(size_t n, unsigned seed, typeTri tri);

#include "generateVector_impl.h"

#endif //ASD2022_L1_COMPLEXITE_GENERATEVECTOR_H
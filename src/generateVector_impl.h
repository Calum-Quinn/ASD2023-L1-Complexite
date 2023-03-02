#ifndef ASD2022_L1_COMPLEXITE_GENERATEVECTOR_IMPL_H
#define ASD2022_L1_COMPLEXITE_GENERATEVECTOR_IMPL_H

#include <random>

template <typename T>
std::vector<T> generateVector(size_t n, int seed, typeTri tri) {
   std::vector<T> vecteur(n);

   if(tri == typeTri::CROISSANT) {
      for (size_t i = 0; i < vecteur.size(); ++i) {
         vecteur[T(i)] = i;
      }
   }

   if(tri == typeTri::DECROISSANT) {
      for (size_t i = vecteur.size() - 1; i >= 0; --i) {
         vecteur[T(i)] = i;
      }
   }

   if (tri == typeTri::ALEATOIRE) {
       for (size_t i = 0; i < vecteur.size(); ++i) {
           vecteur[T(i)] = i;
       }
       shuffle(vecteur.begin(), vecteur.end(), default_random_engine(seed));
   }

   if (tri == typeTri::PRESQUETRIE) {
       for (size_t i = 0; i < vecteur.size(); ++i) {
           srand(seed);
           vecteur[i] = int(double(i)/2. + double(rand()%101)/2.); // Somme pondérée entre tri croissant et aléatoire
       }
   }

   return vecteur;
}

int nbAleatoire(int valMin, int valMax) {
   random_device rand_dev;
   default_random_engine generator(rand_dev());
   uniform_int_distribution<int> distr(valMin, valMax);

   return distr(generator);
}

#endif //ASD2022_L1_COMPLEXITE_GENERATEVECTOR_IMPL_H
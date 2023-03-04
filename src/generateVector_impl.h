#ifndef ASD2022_L1_COMPLEXITE_GENERATEVECTOR_IMPL_H
#define ASD2022_L1_COMPLEXITE_GENERATEVECTOR_IMPL_H

#include <random>


template <typename T>
std::vector<T> generateVector(size_t n, unsigned seed, typeTri tri) {
   std::vector<T> vecteur(n);

   if(tri == typeTri::CROISSANT) {
      for (size_t i = 0; i < vecteur.size(); ++i) {
         vecteur[i] = T(i);
      }
   }

   if(tri == typeTri::DECROISSANT) {
      for (size_t i = 0; i < vecteur.size(); ++i) {
         vecteur[i] = T(n - (i + 1));
      }
   }

   if (tri == typeTri::ALEATOIRE) {
       for (size_t i = 0; i < vecteur.size(); ++i) {
           vecteur[i] = T(i);
       }
       shuffle(vecteur.begin(), vecteur.end(), default_random_engine(seed));
   }

   if (tri == typeTri::PRESQUETRIE) {
       srand((seed));
       for (size_t i = 0; i < vecteur.size(); ++i) {
           vecteur[i] = size_t(double(i)/2. + double(rand()%n)/2.); // Somme pondérée entre tri croissant et aléatoire
       }
   }

   return vecteur;
}

#endif //ASD2022_L1_COMPLEXITE_GENERATEVECTOR_IMPL_H
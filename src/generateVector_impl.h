/* -----------------------------------------------------------------------------------
Nom du fichier : generateVector_impl.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.02.2023
Description    : Programme de génération des vecteurs devant être triés
Remarque(s)    : <à compléter>
Compilateur    : Apple clang version 14.0.0 (clang-1400.0.29.102)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L1_COMPLEXITE_GENERATEVECTOR_IMPL_H
#define ASD2022_L1_COMPLEXITE_GENERATEVECTOR_IMPL_H

template <typename T>
std::vector<T> generateVector(size_t n, unsigned seed, typeTri tri) {
   std::vector<T> vecteur(n);

   //Vecteur croissant de 0 à n-1
   if(tri == typeTri::CROISSANT) {
      for (size_t i = 0; i < vecteur.size(); ++i) {
         vecteur[i] = T(i);
      }
   }

   //Vecteur décroissant de n-1 à 0
   if(tri == typeTri::DECROISSANT) {
      for (size_t i = 0; i < vecteur.size(); ++i) {
         vecteur[i] = T(n - (i + 1));
      }
   }

   //Vecteur aléatoire avec de 0 à n-1
   if (tri == typeTri::ALEATOIRE) {
       for (size_t i = 0; i < vecteur.size(); ++i) {
           vecteur[i] = T(i);
       }
       shuffle(vecteur.begin(), vecteur.end(), default_random_engine(seed));
   }

   //Vecteur ressemblant à trié
   if (tri == typeTri::PRESQUETRIE) {
       srand((seed));
       for (size_t i = 0; i < vecteur.size(); ++i) {
           vecteur[i] = T(double(i)/2. + double(rand()%n)/2.); // Somme pondérée entre tri croissant et aléatoire
       }
   }

   return vecteur;
}

#endif //ASD2022_L1_COMPLEXITE_GENERATEVECTOR_IMPL_H
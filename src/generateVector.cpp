#include <vector>
#include <random>

using namespace std;

enum class typeTri {CROISSANT, DECROISSANT, ALEATOIRE, PRESQUETRIE};

template <typename T>
vector<T> generateVector(size_t n, int seed, typeTri tri) {
   vector<T> vecteur(n);

   if(tri == typeTri::CROISSANT) {
      for (int i = 0; i < vecteur.size(); ++i) {
         vecteur[T(i)];
      }
   }

   if(tri == typeTri::DECROISSANT) {
      for (int i = vecteur.size() - 1; i >= 0; --i) {
         vecteur[T(i)];
      }
   }

   if (tri == typeTri::ALEATOIRE) {
       for (int i = 0; i < vecteur.size(); ++i) {
           vecteur[T(i)];
       }
       shuffle(vecteur.begin(), vecteur.end(), default_random_engine(seed));
   }

   if (tri == typeTri::PRESQUETRIE) {
       for (int i = 0; i < vecteur.size(); ++i) {
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
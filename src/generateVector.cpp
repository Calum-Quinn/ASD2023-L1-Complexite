

enum class typeTri {CROISSANT, DECROISSANT, ALEATOIRE, PRESQUETRIE};

template <typename T>
vector<T> generateVector(size_t n, int seed, typeTri tri) {
   vector<T> vecteur(n);

   if(tri == typeTri::CROISSANT) {
      for (T i = 0; i < vecteur.size(); ++i) {
         vecteur[i];
      }
   }

   if(tri == typeTri::DECROISSANT) {
      for (T i = vecteur.size() - 1; i >= 0; --i) {
         vecteur[i];
      }
   }

   if (tri == typeTri::ALEATOIRE) {

   }

   return vecteur;
}

int nbAleatoire(int valMin, int valMax) {
   random_device rand_dev;
   default_random_engine generator(rand_dev());
   uniform_int_distribution<int> distr(valMin, valMax);

   return distr(generator);
}
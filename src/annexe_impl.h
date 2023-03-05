/* -----------------------------------------------------------------------------------
Nom du fichier : annexe_impl.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 05.03.2023
Description    : Algorithme d'exportation de données dans un fichier csv
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L1_COMPLEXITE_ANNEXE_IMPL_H
#define ASD2022_L1_COMPLEXITE_ANNEXE_IMPL_H

#include <iostream>

template <typename T>
void exporter_csv(std::string const& filename, const std::vector<int>& n_values, const std::vector<std::vector<T>>& mesures) {

   std::ofstream out(filename);

   if(not out.is_open()) {
      std::cerr << "Pas pu ouvrir le fichier en écriture" << std::endl;
      return;
   }

   out << "n";
   for(int n : n_values) out << ";" << n;
   out << std::endl;

   //Si c'est le temps
   if (mesures.size() <= 5) { //5 corresponds au nombre de tris
      for(size_t i = 0; i < mesures.size(); ++i) {
         switch (i) {
            case 0 : out << "BubbleSort"; break;
            case 1 : out << "InsertionSort"; break;
            case 2 : out << "SelectionSort"; break;
            case 3 : out << "Sort"; break;
            case 4 : out << "StableSort"; break;
            default: break;
         }
         for (T d : mesures[i])
            out << ";" << d;
         out << std::endl;
      }
   }
   // Si c'est les opérations
   else {
      for(size_t i = 0; i < mesures.size(); ++i) {
         switch (i) {
            case 0 : out << "Bubble Affecations"; break;
            case 1 : out << "Bubble Comparaisons"; break;
            case 2 : out << "Insertion Affecations"; break;
            case 3 : out << "Insertion Comparaisons"; break;
            case 4 : out << "Selection Affectations"; break;
            case 5 : out << "Selection Comparaisons"; break;
            case 6 : out << "Sort Affecations"; break;
            case 7 : out << "Sort Comparaisons"; break;
            case 8 : out << "StableSort Affectations"; break;
            case 9 : out << "StableSort Comparaisons"; break;
            default: break;
         }
         for (T d : mesures[i])
            out << ";" << d;
         out << std::endl;
      }
   }
}

#endif //ASD2022_L1_COMPLEXITE_ANNEXE_IMPL_H

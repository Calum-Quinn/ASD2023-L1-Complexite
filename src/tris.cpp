#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Basé sur les exemples de tris du Git PRG1 de M Breguet


//---------------------------------------------------------
// Fonction de tri à bulles
template <typename T>
void bubbleSort(vector<T>& v){
   if (v.size() > 0){
      for (size_t i = 0; i < v.size() - 1; ++i){
         for (size_t j = 1; j < v.size() - i; ++j){
            if (v[j - 1] > v[j]) {
               swap(v[j - 1], v[j]);
            }
         }
      }
   }
}


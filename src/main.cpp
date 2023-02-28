#include <iostream>
#include <vector>
#include <random>
#include "test.h"
#include "temps.h"
#include "tris.h"
#include "generateVector.h"

using namespace std;

unsigned cnt = 0;

int main() {

   vector<int> vec1 = {1,2,3,4,5};
   vector<double> vec2 = {1.,3.,2.,4.,5.};

   //Après un srand(...) tous les appels de rand() sont prévisibles
   srand(36);

   cout << rand() << endl;
   cout << rand() << endl;

   cout << boolalpha << estTrie(vec1) << endl;
   cout << boolalpha << estTrie(vec2) << endl;

//   vector<int> generation = generateVector<int>(15, 47, typeTri(3));
//
//    for (int i : generation) {
//        cout << i << ", ";
//    }

//bool test = bubbleSort(vec1);

 mesure_temps(bubbleSort<int>);
//   mesure_temps(insertSort(vec1));
//   mesure_temps(selectionSort(vec1));

   return 0;
}

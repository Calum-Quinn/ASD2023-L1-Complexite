#include <iostream>
#include <vector>
#include <random>
#include "test.h"
#include "temps.h"
#include "tris.h"
#include "generateVector.h"
#include "algorithm"

using namespace std;

unsigned cnt = 0;

int main() {

    const int VALEURSMIN = 10;
    const int VALEURSMAX = 100;
    const int SEED = 475678;

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

    vector<double> valeurs;
    vector<vector<double>> mesures(5);

    int compteur;
    for (int i = VALEURSMIN; i <= VALEURSMAX; i += 10, ++compteur) {
        compteur = 0;
        vector<int> vecteur = generateVector<int>(i, SEED, typeTri::CROISSANT);

        valeurs[compteur] = i;

        mesure_temps<int>(vecteur, bubbleSort<vector<int>::iterator>);

        mesures[0][i - VALEURSMIN] = mesure_temps<int>(vecteur,bubbleSort<int>);


        mesures[1][i - VALEURSMIN] = mesure_temps(insertSort<vector<int>::iterator>,vecteur);
        mesures[2][i - VALEURSMIN] = mesure_temps(selectionSort<int>,vector<int>::iterator>,vecteur);
        mesures[3][i - VALEURSMIN] = mesure_temps(vecteur, sort<vector<int>::iterator>);
        mesures[4][i - VALEURSMIN] = mesure_temps(stable_sort,vecteur);
    }

    /*
    cout << "Bubble Sort : ";
    mesure_temps(bubbleSort<int>, vec1);

    cout << endl << "Insert Sort : ";
    mesure_temps(insertSort<int>, vec1);

    cout << endl << "Selection Sort : ";
    mesure_temps(selectionSort<int>, vec1);
     */

   return 0;
}

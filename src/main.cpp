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
        mesures[3][i - VALEURSMIN] = mesure_temps(vecteur, std::sort<vector<int>::iterator>);
        mesures[0][i - VALEURSMIN] = mesure_temps(bubbleSort<>,vecteur);
        mesures[1][i - VALEURSMIN] = mesure_temps(insertSort<vector<int>::iterator>,vecteur);
        mesures[2][i - VALEURSMIN] = mesure_temps(selectionSort<int>,vector<int>::iterator>,vecteur);
        mesures[3][i - VALEURSMIN] = mesure_temps(sort,vecteur);
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
    mesure_temps(sort, vec1);

    sort(vec1.begin(), vec1.end());
    stable_sort(vec1.begin(), vec1.end());

    //sort()

//   mesure_temps(insertSort(vec1));
//   mesure_temps(selectionSort(vec1));

   return 0;
}

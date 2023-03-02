#include <iostream>
#include <vector>
#include "temps.h"
#include "tris.h"
#include "generateVector.h"
#include "algorithm"

using namespace std;

unsigned cnt = 0;

int main() {

    const int VALEURSMIN = 10;
    const int VALEURSMAX = 100;
    const int PALIER = 10;
    const int SEED = 475678;

    vector<int> vec1 = {1,290,3,47,5,64,7,23,56};
    vector<int> vec2 = {1,290,3,47,5,64,7,23,56};
    vector<int> vec3 = {1,290,3,47,5,64,7,23,56};

    cout << insertSort<vector<int>::iterator, int>(vec1.begin(), vec1.end()) << endl;
    cout << selectionSort(vec2.begin(), vec2.end()) << endl;
    cout << bubbleSort<vector<int>::iterator>(vec3.begin(), vec3.end()) << endl;

    for (int i : vec1) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : vec2) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : vec3) {
        cout << i << " ";
    }

    vector<double> valeurs((VALEURSMAX - VALEURSMIN) / 10 + 1); //Vecteur pour stocker le nombre de valeurs triées
    vector<vector<double>> mesures(5);                          //Vecteur pour stocker des vecteurs de mesures de temps
                                                                //de tris

    int compteur;
    for (size_t i = VALEURSMIN; i <= VALEURSMAX; i += PALIER, ++compteur) {
        compteur = 0;
        vector<int> vecteur = generateVector<int>(i, SEED, typeTri::CROISSANT);

        valeurs[compteur] = i;

        mesures[0][i - VALEURSMIN] = mesure_temps(vecteur, bubbleSort<vector<int>::iterator>);
        mesures[1][i - VALEURSMIN] = mesure_temps(vecteur, insertSort<vector<int>::iterator,int>);
        mesures[2][i - VALEURSMIN] = mesure_temps(vecteur, selectionSort<vector<int>::iterator>);
        mesures[3][i - VALEURSMIN] = mesure_temps(vecteur, sort<vector<int>::iterator>);
        mesures[4][i - VALEURSMIN] = mesure_temps(vecteur, stable_sort<vector<int>::iterator>);
    }
   return EXIT_SUCCESS;
}
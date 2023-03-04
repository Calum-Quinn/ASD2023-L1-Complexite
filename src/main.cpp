/* -----------------------------------------------------------------------------------
Nom du fichier : main.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.02.2023
Description    : Programme principal
Remarque(s)    : <à compléter>
Compilateur    : Apple clang version 14.0.0 (clang-1400.0.29.102)
----------------------------------------------------------------------------------- */

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "temps.h"
#include "tris.h"
#include "generateVector.h"


using namespace std;

void exporter_csv(string const& filename, const vector<double>& n_values, const vector<vector<double>>& mesures);

int main() {

    const int VALEURSMIN = 10;
    const int VALEURSMAX = 100;
    const int PALIER = 10;
    const unsigned SEED = 475678;

    vector<int> vec1 = {1,290,3,47,5,64,7,23,56};
    vector<int> vec2 = {1,290,3,47,5,64,7,23,56};
    vector<int> vec3 = {1,290,3,47,5,64,7,23,56};

    vector<double> valeurs((VALEURSMAX - VALEURSMIN) / 10 + 1); //Vecteur pour stocker le nombre de valeurs triées
    vector<vector<double>> mesures(5); //Vecteur pour stocker des vecteurs de mesures de temps
                                                                //de tris
    for (vector<double>& mesure : mesures) {
        mesure.resize(((VALEURSMAX - VALEURSMIN) / 10 + 1));
    }

    for (size_t i = VALEURSMIN, compteur = 0; i <= VALEURSMAX; i += PALIER, ++compteur) {
        vector<int> vecteur = generateVector<int>(i, SEED, typeTri::PRESQUETRIE);

        valeurs[compteur] = double(i);


        cout << "BubbleSort trie ";
        mesures[0][compteur] = mesure_temps(vecteur, bubbleSort<vector<int>::iterator>);
        cout << "InsertSort trie ";
        mesures[1][compteur] = mesure_temps(vecteur, insertSort<vector<int>::iterator,int>);
        cout << "SelectionSort trie ";
        mesures[2][compteur] = mesure_temps(vecteur, selectionSort<vector<int>::iterator>);
        cout << "Sort trie ";
        mesures[3][compteur] = mesure_temps(vecteur, sort<vector<int>::iterator>);
        cout << "StableSort trie ";
        mesures[4][compteur] = mesure_temps(vecteur, stable_sort<vector<int>::iterator>);

        cout << endl;
    }

    exporter_csv("C:/Users/calum/OneDrive/Documents/Etudes/HEIG/Semestre2/ASD/Laboratoires//ASD2023-L1-Complexite//src/example.csv",valeurs,mesures);

   return EXIT_SUCCESS;
}

void exporter_csv(string const& filename, const vector<double>& n_values, const vector<vector<double>>& mesures) {

    ofstream out(filename);

    if(not out.is_open()) {
        cerr << "Pas pu ouvrir le fichier en écriture" << endl;
        return;
    }

    out << "n";
    for(double n : n_values) out << ";" << n;
    out << endl;

    for(size_t i = 0; i < mesures.size(); ++i) {
        switch (i) {
            case 0 : out << "BubbleSort"; break;
            case 1 : out << "InsertionSort"; break;
            case 2 : out << "SelectionSort"; break;
            case 3 : out << "Sort"; break;
            case 4 : out << "StableSort"; break;
            default: break;
        }
        for (double d : mesures[i])
            out << ";" << d;
        out << endl;
    }

}
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

    vector<int> valeurs((VALEURSMAX - VALEURSMIN) / 10 + 1); //Vecteur pour stocker le nombre de valeurs triées
    vector<vector<double>> mesures(NBR_TRIS); //Vecteur pour stocker des vecteurs de mesures de temps
                                                                //de tri
    vector<vector<unsigned>> mesuresOp(2 * NBR_TRIS);

    for (vector<double>& mesure : mesures) {
        mesure.resize(((VALEURSMAX - VALEURSMIN) / 10 + 1));
    }
    for (vector<unsigned>& mesure : mesuresOp) {
        mesure.resize(((VALEURSMAX - VALEURSMIN) / 10 + 1));
    }

    for (size_t i = VALEURSMIN, compteur = 0; i <= VALEURSMAX; i += PALIER, ++compteur) {
        vector<int> vecteur = generateVector<int>(i, SEED, typeTri::PRESQUETRIE);

        valeurs[compteur] = double(i);

        //Mesures du temps de tri
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

        bubbleSort<vector<OpCounter<int>>::iterator>(opVecteur.begin(),opVecteur.end());
        mesuresOp[0][compteur] = OpCounter<int>::cntAff;
        mesuresOp[1][compteur] = OpCounter<int>::cntComp;
        OpCounter<int>::resetCnt();

        insertSort<vector<OpCounter<int>>::iterator,OpCounter<int>>(opVecteur.begin(),opVecteur.end());
        mesuresOp[2][compteur] = OpCounter<int>::cntAff;
        mesuresOp[3][compteur] = OpCounter<int>::cntComp;
        OpCounter<int>::resetCnt();

        selectionSort<vector<OpCounter<int>>::iterator>(opVecteur.begin(),opVecteur.end());
        mesuresOp[4][compteur] = OpCounter<int>::cntAff;
        mesuresOp[5][compteur] = OpCounter<int>::cntComp;
        OpCounter<int>::resetCnt();

        sort<vector<OpCounter<int>>::iterator>(opVecteur.begin(),opVecteur.end());
        mesuresOp[6][compteur] = OpCounter<int>::cntAff;
        mesuresOp[7][compteur] = OpCounter<int>::cntComp;
        OpCounter<int>::resetCnt();

        stable_sort<vector<OpCounter<int>>::iterator>(opVecteur.begin(),opVecteur.end());
        mesuresOp[8][compteur] = OpCounter<int>::cntAff;
        mesuresOp[9][compteur] = OpCounter<int>::cntComp;

        cout << endl;
    }

    exporter_csv("C:/Users/calum/OneDrive/Documents/Etudes/HEIG/Semestre2/ASD/Laboratoires//ASD2023-L1-Complexite//src/example.csv",valeurs,mesures);
    exporter_csv<unsigned>("C:/Users/calum/OneDrive/Documents/Etudes/HEIG/Semestre2/ASD/Laboratoires//ASD2023-L1-Complexite//src/compteOperations.csv",valeurs,mesuresOp);

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

    if (mesures.size() <= 5) {
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
            out << endl;
        }
    } else {
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
            out << endl;
        }
    }
}
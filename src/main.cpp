/* -----------------------------------------------------------------------------------
Nom du fichier : main.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.02.2023
Description    : Programme principal
Remarque(s)    : <à compléter>
Compilateur    : Apple clang version 14.0.0 (clang-1400.0.29.102)
----------------------------------------------------------------------------------- */

#include <iostream>     //Pour afficher si le vecteur a correctement été trié
#include <vector>       //Pour créer les vecteurs
#include <fstream>      //Pour exporter les donnnées en CSV
#include <algorithm>    //Pour des opérations comme is_sorted et stable_sort

#include "mesure.h"
#include "tris.h"
#include "generateVector.h"
#include "OpCounter.h"

using namespace std;

template <typename T>
void exporter_csv(string const& filename, const vector<int>& n_values, const vector<vector<T>>& mesures);

int main() {

    const int NBR_TRIS = 5;
    const int VALEURSMIN = 10;
    const int VALEURSMAX = 100;
    const int PALIER = 10;
    const unsigned SEED = 475678;

    //Vecteur pour stocker le nombre de valeurs triées
    vector<int> valeurs((VALEURSMAX - VALEURSMIN) / 10 + 1);

    //Vecteur pour stocker des vecteurs de mesures de temps de tri
    vector<vector<double>> mesures(NBR_TRIS);

    //Vecteur pour stocker le nombre d'opérations
    vector<vector<unsigned>> mesuresOp(2 * NBR_TRIS);

    //Initialisation des vecteurs
    for (vector<double>& mesure : mesures) {
        mesure.resize(((VALEURSMAX - VALEURSMIN) / 10 + 1));
    }
    for (vector<unsigned>& mesure : mesuresOp) {
        mesure.resize(((VALEURSMAX - VALEURSMIN) / 10 + 1));
    }

    //Prise des mesures
    for (size_t i = VALEURSMIN, compteur = 0; i <= VALEURSMAX; i += PALIER, ++compteur) {
        //Génération des vecteurs selon le type de tri
        vector<int> vecteur = generateVector<int>(i, SEED, typeTri::PRESQUETRIE);
        vector<OpCounter<int>> opVecteur = generateVector<OpCounter<int>>(i, SEED, typeTri::PRESQUETRIE);
        //Reset les compteurs pour que ça ne retourne seulement les opérations dans les tris
        OpCounter<int>::resetCnt();

        //Remplis le vecteur pour le nombre de valeurs étant triés
        valeurs[compteur] = int(i);

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

        //Mesures du nombre d'opérations
        //BubbleSort
        bubbleSort<vector<OpCounter<int>>::iterator>(opVecteur.begin(),opVecteur.end());
        mesuresOp[0][compteur] = OpCounter<int>::cntAff;
        mesuresOp[1][compteur] = OpCounter<int>::cntComp;
        OpCounter<int>::resetCnt();

        //InsertSort
        insertSort<vector<OpCounter<int>>::iterator,OpCounter<int>>(opVecteur.begin(),opVecteur.end());
        mesuresOp[2][compteur] = OpCounter<int>::cntAff;
        mesuresOp[3][compteur] = OpCounter<int>::cntComp;
        OpCounter<int>::resetCnt();

        //SelectionSort
        selectionSort<vector<OpCounter<int>>::iterator>(opVecteur.begin(),opVecteur.end());
        mesuresOp[4][compteur] = OpCounter<int>::cntAff;
        mesuresOp[5][compteur] = OpCounter<int>::cntComp;
        OpCounter<int>::resetCnt();

        //Sort
        sort<vector<OpCounter<int>>::iterator>(opVecteur.begin(),opVecteur.end());
        mesuresOp[6][compteur] = OpCounter<int>::cntAff;
        mesuresOp[7][compteur] = OpCounter<int>::cntComp;
        OpCounter<int>::resetCnt();

        //StableSort
        stable_sort<vector<OpCounter<int>>::iterator>(opVecteur.begin(),opVecteur.end());
        mesuresOp[8][compteur] = OpCounter<int>::cntAff;
        mesuresOp[9][compteur] = OpCounter<int>::cntComp;
    }

    //Export local des mesures en format CSV
    exporter_csv("C:/Users/calum/OneDrive/Documents/Etudes/HEIG/Semestre2/ASD/Laboratoires//ASD2023-L1-Complexite//src/example.csv",valeurs,mesures);
    exporter_csv<unsigned>("C:/Users/calum/OneDrive/Documents/Etudes/HEIG/Semestre2/ASD/Laboratoires//ASD2023-L1-Complexite//src/compteOperations.csv",valeurs,mesuresOp);

   return EXIT_SUCCESS;
}

template <typename T>
void exporter_csv(string const& filename, const vector<int>& n_values, const vector<vector<T>>& mesures) {

    ofstream out(filename);

    if(not out.is_open()) {
        cerr << "Pas pu ouvrir le fichier en écriture" << endl;
        return;
    }

    out << "n";
    for(int n : n_values) out << ";" << n;
    out << endl;

    //Si c'est le temps
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
    }
    //Si c'est les opérations
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
            out << endl;
        }
    }
}
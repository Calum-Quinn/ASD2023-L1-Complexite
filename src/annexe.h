/* -----------------------------------------------------------------------------------
Nom du fichier : annexe.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 05.03.2023
Description    : Programme servant à l'exportation de données dans un fichier csv
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L1_COMPLEXITE_ANNEXE_H
#define ASD2022_L1_COMPLEXITE_ANNEXE_H

#include <string>       // Utilisation du string
#include <vector>       // Utilisation des vecteurs
#include <fstream>      // Pour exporter les donnnées en CSV

/**
 * @name 	                : export_csv
 *
 * @but 	                   : export de données dans un fichier csv
 * @param filename          : emplacement du fichier de destination
 * @param n_values          : nombre de colonnes
 * @param mesures           : données qui seront affichées dans le fichier
 * @return                  : NIL
 * @throws                  : NIL
 */
template <typename T>
void exporter_csv(std::string const& filename, const std::vector<int>& n_values, const std::vector<std::vector<T>>& mesures);

#include "annexe_impl.h"

#endif //ASD2022_L1_COMPLEXITE_ANNEXE_H

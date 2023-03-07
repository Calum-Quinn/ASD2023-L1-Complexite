/* -----------------------------------------------------------------------------------
Nom du fichier : OpCounter.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.02.2023
Description    : Classe chargée de compter le nombres d'opérations effectués lors d'un tris
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD2022_L1_COMPLEXITE_OPCOUNTER_H
#define ASD2022_L1_COMPLEXITE_OPCOUNTER_H

template <typename T>
class OpCounter{
public:
    /**
     * @name                : OpCounter
     *
     * @but                 : Constructeur par défaut
     *
     * @return              : void
     * @throws              : NIL
     */
    OpCounter() {};

    /**
     * @name                : OpCounter
     *
     * @but                 : Constructeur avec paramètre
     *
     * @param i             : valeur a affecter
     * @return              : void
     * @throws              : NIL
     */
    OpCounter(T i) : val(i){};

    /**
     * @name                : OpCounter
     *
     * @but                 : Constructeur par copie
     *
     * @param autre         : OpCounter a copier
     * @return              : void
     * @throws              : NIL
     */
    OpCounter(const OpCounter& autre) : val(autre.val){};

    /**
     * @name            : resetCnt
     *
     * @but             : Fonction qui reset les compteurs d'opérations
     *
     * @return          : void
     * @throws          : NIL
     */
    static void resetCnt();

    /**
     * @name                : operator<
     *
     * @but                 : comparer la taille de deux OpCounter
     *
     * @param autre         : OpCounter a comparer
     * @return              : si le premier est plus petit
     * @throws              : NIL
     */
    bool operator<  (const OpCounter& autre) const;

    /**
     * @name                : operator>
     *
     * @but                 : comparer la taille de deux OpCounter
     *
     * @param autre         : OpCounter a comparer
     * @return              : si le premier est plus grand
     * @throws              : NIL
     */
    bool operator>  (const OpCounter& autre) const;

    /**
     * @name                : operator<=
     *
     * @but                 : comparer la taille de deux OpCounter
     *
     * @param autre         : OpCounter a comparer
     * @return              : si le premier est plus petit ou égal
     * @throws              : NIL
     */
    bool operator<= (const OpCounter& autre) const;

    /**
     * @name                : operator>=
     *
     * @but                 : comparer la taille de deux OpCounter
     *
     * @param autre         : OpCounter a comparer
     * @return              : si le premier est plus grand ou égal
     * @throws              : NIL
     */
    bool operator>= (const OpCounter& autre) const;

    /**
     * @name                : operator==
     *
     * @but                 : comparer deux OpCounter
     *
     * @param autre         : OpCounter a comparer
     * @return              : si le premier est égal
     * @throws              : NIL
     */
    bool operator== (const OpCounter& autre) const;

    /**
     * @name                : operator!=
     *
     * @but                 : comparer deux OpCounter
     *
     * @param autre         : OpCounter a comparer
     * @return              : si le premier n'est pas égal
     * @throws              : NIL
     */
    bool operator!= (const OpCounter& autre) const;

    /**
     * @name                : operator=
     *
     * @but                 : opérateur d'affectation
     *
     * @param autre         : OpCounter a affecter
     * @return              : l'OpCounter
     * @throws              : NIL
     */
    OpCounter& operator=(const OpCounter& autre);

    static unsigned     cntAff,
                        cntComp;
private:
    T val;
};

#include "OpCounter_impl.h"

#endif //ASD2022_L1_COMPLEXITE_OPCOUNTER_H

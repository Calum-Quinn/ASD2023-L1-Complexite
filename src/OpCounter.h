//
// Created by ema on 28.02.2023.
//

#ifndef ASD2022_L1_COMPLEXITE_OPCOUNTER_H
#define ASD2022_L1_COMPLEXITE_OPCOUNTER_H

template <typename T>
class OpCounter{
public:
    OpCounter(T i) : val(i){};
    static void resetCnt();
    bool operator<  (const OpCounter& autre) const;
    bool operator>  (const OpCounter& autre) const;
    bool operator<= (const OpCounter& autre) const;
    bool operator>= (const OpCounter& autre) const;
    bool operator== (const OpCounter& autre) const;
    bool operator!= (const OpCounter& autre) const;
    OpCounter& operator=(const OpCounter& autre) const;
private:
    T val;
    static unsigned  cntAff,
            cntComp,
            cntIt;
};

#include "OpCounter_impl.h"

#endif //ASD2022_L1_COMPLEXITE_OPCOUNTER_H

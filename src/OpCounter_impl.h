//
// Created by ema on 28.02.2023.
//

#ifndef ASD2022_L1_COMPLEXITE_OPCOUNTER_IMPL_H
#define ASD2022_L1_COMPLEXITE_OPCOUNTER_IMPL_H

template <typename T>
bool OpCounter<T>::operator< (const OpCounter& autre) const{
    ++cntComp;
    return this->val < autre.val;
}

template <typename T>
bool OpCounter<T>::operator> (const OpCounter& autre) const{
    ++cntComp;
    return autre < *this;
}

template <typename T>
bool OpCounter<T>::operator<= (const OpCounter& autre) const{
    ++cntComp;
    return this->val <= autre.val;
}

template <typename T>
bool OpCounter<T>::operator>= (const OpCounter& autre) const{
    ++cntComp;
    return autre < *this;
}

template <typename T>
OpCounter& OpCounter<T>::operator=(const OpCounter& autre) const{
    if(this = &autre)
        return *this;
    ++cntAff;
    this->i = autre.i;
    return *this;
}

template <typename T>
bool operator== (const OpCounter& autre) const{
    ++cntComp;
    return this->i == autre.i;
}

template <typename T>
bool operator!= (const OpCounter& autre) const{
    ++cntComp;
    return not(*this == autre);
}

template <typename T>
void OpCounter<T>::resetCnt() {
    cntAff  = 0;
    cntComp = 0;
    cntIt   = 0;
}

#endif //ASD2022_L1_COMPLEXITE_OPCOUNTER_IMPL_H

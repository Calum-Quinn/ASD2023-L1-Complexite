#ifndef ASD2022_L1_COMPLEXITE_OPCOUNTER_IMPL_H
#define ASD2022_L1_COMPLEXITE_OPCOUNTER_IMPL_H

template <typename T>
unsigned  OpCounter<T>::cntAff = 0;

template <typename T>
unsigned  OpCounter<T>::cntComp = 0;

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
OpCounter<T>& OpCounter<T>::operator=(const OpCounter& autre){
    if(this == &autre)
        return *this;
    ++cntAff;
    this->val = autre.val;
    return *this;
}

template <typename T>
bool OpCounter<T>::operator== (const OpCounter<T>& autre) const{
    ++cntComp;
    return this->val == autre.val;
}

template <typename T>
bool OpCounter<T>::operator!= (const OpCounter<T>& autre) const{
    ++cntComp;
    return not(*this == autre);
}

template <typename T>
void OpCounter<T>::resetCnt() {
    cntAff  = 0;
    cntComp = 0;
}

#endif //ASD2022_L1_COMPLEXITE_OPCOUNTER_IMPL_H


template <typename T>
class OpCounter{
public:
    OpCounter(T i) : val(i){};
    static void resetCnt();
    bool operator<(const OpCounter& autre) const;
    bool operator>(const OpCounter& autre) const;
    bool operator<=(const OpCounter& autre) const;
    bool operator>=(const OpCounter& autre) const;
private:
    T val;
    static unsigned  cntAff,
                     cntComp,
                     cntIt;
};

template <typename T>
bool OpCounter<T>::operator<(const OpCounter& autre) const{
    return this->val < autre.val;
}

template <typename T>
bool OpCounter<T>::operator>(const OpCounter& autre) const{
    return autre < *this;
}

template <typename T>
bool OpCounter<T>::operator<=(const OpCounter& autre) const{
   return this->val <= autre.val;
}

template <typename T>
bool OpCounter<T>::operator>=(const OpCounter& autre) const{
   return autre < *this;
}

template <typename T>
void OpCounter<T>::resetCnt() {
    cntAff  = 0;
    cntComp = 0;
    cntIt   = 0;
}


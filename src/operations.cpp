
class OpCounter{
public:
    OpCounter(int i) : i(i){};
    static void resetCnt();
    OpCounter& operator++();
    OpCounter  operator++(int);
    bool operator<(const OpCounter& autre) const;
    bool operator>(const OpCounter& autre) const;
private:
    int i;
    static unsigned cnt;
};


OpCounter &OpCounter::operator++() {
    this->cnt++;
    return *this;
}


OpCounter OpCounter::operator++(int) {
    OpCounter tmp = *this;
    ++(*this);
    return tmp;
}


bool OpCounter::operator<(const OpCounter& autre) const{
    return this->cnt < autre.cnt;
}


bool OpCounter::operator>(const OpCounter& autre) const{
    return autre < *this;
}


void OpCounter::resetCnt() {
    cnt   = 0;
}


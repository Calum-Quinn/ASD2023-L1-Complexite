#ifndef ASD2022_L1_COMPLEXITE_TEST_H
#define ASD2022_L1_COMPLEXITE_TEST_H

#include <algorithm>

template <class T>
bool estTrie(const T& begin, const T& end) {
    return std::is_sorted(begin, end);
}

#endif //ASD2022_L1_COMPLEXITE_TEST_H
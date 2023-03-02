#ifndef ASD2022_L1_COMPLEXITE_TEST_H
#define ASD2022_L1_COMPLEXITE_TEST_H

#include <algorithm>

template <typename T>
bool estTrie(const std::vector<T>& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

#endif //ASD2022_L1_COMPLEXITE_TEST_H
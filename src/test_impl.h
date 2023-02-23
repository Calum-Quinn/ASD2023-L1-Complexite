#ifndef ASD2022_L1_COMPLEXITE_TEST_IMPL_H
#define ASD2022_L1_COMPLEXITE_TEST_IMPL_H

#include <vector>

using namespace std;

template <typename T>
bool estTrie(const vector<T>& vec) {
    if (vec.size())
        for (size_t i = 1; i < vec.size(); ++i) {
            if (vec[i - 1] > vec[i])
                return false;
        }
    return true;
}

#endif //ASD2022_L1_COMPLEXITE_TEST_IMPL_H

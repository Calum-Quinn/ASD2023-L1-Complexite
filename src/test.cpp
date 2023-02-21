#include <vector>

using namespace std;

template <typename T>
bool estTrie(const vector<T>& vec) {
   if (vec.size())
      for (size_t i = 0; i < vec.size(); ++i) {
         if (vec[i] > vec[i + 1])
            return false;
      }
   return true;
}
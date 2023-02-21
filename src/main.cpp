#include <iostream>
#include <vector>
#include "test.cpp"

using namespace std;

class OpCounter{
public:


private:
   int i;
   static unsigned cnt;
};

unsigned cnt = 0;

int main() {

   vector<int> vec1 = {1,2,3,4,5};
   vector<double> vec2 = {1.,3.,2.,4.,5.};

   cout << boolalpha << estTrie(vec1) << endl;
   cout << boolalpha << estTrie(vec2) << endl;

   return 0;
}

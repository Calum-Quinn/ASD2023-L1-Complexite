#include <iostream>
#include <vector>
#include <random>
#include "test.cpp"
#include "temps.h"
#include "tris.h"

using namespace std;



unsigned cnt = 0;

int main() {

   vector<int> vec1 = {1,2,3,4,5};
   vector<double> vec2 = {1.,3.,2.,4.,5.};

   //cout << srand(36) << endl;
   srand(36);

   cout << rand() << endl;
   cout << rand() << endl;

   cout << boolalpha << estTrie(vec1) << endl;
   cout << boolalpha << estTrie(vec2) << endl;

   //mesure_temps(bubbleSort);

   return 0;
}

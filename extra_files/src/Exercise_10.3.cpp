#include<vector>
#include<numeric>
#include<iostream>
using namespace std;

int main()
{
   vector<int> veci = {1,2,3,4,5,5,6,1,3};
   int val = 3;
   int sum = accumulate(veci.cbegin(),veci.cend(),0);
   cout <<"sum is" << sum  << endl;
   return 0;
}

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
   vector<int> veci = {1,2,3,4,5,6};
   fill_n(veci.begin(), veci.size(), 0);
   for(auto v:veci) cout << v << endl;
   return 0;
}

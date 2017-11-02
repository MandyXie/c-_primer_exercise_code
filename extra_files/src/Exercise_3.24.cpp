#include<iostream>
#include<vector>
using namespace std;

int main()
{
   vector<int> vecint;
   for(int i; cin >> i; vecint.push_back(i));
   for(auto it = vecint.cbegin(); it + 1 != vecint.cend(); ++it)
   {
      cout << *it + *(it+1) << " ";
   }
   cout << endl;

   for(auto lft = vecint.cbegin(), rht = vecint.cend()-1; lft <= rht; ++lft, --rht)
   {
      cout << *lft + *rht << " ";
   }
   cout << endl;
   return 0;
}

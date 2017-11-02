#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
   vector<int> vec = {1,2,3,4,5,6,7,8,9};
   for(auto iter = prev(vec.cend()); true; --iter)
   {
      cout << *iter << endl;
      if(iter == vec.cbegin()) break;
   }
   return 0;
}

#include<iostream>
#include<iterator>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
   vector<int> vec = {1,2,3,4,5,6,7,8,9};
   list<int> ret_lst(8 - 3);
   copy(vec.cbegin() + 3, vec.cbegin() + 8, ret_lst.rbegin());
   for(auto l:ret_lst) cout << l << endl;
   return 0;
}

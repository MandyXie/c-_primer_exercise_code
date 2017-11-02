#include<iostream>
#include<list>
using namespace std;

void elimDups(list<int> &li)
{
   li.sort();
   li.unique();
}

int main()
{
   list<int> lst = {0,1,2,3,2,3,4,5,6};
   elimDups(lst);
   for(auto l:lst) cout << l << endl;
   return 0;
}

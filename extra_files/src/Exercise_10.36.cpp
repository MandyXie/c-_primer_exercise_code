#include<iostream>
#include<iterator>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
   list<int> li = {1,2,3,0,4,5,6,7,0,8,9};
   auto zero = find(li.crend(),li.crbegin(),0);
   cout << distance(zero, li.crend()) << endl; 
   return 0;
}

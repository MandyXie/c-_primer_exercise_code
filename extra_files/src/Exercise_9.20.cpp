#include<deque>
#include<list>
#include<iostream>
using namespace std;

int main()
{
   list<int> li{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   deque<int> dq1,dq2;
   for(auto l:li)
   {
      l%2 == 0? dq1.push_back(l) : dq2.push_back(l);
   }

   cout << "element in dq1 should be even:" << endl;
   for(auto dq:dq1)
      cout << dq << endl;
   
   cout << "element in dq2 should be odd:" << endl;
   for(auto dq:dq2)
      cout << dq << endl;
   return 0;
}

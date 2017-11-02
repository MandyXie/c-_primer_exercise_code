#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
   int ia[] = { 0, 1, 1, 2, 2, 3, 5, 8, 13, 21, 55, 89 };
   vector<int> vec(ia,end(ia));
   list<int> li(ia,end(ia));
   
   for(auto iter = li.begin(); iter != li.end();)
   {
      if(*iter%2) iter = li.erase(iter);
      else ++iter;
   }

   for(auto iter = vec.begin(); iter != vec.end();)
   {
      if(!(*iter%2)) iter = vec.erase(iter);
      else ++iter;
   }
   return 0;
}

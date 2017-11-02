#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
   vector<int> vec = {1,2,3,4,5,6,7,8,9};
   for(auto riter = vec.crbegin(); riter != vec.crend(); ++riter)
   {
      cout << *riter << endl;
   }
   return 0;
}

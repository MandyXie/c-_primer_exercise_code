#include<vector>
#include<iostream>
using namespace std;

using ptr = vector<int>*;
auto vecint() -> ptr
{
   return new vector<int>{ };
}

auto assignvalue(ptr vec) -> ptr
{
   int i;
   while(cin >> i)
      vec->push_back(i);
   return  vec;   
}

void print(ptr vec)
{
   for(auto i:*vec)
      cout << i << endl;
   delete vec;
}

int main()
{
   print(assignvalue(vecint()));
   return 0;
}

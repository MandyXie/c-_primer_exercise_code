#include<vector>
#include<iostream>
#include<memory>
using namespace std;

using ptr = shared_ptr<vector<int>>;
auto vecint() -> ptr
{
   return make_shared<vector<int>>();
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
}

int main()
{
   print(assignvalue(vecint()));
   return 0;
}

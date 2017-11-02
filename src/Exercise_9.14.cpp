#include<list>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
   list<const char* > l{"Moophy", "pezy", "Queeuqueg"};
   vector<string> v;
   v.assign(l.cbegin(), l.cend());
   for(auto ptr:v)
      cout << ptr << endl;
   return 0;
}

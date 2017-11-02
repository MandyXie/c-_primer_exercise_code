#include<map>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
   map<string,vector<string>> family;
   string name;
   for(string ln; cout << "last name:\n",cin >> ln && ln != "@q"; )
      for(string cn; cout << "children's name:\n", cin >> cn && cn != "@q";)
          family[ln].push_back(cn);
   for(auto &f:family)
   {
      for(auto &n:f.second)
         cout << n << " ";
      cout << " are in family " << f.first << endl;
   }
   return 0;
}

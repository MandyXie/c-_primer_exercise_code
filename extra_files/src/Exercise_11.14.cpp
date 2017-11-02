#include<map>
#include<vector>
#include<string>
#include<utility>
#include<iostream>
using namespace std;

int main()
{
   map<string,vector<pair<string,string>>> family;
   string name;
   string db;
   for(string ln; cout << "last name:\n",cin >> ln && ln != "@q"; )
      for(string cn; cout << "children's name and birthday:\n", cin >> cn >> db && cn != "@q";)
          family[ln].push_back({cn,db});
   for(auto &f:family)
   {
      for(auto &n:f.second)
         cout << n.first << " " << n.second << " ";
      cout << " are in family " << f.first << endl;
   }
   return 0;
}

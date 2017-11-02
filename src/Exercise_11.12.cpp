#include<utility>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
   pair<string, int> pairs;
   vector<pair<string, int>> vecp;
   while(cin >> pairs.first && cin >> pairs.second)
       vecp.push_back(pairs);
   for(auto v:vecp)
      cout << v.first << " " << v.second << endl;
   return 0;
}

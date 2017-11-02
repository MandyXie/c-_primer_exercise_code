#include<utility>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
   vector<pair<string, int>> vecp;
   string str;
   int i;
   while(cin >> str >> i)
       vecp.push_back(pair<string, int> (str,i));
      // vecp.push_back(make_pair<str,i>);
      // vecp.push_back({str,i});
      // vecp.emplace_back(stri,i);
   for(auto v:vecp)
      cout << v.first << " " << v.second << endl;
   return 0;
}

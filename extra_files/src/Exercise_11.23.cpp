#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

int main()
{
   string ln;
   string cn;
   multimap<string, string> families;
   while(cin >> ln >> cn)
       families.insert({ln,cn});
   return 0;
}

#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
   vector<char> vecchar = {'a','b','c'};
   string str(vecchar.begin(),vecchar.end());
   cout << str << endl;
   return 0;
}

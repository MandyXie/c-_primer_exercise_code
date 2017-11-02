#include<list>
#include<string>
#include<iostream>
using namespace std;

int main()
{
   string str;
   list<string> dq;
   while(cin >> str)
      dq.push_back(str);

   for(auto iter = dq.begin(); iter != dq.end(); ++iter)
      cout << *iter << endl;
   return 0;
}

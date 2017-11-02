#include<iostream>
#include<string>
using namespace std;

int main()
{
   string s("Hello World!!!");
   for(auto &c : s)
   {
      c = 'X';
   }
   cout << s << endl;
}

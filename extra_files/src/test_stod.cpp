#include<iostream>
#include<string>
using namespace std;

int main()
{
   string s = "pi = 3.143";
   auto d = stod(s.substr(s.find_first_of("+-.0123456789")));
   cout << d << endl;
   return 0;
}

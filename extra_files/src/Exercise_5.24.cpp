#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
   int i, j;
   cout << "input two intergers: " << endl;
   cin >> i >> j;
   if(j == 0) throw runtime_error("the divider is zero");
   cout << "i / j = " << i/j << endl;
   return 0;
}

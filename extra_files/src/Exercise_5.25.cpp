#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
   int i, j;
   char c;
   do
   {
      cout << "input two intergers: " << endl;
      cin >> i >> j;
      try
      {
         if(j == 0) throw runtime_error("the divider is zero");
         cout << "i / j = " << i/j << endl;
      }
      catch (runtime_error err)
      {
         cout << err.what() << endl;
         cout << "try again? Enter y or n: " << endl;
         cin >> c;
      }
   }while(cin && c == 'y');
   return 0;
}

#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
   Sales_item currItem, valItem;
   cin >> currItem;
   int cnt = 1;
   while(cin >> valItem)
   {
      if(currItem.isbn() == valItem.isbn())
      {
         ++cnt;
      }
      else
      {
         cout << currItem << " occurs " << cnt << " times " << std::endl;
         currItem = valItem;
         cnt = 1;
      }
   }
   cout << currItem << " occurs " << cnt << " times " << std::endl;
   return 0;
}

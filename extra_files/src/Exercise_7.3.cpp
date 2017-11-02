#include<iostream>
#include<string>
#include "Exercise_7.2.h"
using namespace std;

int main()
{
   Sales_data total;
   if(cin >> total.bookNo >> total.units_sold >> total.revenue)
   {
      Sales_data trans;
      while(cin >> trans.bookNo >> trans.units_sold >> total.revenue)
      {
         if(trans.isbn() == total.isbn())
         {
            total.combine(total);
         }
         else
         {
            cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
            total = trans;
         }
      }
      cout << total.bookNo << " " << total.units_sold << " " << total.reve
nue << endl;
   }
   else
   {
      cerr << "no data" << endl;
      return -1;
   }
   return 0;
}



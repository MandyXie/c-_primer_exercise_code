#include<iostream>
#include<string>
using namespace std;

int main()
{
   string str;
   string pre_str;
   string repeated_str;
   int count = 1;
   int pre_count = 1;
   while(cin >> str)
   {
      if(str == pre_str)
      {
         ++count;
      }
      else
      {
         if(pre_count < count)
         {
            pre_count = count;
            repeated_str = pre_str;
         }
         
         count = 1;
      }
      pre_str = str;
   }
   if(pre_count == 1)
   {
      cout << "no word was repeated" << endl;
   }
   else
   {
      cout << "the word " << repeated_str << " occurred " << pre_count << " times" << endl;
   }
   return 0;
}

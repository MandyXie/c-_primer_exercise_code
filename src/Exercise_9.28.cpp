#include<string>
#include<forward_list>
#include<iostream>
using namespace std;

int main()
{
   forward_list<string> flstr{"are", "you", "kidding"};
   string str1{"are"};
   string str2{"not"};
   
   auto prev = flstr.before_begin();
   auto curr = flstr.begin();
   for(curr; curr != flstr.end(); prev = curr++)
   {
      if(*curr == str1) {
          flstr.insert_after(curr,str2);
          for(auto fl:flstr) cout << fl << endl;
          return 0;
      }
   }
   flstr.insert_after(prev, str2);
   for(auto fl:flstr) cout << fl << endl;
   return 0;
}

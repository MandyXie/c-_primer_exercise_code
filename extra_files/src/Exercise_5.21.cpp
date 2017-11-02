#include<iostream>
#include<string>
using namespace std;

int main()
{
   string str;
   string pre_str;
   bool flag = false;
   while(cin >> str)
   {
      if(!isupper(str[0])) continue;
      if(str == pre_str)
      {
         flag = true;
         cout << str << " occurs twice in succession" << endl;
         break;
      }
      pre_str = str;
   }
   
   if(!flag) cout << "no word was repeated" << endl;
}

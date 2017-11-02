#include<iostream>
#include<string>
using namespace std;

int main()
{
   pair<string, int> max_duplicated;
   int count = 0;
   for(string str, pre_str; cin >> str; prestr = str)
   {
      if(str == ptr) ++count;
      else count = 0;
      if(count > max_duplicated.second) max_duplicated = {prestr, count};
   }
   if(max_duplicated.first.empty()) cout << "there is no duplicated string" << endl;
   else cout << cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << endl;
   
   return 0;
}

